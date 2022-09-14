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
 * @file Cell.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Cell.h"



/*TODO REFACTOR
 * Move fields and methods which do not belong in the colony class
 */

//TODO How do we track how many ants are in each cells?

Cell::Cell() {

}

double Cell::getFood() const {
    return food;
}

int Cell::getPosX() const {
    return posX;
}

int Cell::getPosY() const {
    return posY;
}

bool Cell::isPathable() const {
    return pathable;
}

bool Cell::isExplored() const {
    return explored;
}

double Cell::getPheromone() const {
    return pheromone;
}

double Cell::foodPickUp(double amount) {
    if (amount > this->food) {
        double buff = this->food;
        this->food = 0;
        return buff;
    } else {
        this->food -= amount;
        return amount;
    }
}

void Cell::foodDrop(double &amount) {
    this->food += amount;

}

void Cell::pheromoneDrop(double &amount) {
    if (double buff = pheromone + amount > 1000)
        this->pheromone = 1000;
    else
        this->pheromone += amount;
}

void Cell::pheromoneEvaporation() {
    this->pheromone *= 0.95;
}

void Cell::setAsObstacle() {
    this->pathable = false;
}

void Cell::setAsExplored() {
    this->explored = true;
}

Cell::Cell(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
}

int Cell::getCapacity() const {
    return capacity;
}

int Cell::getAntsNb() const {
    return antsNb;
}

void Cell::antRemove() {
    //TODO
}

void Cell::antAdd() {
    //TODO
}

void Cell::displayCell() {

}

void Cell::setFood(double food) {
    Cell::food = food;
}

void Cell::setPathable(bool pathable) {
    Cell::pathable = pathable;
}

void Cell::setExplored(bool explored) {
    Cell::explored = explored;
}

void Cell::setPheromone(double pheromone) {
    Cell::pheromone = pheromone;
}

void Cell::setCapacity(int capacity) {
    Cell::capacity = capacity;
}

void Cell::setAntsNb(int antsNb) {
    Cell::antsNb = antsNb;
}




