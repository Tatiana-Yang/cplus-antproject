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
 * @file Terrain.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../include/Terrain.h"

Terrain::Terrain(int posX, int posY) : Cell(posX, posY) {
    this->antsNb=0;
    this->capacity=12;
}

void Terrain::displayCell() {
    Cell::displayCell();

    if (isPathable()) {
        if (isExplored()) {
            cout << "X";
        } else {
            if (getFood() != 0)
                cout << "!";
            else
                cout << "?";
        }
    } else {
        cout << "O";
    }
}
