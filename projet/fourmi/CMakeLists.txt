cmake_minimum_required(VERSION 3.20)
project (fourmi)

set(CMAKE_CXX_STANDARD 11)

add_executable(fourmi ensicaen/ecole/project/main.cpp ensicaen/ecole/project/model/ants/Queen.cpp ensicaen/ecole/project/include/Queen.h ensicaen/ecole/project/model/ants/Plebian.cpp ensicaen/ecole/project/include/Plebian.h ensicaen/ecole/project/model/ants/Soldier.cpp ensicaen/ecole/project/include/Soldier.h ensicaen/ecole/project/include/Board.h ensicaen/ecole/project/model/Board.cpp ensicaen/ecole/project/include/Cell.h ensicaen/ecole/project/model/Cell.cpp ensicaen/ecole/project/model/ants/Ant.cpp ensicaen/ecole/project/include/Ant.h ensicaen/ecole/project/model/ants/Worker.cpp ensicaen/ecole/project/include/Worker.h ensicaen/ecole/project/model/ants/Scout.cpp ensicaen/ecole/project/include/Scout.h ensicaen/ecole/project/model/ants/Slaver.cpp ensicaen/ecole/project/include/Slaver.h ensicaen/ecole/project/model/cells/Colony.cpp ensicaen/ecole/project/include/Colony.h ensicaen/ecole/project/model/cells/Terrain.cpp ensicaen/ecole/project/include/Terrain.h ensicaen/ecole/project/model/Utils.cpp ensicaen/ecole/project/include/Utils.h)
