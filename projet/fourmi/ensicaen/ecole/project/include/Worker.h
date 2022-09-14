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
 * @file Worker.h
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef FOURMI_WORKER_H
#define FOURMI_WORKER_H

#include <iostream>
#include <stack>
#include <vector>
#include "Plebian.h"

using namespace std;

class Worker : public Plebian {
private:
    int backColony = 100;
    bool major = false;
    bool findFood = false;

public:
    virtual void comeOfAge();
//GETTER SETTER

    int getBackColony() const;

    void setBackColony(int backColony);

    bool isMajor() const;

    bool isFindFood() const;

    void setFindFood(bool findFood);

    void setMajor(bool major);

    void pheromoneDeposit();

// REDEFINITION DE METHODE ABSTRAITE

    Cell* choiceMove() override;

    void actionMove() override;

    void feed(Cell *cell) override;

    void oneDaySpent(Cell *colony) override;

    Worker(){
        antBelong = WORKER;
        canMove = true;
    }
};


#endif //FOURMI_WORKER_H
