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
 * @file Board.cpp
 * @author David SIMON (david.simon@ecole.ensicaen.fr)
 * @author Tatiana YANG (tatiana.yang@ecole.ensicaen.fr)
 * @brief This file permit to display the menu and after manage and play with some maze
 * @version 1.0
 * @date 2021-12-15
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Board.h"

Board::Board() {
    int nbCell= X*Y;
    initializeBoard();
    initializeColony();
    //initializeFood(nbCell);
    //initializeObstacle(nbCell);


}
void Board::initializeColony(){
    int indice = Utils::calculIndice(0,0);
    this->cells[indice] = new Colony(0,0);
}

void Board::initializeBoard() {
    int nbCell = X * Y;
    int nbObstacle = nbCell * 3 / 100;

    int obstacle1 = nbObstacle * 50 / 100;//nombre d'obstacle de taille 1
    int obstacle2 = (nbObstacle * 30 / 100) / 2;//nombre d'obstacle de taille 2
    int obstacle3 = (nbObstacle * 10 / 100) / 3;//nombre d'obstacle de taille 3
    int obstacle4 = (nbObstacle * 5 / 100) / 4;//nombre d'obstacle de taille 4
    int obstacle5 = (nbObstacle * 4 / 100) / 5;//nombre d'obstacle de taille 5
    int obstacle6 = (nbObstacle / 100) / 6;//nombre d'obstacle de taille 6
    //cout<<"nbObstacle:"<<nbObstacle<<"| obstacles Descending:"<<obstacle1<<" "<<obstacle2<<" "<<obstacle3<<" "<<obstacle4<<" "<<obstacle5<<" "<<obstacle6<<" "<<endl;

    vector<int> obstacleStats;

    obstacleStats.push_back(obstacle1);
    obstacleStats.push_back(obstacle2);
    obstacleStats.push_back(obstacle3);
    obstacleStats.push_back(obstacle4);
    obstacleStats.push_back(obstacle5);
    obstacleStats.push_back(obstacle6);

    //this->cells.push_back(new Colony(0, 0));

    for (int i=-((X-1)/2);i<=(X-1)*0.5;i++)
        for(int j=-((Y-1)/2); j<=(Y-1)*0.5;j++)
            this->cells.push_back(new Terrain(i,j));

    cout << "nb de cell: " << nbCell << endl;
    cout << "nb obstacles:  " << nbObstacle << endl;

    for (int el: obstacleStats)
        cout << "obstacleStats: " << el << endl;

    initializeFoodBig();
    initializeObstacle(obstacleStats);
    initializeFoodSmall(nbCell);

    //cout << "nb de cell: " << nbCell << endl;
    //cout << "nb obstacles:  " << nbObstacle << endl;

    for (int el: obstacleStats)
        cout << "obstacleStats: " << el << endl;
}

void Board::initializeObstacle(vector<int> &stats) {
    //use a/multiple static seed(s) ?
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution<int> randX(-X / 2, X / 2);
    std::uniform_int_distribution<int> randY(-Y / 2, Y / 2);
    std::uniform_int_distribution<int> randDirection(0, 3);

    vector<tuple<int, int>> positions;
    int posX = 0, posY = 0;

    while (!stats.empty()) {
        //cout << "stats etat:" << stats.back() << endl;
        //position from which to start trying to create an obstacle
        posX = randX(mt);
        posY = randY(mt);

        //if position is not that of the colony we can proceed
        if (posX != 0 && posY != 0 && cells.at(getCellByPos(posX, posY))->isPathable()) {
            bool ret = true;
            int direction = 0;

            while (positions.size() < stats.size() && ret) {
                direction = randDirection(mt);
                positions.emplace_back(make_tuple(posX, posY));
                ret = nextObstacle(posX, posY, direction, mt);

            }
            //if ret is false, then pop_back until positions is empty, else start making these cells unpathable
            if (!ret) {
                while (!positions.empty())
                    positions.pop_back();
                stats.back()++;
            } else
                while (!positions.empty()) {
                    cells.at(getCellByPos(get<0>(positions[positions.size() - 1]),
                                          get<1>(positions[positions.size() - 1])))->setAsObstacle();

                    positions.pop_back();
                }
        }
        stats.back()--;
        if (stats.back() == 0)
            stats.pop_back();

    }

}

