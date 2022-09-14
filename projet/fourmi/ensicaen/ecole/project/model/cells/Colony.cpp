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
 * @file Colony.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../include/Colony.h"


Colony::Colony(int posX, int posY) : Cell(posX, posY) {
    this->antsNb=0;
    this->capacity=100;
    this->food = 2; // Car nous commençons notre simulation avec une capacité de nourriture à 2
}

void Colony::displayCell() {
    Cell::displayCell();
    std::cout<<"T";
}
