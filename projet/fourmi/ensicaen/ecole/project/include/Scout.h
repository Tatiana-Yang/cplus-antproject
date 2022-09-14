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
 * @file Scout.h
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef FOURMI_SCOUT_H
#define FOURMI_SCOUT_H

#include <stack>
#include <iostream>
#include "Worker.h"

//#include "../../../../../../../../../../../../../../Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/stack"

using namespace std;

class Scout : public Worker {
private:

public:

// implement abstract method

    void comeOfAge() override;

    Cell* choiceMove() override;

    void actionMove() override;

    void feed(Cell *cell) override;
    void oneDaySpent(Cell *cell) override;

    Scout(){
        antBelong = SCOUT;
        canMove = true;
    }

};


#endif //FOURMI_SCOUT_H