//on regarde stats pour savoir combien d'obstacle il reste à créer
//à chaque création d'obstacle on décrémente la dernière case de stats
//quand la dernière case est à zéro popback
//si la dernière case est aussi la première case then break

//initialize obstacle
//générer aléatoirement une position (X,Y)
//trouver la position de la cellule dans le vecteur
//cellule à position trouvée est déjà obstacle? false:true
//choisir une direction
//cellule dans direction est déjà obstacle ? false:true
//méthode qui trouve la prochaine cell pouvant être obstacle





void Board::initializeFoodSmall(int nbCell) {
    this->foodSmall = ceil(nbCell * 2 / 1000);
    std::random_device rd;
    std::mt19937 mt(rd());
    int randPosX = 0, randPosY = 0;
    int limitX = X - 2, limitY = Y - 2;
    double smallFoodDrop = 10;

    std::uniform_int_distribution<int> randX(-limitX / 2, limitX / 2);
    std::uniform_int_distribution<int> randY(-limitY / 2, limitY / 2);


    double foodCount = this->foodSmall;

    while (foodCount != 0) {
        randPosX = randX(mt);
        randPosY = randY(mt);
        int neighbourCont = 0;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= +1; j++) {
                if (i != 0 || j != 0) {
                    if (cells.at(getCellByPos(randPosX + i, randPosY + j))->getFood() == 0)
                        neighbourCont++;
                }
            }
        }
        if (neighbourCont == 8) {
            cells.at(getCellByPos(randPosX, randPosY))->foodDrop(smallFoodDrop);
            foodCount--;
        }

    }


    //pour grande réserves choisir une cellule et placé sur 4 des voisines une partie de la nourriture
    cout << "nb foodsmall:" << this->foodSmall << endl;

}

void Board::pheromoneDiffusion(Cell cell) {
    int posX = cell.getPosX(), posY = cell.getPosY();
    double pheromone = cell.getPheromone() * 0.02;
    cell.pheromoneEvaporation();

    for (int i = posX - 1; i <= (posX + 1); i++) {
        for (int j = posY - 1; j <= (posY + 1); j++) {
            if ((i != posX || j != posY) && cells.at(getCellByPos(i, j))->isPathable()) {
                cells.at(getCellByPos(i, j))->pheromoneDrop(pheromone);
            }
        }
    }
}

int Board::getCellByPos(int posX, int posY) {
    int i = 0;
    for (Cell *cell: this->cells) {
        if (cell->getPosX() == posX && cell->getPosY() == posY) {
            return i;
        } else
            i++;
    }
    return -1;
}

void Board::getXYbyDirection(int &posX, int &posY, int direction) {

    switch (direction) {
        case 0:
            posY += 1;
            break;
        case 1:
            posX += 1;
            break;
        case 2:
            posY -= 1;
            break;
        default:
            posX -= 1;
            break;
    }

}

bool Board::nextObstacle(int &posX, int &posY, int &direction, mt19937 &mt) {

    int yBuffer, xBuffer, newDirection;

    std::uniform_int_distribution<int> randDirection(0, 3);
    newDirection = randDirection(mt);

    while (newDirection == direction)
        newDirection = randDirection(mt);

    getXYbyDirection(posX, posY, direction);
    xBuffer = posX;
    yBuffer = posY;

    direction = (newDirection + 2) % 4;

    if (abs(posX) > (X / 2) || abs(posY) > (Y / 2))
        return false;
    for (int i = 0; i < 4; i++) {
        if (i != direction) {
            getXYbyDirection(xBuffer, yBuffer, i);
            if ((abs(xBuffer) > (X / 2) || abs(yBuffer) > (Y / 2)) ||
                !cells.at(getCellByPos(xBuffer, yBuffer))->isPathable()) {
                return false;
            }
        }
    }

    return true;

}

