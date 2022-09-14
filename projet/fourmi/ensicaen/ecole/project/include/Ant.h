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
 * @file Ant.h
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJET_FOURMIS_ANT_H
#define PROJET_FOURMIS_ANT_H

#include <iostream>
#include "Cell.h"

using namespace std;

enum{
    QUEEN, PLEBIAN, WORKER, SOLDIER, SCOUT, SLAVER
};

class Ant{
protected :
    int lifeExpectancy = 0;
    bool die = false;
    bool canMove;
    bool larva = true;

    vector<Cell*> neighborhood_8;

    Cell* location; //initialize to the colony location
    char antBelong;

public:
    bool isLarva() const;

    void setLarva(bool larva);

    char getAntBelong() const;

    void setAntBelong(char antBelong);

    bool isDie() const;

    void setDie(bool die);

    bool isCanMove() const;

    Cell* getLocation() const;

    void setLocation(Cell* location);

    const vector<Cell *> &getNeighborhood8() const;

    void setNeighborhood8(const vector<Cell *> &neighborhood8);
    virtual int getLifeExpectancy() const;

    virtual void setLifeExpectancy(int lifeExpectancy);

    virtual void oneDaySpent(Cell *cell);
    virtual void feed(Cell *cell);

    virtual Cell *choiceMove() = 0;
    virtual void actionMove() = 0;
};


#endif //PROJET_FOURMIS_ANT_H
