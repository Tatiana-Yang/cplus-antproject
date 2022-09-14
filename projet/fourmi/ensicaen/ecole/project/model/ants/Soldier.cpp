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
 * @file Soldier.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include "../../include/Soldier.h"

void Soldier::oneDaySpent(Cell *colony) {
    Soldier::setEat(false);
    Cell *cell = colony;// l'emplacement de la colonie
    Soldier::feed(cell);
    if(Soldier::hasEat() and Soldier::getLifeExpectancy() != 0){
        int life = Soldier::getLifeExpectancy();
        Soldier::setLifeExpectancy(life - 1);
        Soldier::setBackHome(Soldier::getBackHome()-1);
    }
    else{
        Soldier::setDie(true);
    }
}


void Soldier::feed(Cell *cell) {
    if (cell->getFood() - Soldier::getFoodNeed() >= 0 ){
        Soldier::setEat(true);
        cell->setFood(cell->getFood() - Soldier::getFoodNeed());
    }
};

Cell* Soldier::choiceMove() {
    vector<Cell*> vNeighborhood = Plebian::getNeighborhood8();

    int indice = (rand() % 7) + 1;
    if(Soldier::getBackHome() == 0){
        indice = Soldier::moveToBackHome();
    }
    else{
        do{
            cout << "La boucle est infini ? "<< endl;
            //Choose ramdomly an index beetween 0 and 7
            indice = (rand() % 7) + 1;
        }while(!vNeighborhood[indice]->isPathable() && vNeighborhood[indice]->getAntsNb() > vNeighborhood[indice]->getCapacity() && !vNeighborhood[indice]->isExplored());
    }
    return vNeighborhood[indice];
}
void Soldier::actionMove() {
    Cell* cell = Soldier::choiceMove();
    stack<Cell*> path = Soldier::getPath();
    path.push(Soldier::getLocation());
    Soldier::setPath(path);
    Soldier::setLocation(cell);

    if(Soldier::getLocation() == Soldier::getNeighborhood8()[Utils::calculIndice(0,0)]){
        Soldier::setBackHome(DAYBACKHOME);
    }
}

int Soldier::getBackHome() const {
    return backHome;
}

void Soldier::setBackHome(int backHome) {
    Soldier::backHome = backHome;
}

// TODO djikstra, search path to go back to the colony
int Soldier::moveToBackHome() {
    int indice = 0;

    return indice;

}
