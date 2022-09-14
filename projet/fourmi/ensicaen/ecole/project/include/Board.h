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
 * @file Board.h
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJET_FOURMIS_BOARD_H
#define PROJET_FOURMIS_BOARD_H

#include "Colony.h"
#include "Terrain.h"
#include "Ant.h"
#include "Utils.h"
#include <array>
#include <iostream>
#include <ctime>
#include <tuple>
#include <random>


#define X 211
#define Y 201

using namespace std;

class Board{

public:
    int getNbAntColony() const;

    void setNbAntColony(int nbAntColony);

    vector<Cell*> cells;
    vector<Ant*> ants;
    int nbAntColony = 0;

    double foodSmall = 0, foodBig = 2;


    void initializeBoard();

    void initializeObstacle(vector<int> &obstacleStats);

    void initializeFoodSmall(int nbCell);

    void initializeFoodBig();

    void initializeColony();

    void pheromoneDiffusion(Cell cell);

    int getCellByPos(int posX, int posY);

    bool nextObstacle(int &x, int &y, int &direction, std::mt19937 &mt);

    void getXYbyDirection(int &posX, int &posY, int direction);

    void displayPartial();

    bool neighbourPathable(int posX, int posY, int direction);

    Board();

    //MOVEMENT
    vector<Cell*> neighborhood_8(Cell *antLocation);
    void antMovement();

    void display();

    void addAnts(Ant *ant);
};

#endif //PROJET_FOURMIS_BOARD_H
