/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students. No portion of this
 * document may be reproduced, copied or revised without written
 * permission of the authors.
 */

/**
 * @file Worker.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../include/Worker.h"

// getters and setter

int Worker::getBackColony() const {
    return backColony;
}

void Worker::setBackColony(int backColony) {
    Worker::backColony = backColony;
}

bool Worker::isMajor() const {
    return major;
}

void Worker::setMajor(bool major) {
    Worker::major = major;
}

bool Worker::isFindFood() const {
    return findFood;
}

void Worker::setFindFood(bool findFood) {
    Worker::findFood = findFood;
}

// functions
void Worker::comeOfAge() {
    if (Worker::getLifeExpectancy() == 350){
        Worker::setMajor(true);
    }
}


void Worker::feed(Cell *cell) {
    if (cell->getFood() - Worker::getFoodNeed() >= 0){
        Worker::setEat(true);
        cell->setFood(cell->getFood() - Worker::getFoodNeed());
        cout<<cell->getFood()<<endl;
    }
};

void Worker::oneDaySpent(Cell *colony) {
    Worker::setEat(false);
    Cell *cell = colony; // l'emplacement de la colonie
    Worker::feed(cell);
    if(Worker::hasEat() and Worker::getLifeExpectancy() != 0){
        int life = Worker::getLifeExpectancy();
        Worker::setLifeExpectancy(life - 1);
        Worker::comeOfAge();
    }
    else{
        Worker::setDie(true);
    }

}

void Worker::pheromoneDeposit() {
    Cell* cell = Worker::getLocation();
    if(Worker::isFindFood()){
        if(Worker::getPheromones() != 0){
            cell->setPheromone(cell->getPheromone()+1);
            Worker::setPheromones(Worker::getPheromones()-1);

        }
    }


}

Cell* Worker::choiceMove() {
    vector<Cell*> vNeighborhood = Worker::getNeighborhood8();

    Cell *mostPheromone = Worker::getLocation();
    for(int i = 0; i < vNeighborhood.size(); i++){
        if(vNeighborhood[i]->isPathable() && vNeighborhood[i]->getAntsNb() < vNeighborhood[i]->getCapacity() && vNeighborhood[i]->isExplored()){
            if(vNeighborhood[i]->getPheromone() >= mostPheromone->getPheromone()){
                mostPheromone = vNeighborhood[i];
            }
        }
    }
    if(mostPheromone == Worker::getLocation()){
        for(int i = 0; i < vNeighborhood.size(); i++){
            if(vNeighborhood[i]->isPathable() && vNeighborhood[i]->getAntsNb() < vNeighborhood[i]->getCapacity() && vNeighborhood[i]->isExplored()){
                mostPheromone = vNeighborhood[i];
            }
        }
    }
    return mostPheromone;
}

void Worker::actionMove() {
    Cell *antPosition = Worker::getLocation();
    if(antPosition->getPosX() == 0 && antPosition->getPosY() == 0){ // dans le cas ou notre fourmi est dans la colonie, elle dépos ela nourriture qu'elle a
        if(Worker::isFindFood()){
            antPosition->setFood(antPosition->getFood() + 1);
            Worker::setFindFood(false);
        }
        else {
            Cell *cell = Worker::choiceMove();
            stack<Cell*> path = Worker::getPath();
            path.push(Worker::getLocation());
            Worker::setPath(path);
            Worker::setLocation(cell);
        }
    }
    else if(Worker::isFindFood()){
        stack<Cell*> path = Worker::getPath();
        Cell *cell = path.top();
        Worker::pheromoneDeposit();
        Worker::setLocation(cell);
    }
    else {
        Worker::pheromoneDeposit();
        Cell *cell = Worker::choiceMove();
        stack<Cell*> path = Worker::getPath();
        path.push(Worker::getLocation());
        Worker::setPath(path);
        Worker::setLocation(cell);
        if(cell->getFood() != 0){
            cell->setFood(cell->getFood() - 1);
            Worker::setFindFood(true);
        }
    }

}