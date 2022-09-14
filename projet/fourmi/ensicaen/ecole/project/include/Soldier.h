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
 * @file Soldier.h
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef FOURMI_SOLDIER_H
#define FOURMI_SOLDIER_H

#include <stack>
#include "Cell.h"
#include "Plebian.h"
#include "Utils.h"

#define DAYBACKHOME 100

using namespace std;

class Soldier : public Plebian {
private:
    int backHome = 100;

public:

    int getBackHome() const;

    void setBackHome(int backHome);

    int moveToBackHome();


    void feed(Cell *cell) override;
    void oneDaySpent(Cell *cell) override;

    void actionMove() override;
    Cell* choiceMove() override;

    Soldier(){
        antBelong = SOLDIER;
    }


};


#endif //FOURMI_SOLDIER_H
