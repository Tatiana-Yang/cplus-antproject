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
 * @file Cell.h
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef PROJET_FOURMIS_CELL_H
#define PROJET_FOURMIS_CELL_H
#include <vector>
#include <iostream>



/*TODO REFACTOR
 * déplacer les champ de données et méthodes qui n'ont pas de sens à être utilisé dans les cellules dérivées Colony
 * */

class Cell {
protected:

    int posX, posY;
    bool pathable=true, explored = false;
    double food =0, pheromone =0;
public:
    void setFood(double food);

protected:
    int capacity;

    int antsNb;
public:

    int getCapacity() const;

    void setPathable(bool pathable);

    int getAntsNb() const;


    double foodPickUp(double amount);

    void foodDrop(double &amount);

    void pheromoneDrop(double &amount);

    void pheromoneEvaporation();

    void setAsObstacle();

    void setAsExplored();

    void antAdd();

    void antRemove();


    Cell();

    Cell(int posX, int posY);

    int getPosX() const;

    int getPosY() const;

    bool isPathable() const;

    bool isExplored() const;

    double getPheromone() const;

    void setExplored(bool explored);

    void setPheromone(double pheromone);

    void setCapacity(int capacity);

    void setAntsNb(int antsNb);

    double getFood() const;

    virtual void displayCell();

};


#endif //PROJET_FOURMIS_CELL_H
