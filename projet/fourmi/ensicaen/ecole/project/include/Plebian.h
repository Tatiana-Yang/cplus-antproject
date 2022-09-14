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
 * @file Plebian.h
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef FOURMI_PLEBIAN_H
#define FOURMI_PLEBIAN_H

#include <stack>
#include <vector>
#include "Ant.h"
using namespace std;

class Plebian : public Ant {
public:
    double getFoodNeed() const;

    void setFoodNeed(double foodNeed);

    bool hasEat() const;

    void setEat(bool eat);

    int getPheromones() const;

    void setPheromones(int pheromones);

    const stack<Cell*> &getPath() const;

    void setPath(const stack<Cell*> &path);

    int getLifeExpectancy() const override;

    void setLifeExpectancy(int lifeExpectancy) override;

    void oneDaySpent(Cell *cell) override;
    void feed(Cell *cell) override;

    Cell *choiceMove() override;
    void actionMove() override;

    Plebian(){
        antBelong = PLEBIAN;
        canMove = true;
    }

private:
    double foodNeed = 0.001;
    bool eat = false;
    int pheromones = 500;
    stack<Cell*> path;
    int lifeExpectancy = 365;
    int AntBelong = 1;
};


#endif //FOURMI_PLEBIAN_H
