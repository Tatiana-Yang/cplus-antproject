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
 * @file Queen.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../include/Queen.h"

// getters and setter
bool Queen::isLarvae() const {
    return larvae;
}

void Queen::setLarvae(bool larvae) {
    Queen::larvae = larvae;
}

double Queen::getFoodNeed() const {
    return foodNeed;
}

void Queen::setFoodNeed(double foodNeed) {
    Queen::foodNeed = foodNeed;
}

bool Queen::hasEat() const {
    return eat;
}

void Queen::setEat(bool eat) {
    Queen::eat = eat;
}

int Queen::getLifeExpectancy() const {
    return lifeExpectancy;
}

void Queen::setLifeExpectancy(int lifeExpectancy) {
    Queen::lifeExpectancy = lifeExpectancy;
}

void Queen::feed(Cell *cell) {
    if (cell->getFood() - Queen::getFoodNeed() >= 0){
        Queen::setEat(true);
        cell->setFood(cell->getFood() - Queen::getFoodNeed());
    }
};

void Queen::oneDaySpent(Cell *colony) {
    Queen::setEat(false); // Tous les jours, on remet le fait d'avoir mangé à faux
    Cell *cell = colony; // l'emplacement de la colonie
    Queen::feed(cell);
    if(Queen::hasEat() and Queen::getLifeExpectancy() != 0){
        int life = Queen::getLifeExpectancy();
        Queen::setLifeExpectancy(life - 1);
    }
    else{
        Queen::setDie(true);
        std::cout << "The queen die !"<<endl;
    }
}

vector<Plebian> Queen::reproduce() {
    vector<Plebian> vlarvae;
    int i = 0;
    if(Queen::getLifeExpectancy() == 3650){
        Scout ant = Scout();
        ant.setLocation(Queen::getLocation());
        vlarvae.push_back(ant);

        std::cout << "First It's a Scout !" << endl;

        i = 1;

    }
    for (i; i < 2; i++) {
        int randomNb = (rand() % 100) + 1;
        if (randomNb <= 80) {
            Worker ant = Worker();
            ant.setLocation(Queen::getLocation());
            vlarvae.push_back(ant);
            std::cout << "It's a Worker !" << endl;
        } else if (randomNb > 80 && randomNb <= 95) {
            Soldier ant = Soldier();
            ant.setLocation(Queen::getLocation());
            vlarvae.push_back(ant);
            std::cout << "It's a Soldier !" << endl;
        } else {
            Scout ant = Scout();
            ant.setLocation(Queen::getLocation());
            vlarvae.push_back(ant);
            std::cout << "It's a Scout !" << endl;
        }
    }
    return vlarvae;
}

bool Queen::isAttacked() const {
    return attacked;
}

void Queen::setAttacked(bool attacked) {
    Queen::attacked = attacked;
}

void Queen::actionMove() {
    // The queen don't pheromoneDeposit
}

Cell *Queen::choiceMove() {
    return nullptr;
}