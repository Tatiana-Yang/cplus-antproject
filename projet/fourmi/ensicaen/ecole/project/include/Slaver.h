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
 * @file Slaver.h
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef FOURMI_SLAVER_H
#define FOURMI_SLAVER_H

#include "Plebian.h"

class Slaver : public Plebian {

private:
    int fasting = 10;
    bool catchAnt = false;

public:
    int getFasting() const;

    void setFasting(int fasting);

    bool isCatchAnt() const;

    void setCatchAnt(bool catchAnt);

    void feed(Cell *cell) override;
    void oneDaySpent(Cell *cell) override;

    Slaver(){
        antBelong = SLAVER;
        canMove = true;
    }


};


#endif //FOURMI_SLAVER_H