void Board::displayPartial() {
    for (int i = 105; i >= 0; i--) {
        for (int j = 0; j < 100; j++) {
            cells.at(getCellByPos(i, j))->displayCell();
        }
        cout << endl;
    }
}


//implement in next obstacle ....
bool Board::neighbourPathable(int posX, int posY, int direction) {

    int i = posX - 1, j = posY - 1;
    int exceptX = posX, exceptY = posY;

    switch (direction) {
        case 1:
            exceptY++;
            break;
        case 2:
            exceptX++;
            break;
        case 3:
            exceptY--;
            break;
        default:
            exceptX--;
            break;
    }

    for (; i < (posX + 1); i++) {
        for (; j < (posY + 1); j++) {
            if (i == exceptX && j == exceptY)
                break;
            if (i != posX && abs(i) < (X / 2) && j != posY && abs(i) < (Y / 2))
                if (!cells.at(getCellByPos(i, j))->isPathable())
                    return false;
        }
    }

    return true;
}


void Board::initializeFoodBig() {
    int bigFoodCount = 2;
    double bigFood = 20000;
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution<int> randX(-X / 4, X / 4);
    std::uniform_int_distribution<int> randY(-Y / 4, Y / 4);
    std::uniform_int_distribution<int> randDirection(0, 3);

    int randPosX = 0, randPosY = 0;

    while (bigFoodCount != 0) {
        int randomDir = randDirection(mt);

        if (randomDir % 2) {
            if (randomDir > 1) {
                randPosY = (Y - 2) / 2;
                randPosX = randX(mt);
            } else {
                randPosY = -(Y - 2) / 2;
                randPosX = randX(mt);
            }
        } else {
            if (randomDir > 1) {
                randPosX = (X - 2) / 2;
                randPosY = randY(mt);

            } else {
                randPosX = -(X - 2) / 2;
                randPosY = randY(mt);
            }
        }

        cells.at(getCellByPos(randPosX, randPosY))->foodDrop(bigFood);

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (j != i && j != -i && (i != 0 || j != 0))
                    cells.at(getCellByPos(randPosX + i, randPosY + j))->foodDrop(bigFood);
            }
        }

        bigFoodCount--;
    }
}

/*
 * Déplacement des fourmis sur le plateau
 */
void Board::antMovement(){
    for(int i = 0; i < Board::ants.size(); i++){
        if(Board::ants[i]->isCanMove()) {
            Cell * location = Board::ants[i]->getLocation();
            Board::ants[i]->setNeighborhood8(Board::neighborhood_8(location)); // mise à jour des 8 voisins de notre fourmi
            Board::ants[i]->actionMove();
        }
    }
}


vector<Cell *> Board::neighborhood_8(Cell *antLocation) {
    Cell *cell = antLocation;

    vector<Cell*> vNeighborhood;

    int posX = cell->getPosX();
    int posY = cell->getPosY();
    for(int i = -1; i <=1; i++) {
        for (int j = -1; j <= 1; j++) {
            int indice = Utils::calculIndice(posX + i, posY + j);
            if(posX + i < -(X/2) || posX + i > X/2 || posY + j > Y/2 || posY + j < -(Y/2)){
                continue;
            }
            if(i != 0 || j != 0){
                vNeighborhood.push_back(Board::cells[indice]);
            }
        }
    }

    return vNeighborhood;
}

void Board::addAnts(Ant *ant){
    this->ants.push_back(ant);
    this->nbAntColony++;
}

void Board::display(){
    char * c;
    for (int i=0; i < Board::cells.size(); i++){
        std::cout << Board::cells[i]->getPosX() << ";" << Board::cells[i]->getPosY() << endl;
    }

}

int Board::getNbAntColony() const {
    return nbAntColony;
}

void Board::setNbAntColony(int nbAntColony) {
    Board::nbAntColony = nbAntColony;
}
