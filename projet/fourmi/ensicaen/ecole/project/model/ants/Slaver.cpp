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
 * @file Slaver.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../include/Slaver.h"

void Slaver::feed(Cell *cell) {
    if (cell->getFood() - Slaver::getFoodNeed() >= 0){
        Slaver::setEat(true);
        cell->setFood(cell->getFood() - Slaver::getFoodNeed());
        Slaver::setFasting(10);
    }
};

void Slaver::oneDaySpent(Cell *colony) {
    Slaver::setEat(false);
    Cell *cell = colony;// l'emplacement de la colonie
    Slaver::feed(cell);
    if((Slaver::hasEat() and Slaver::getLifeExpectancy() != 0) or Slaver::getFasting() > 0 ){
        int life = Slaver::getLifeExpectancy();
        Slaver::setLifeExpectancy(life - 1);
        if(!Slaver::hasEat()){
            Slaver::setFasting(Slaver::getFasting() - 1);
        }
    }
    else{
        Slaver::setDie(true);
    }
}

int Slaver::getFasting() const {
    return fasting;
}

void Slaver::setFasting(int fasting) {
    Slaver::fasting = fasting;
}

bool Slaver::isCatchAnt() const {
    return catchAnt;
}

void Slaver::setCatchAnt(bool catchAnt) {
    Slaver::catchAnt = catchAnt;
}



