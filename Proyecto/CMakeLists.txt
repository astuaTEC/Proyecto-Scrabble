cmake_minimum_required(VERSION 3.13)
project(Proyecto)

set(CMAKE_CXX_STANDARD 17)

include_directories(. include/rapidjson)

add_executable(Proyecto main.cpp Tablero/Tablero.cpp Tablero/Tablero.h Tablero/Elemento.cpp Tablero/Elemento.h Prueba.cpp Dealer/Ficha.cpp Dealer/Ficha.h Dealer/Dealer.cpp Dealer/Dealer.h Estructuras/List.cpp Estructuras/List.h Estructuras/Node.cpp Estructuras/Node.h Converter/Converter.cpp Converter/Converter.h Converter/Person.cpp)


