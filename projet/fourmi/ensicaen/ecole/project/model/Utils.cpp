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
 * @file Utils.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Utils.h"
int Utils::calculIndice(int x, int y){
    int response = 0;

    if(x >= 0){
        response += (X-1)/2 + x; // car initialisation des coordonnées en ayant comme centre les coordonnées (0,0)
    }
    else{
        int mod = x % ((X-1)/2);
        if(mod < 0){
            mod += (X-1)/2;
        }
        response += mod;
    }
    response *= Y;

    if(y >=0){
        response += (Y-1)/2 + y;
    }
    else{
        int mod = y % ((Y-1)/2);
        if(mod < 0){
            mod += (Y-1)/2;
        }
        response += mod;
    }
    return response;
}