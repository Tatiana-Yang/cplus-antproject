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
 * @file Scout.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../include/Scout.h"


void Scout::comeOfAge() {
    if (getLifeExpectancy() == 363){
        setMajor(true);
    }
}

Cell* Scout::choiceMove() {
    vector<Cell*> vNeighborhood = Plebian::getNeighborhood8();
    int randomChoice = (rand() % 7) + 1;
    do{
        //Choose ramdomly an index beetween 0 and 7
        int randomChoice = (rand() % 7) + 1;
    }while(!vNeighborhood[randomChoice]->isPathable() || vNeighborhood[randomChoice]->getAntsNb() > vNeighborhood[randomChoice]->getCapacity());

    return vNeighborhood[randomChoice];
}

void Scout::actionMove() {
    if(Scout::isFindFood()){
        stack<Cell*> path = Scout::getPath();
        Cell *cell = path.top();
        Scout::setLocation(cell);
    }
    else {
        Scout::pheromoneDeposit();
        Cell *cell = Scout::choiceMove();
        stack<Cell*> path = Scout::getPath();
        path.push(Scout::getLocation());
        Scout::setPath(path);
        Scout::setLocation(cell);
        if(!cell->isExplored()){
            cell->setExplored(true);
        }
    }
}

void Scout::feed(Cell *cell) {
    if (cell->getFood() - Scout::getFoodNeed() >= 0){
        Scout::setEat(true);
        cell->setFood(cell->getFood() - Scout::getFoodNeed());
    }
};

void Scout::oneDaySpent(Cell *colony) {
    Scout::setEat(false);
    Cell *cell = colony; // l'emplacement de la colonie
    Scout::feed(cell);
    if(Scout::hasEat() and Scout::getLifeExpectancy() != 0){
        int life = Scout::getLifeExpectancy();
        Scout::setLifeExpectancy(life - 1);
        Scout::comeOfAge();
    }
    else{
        Scout::setDie(true);
    }

}