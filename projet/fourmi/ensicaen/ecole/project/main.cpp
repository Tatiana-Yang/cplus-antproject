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
 * @file main.cpp
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
#include <ctime>
#include <cstdlib>
#include "./include/Board.h"
#include "include/Soldier.h"
#include "include/Scout.h"
#include "include/Worker.h"
#include "include/Queen.h"
#include "include/Colony.h"
#include "include/Slaver.h"
#include "include/Utils.h"

int main() {

    Board board;
    board.displayPartial();


    return 0;
}
