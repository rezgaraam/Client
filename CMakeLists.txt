cmake_minimum_required(VERSION 3.20)
project(Client)

set(CMAKE_CXX_STANDARD 14)

include_directories(Client)

add_executable(Client
        Client/Client.cpp
        Client/Client.h
        Client/Error.h
        Client/main.cpp Client/Expression.h Client/Expression.cpp Client/Constante.h Client/Constante.cpp Client/Fois.h Client/Fois.cpp Client/OpBinaire.h Client/OpBinaire.cpp Client/Plus.h Client/Plus.cpp Client/Variable.h Client/Variable.cpp)
