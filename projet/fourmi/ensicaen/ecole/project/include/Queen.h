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
 * @file Queen.h
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef FOURMI_QUEEN_H
#define FOURMI_QUEEN_H

#include "Ant.h"
#include "Cell.h"
#include "Plebian.h"
#include "Worker.h"
#include "Soldier.h"
#include "Scout.h"

class Queen : public Ant{
private:
    bool larvae = true;
    double foodNeed = 0.01;
    bool eat = false;
    int lifeExpectancy = 3650;
    bool attacked = false;

public:
    bool isAttacked() const;

    void setAttacked(bool attacked);

    bool isLarvae() const;

    void setLarvae(bool larvae);

    double getFoodNeed() const;

    void setFoodNeed(double foodNeed);

    bool hasEat() const;

    void setEat(bool eat);

    vector<Plebian> reproduce();

    int getLifeExpectancy() const override;

    void setLifeExpectancy(int lifeExpectancy) override;


    void oneDaySpent(Cell *cell) override;

    Cell* choiceMove() override;

    void actionMove() override;
    void feed(Cell *cell) override;

    Queen(){
        antBelong = QUEEN;
        canMove = false;
    }

};

#endif //FOURMI_QUEEN_H
