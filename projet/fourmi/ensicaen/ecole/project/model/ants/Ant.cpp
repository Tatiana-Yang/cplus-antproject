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
 * @file Ant.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../include/Ant.h"

bool Ant::isDie() const {
    return die;
}

void Ant::setDie(bool die) {
    Ant::die = die;
}

bool Ant::isCanMove() const {
    return canMove;
}

bool Ant::isLarva() const {
    return larva;
}

void Ant::setLarva(bool larva) {
    Ant::larva = larva;
}

Cell* Ant::getLocation() const {
    return location;
}

void Ant::setLocation(Cell* location) {
    Ant::location = location;
}

int Ant::getLifeExpectancy() const {
    return lifeExpectancy;
}

void Ant::setLifeExpectancy(int lifeExpectancy) {
    Ant::lifeExpectancy = lifeExpectancy;
}

void Ant::oneDaySpent(Cell *cell) {
    // TODO
}

void Ant::feed(Cell *cell) {
    //TODO
}

const vector<Cell *> &Ant::getNeighborhood8() const {
    return neighborhood_8;
}

void Ant::setNeighborhood8(const vector<Cell *> &neighborhood8) {
    neighborhood_8 = neighborhood8;
}

char Ant::getAntBelong() const {
    return antBelong;
}

void Ant::setAntBelong(char antBelong) {
    Ant::antBelong = antBelong;
}
