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
 * @file Plebian.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../include/Plebian.h"

int Plebian::getLifeExpectancy() const {
    return lifeExpectancy;
}

void Plebian::setLifeExpectancy(int lifeExpectancy) {
    Plebian::lifeExpectancy = lifeExpectancy;
}

double Plebian::getFoodNeed() const {
    return foodNeed;
}

void Plebian::setFoodNeed(double foodNeed) {
    Plebian::foodNeed = foodNeed;
}

bool Plebian::hasEat() const {
    return eat;
}

void Plebian::setEat(bool eat) {
    Plebian::eat = eat;
}

int Plebian::getPheromones() const {
    return pheromones;
}

void Plebian::setPheromones(int pheromones) {
    Plebian::pheromones = pheromones;
}

const stack<Cell*> &Plebian::getPath() const {
    return path;
}

void Plebian::setPath(const stack<Cell *> &path) {
    Plebian::path = path;
}

void Plebian::oneDaySpent(Cell *colony) {
    //TODO
}

void Plebian::feed(Cell* cell) {
    //TODO
}

Cell* Plebian::choiceMove() {
    vector<Cell*> vNeighborhood = Plebian::getNeighborhood8();
    cout<<"JE SUIS FORCEMENT PASSER ICI"<<endl;
    Cell* mostPheromone = vNeighborhood[0];
    for(int i = 0; i < vNeighborhood.size(); i++){
        if(vNeighborhood[i]->isPathable() && vNeighborhood[i]->getAntsNb() < vNeighborhood[i]->getCapacity()){
            if(vNeighborhood[i]->getPheromone() > mostPheromone->getPheromone()){
                mostPheromone = vNeighborhood[i];
            }
        }
    }
    return mostPheromone;
}

void Plebian::actionMove() {
    cout<<"JE SUIS FORCEMENT PASSER ICI"<<endl;
    Cell* cell = Plebian::choiceMove();
    stack<Cell*> path = Plebian::getPath();
    path.push(Plebian::getLocation());
    Plebian::setPath(path);
    Plebian::setLocation(cell);
}

