cmake_minimum_required(VERSION 4.0)
project(MEMOIRE_ENSIIE C)

set(CMAKE_C_STANDARD 11)

add_executable(hw
        C/TP1/helloWorld.c)
add_executable(EX1 C/TP1/EX1/lorem.c)
add_executable(EX5 C/TP1/EX5/sommeproduit.c)
add_executable(EX7 C/TP1/EX7/milieu.c)
add_executable(EX9 C/TP1/EX9/sphere.c)
add_executable(EX10 C/TP1/EX10/positif.c)
add_executable(EX12 C/TP1/EX12/tablem.c)
add_executable(EX17 C/TP1/EX17/rectangle.c)
add_executable(EX18 C/TP1/EX18/gravite.c)
add_executable(EX22 C/TP1/EX22/triangle.c
        C/TP1/EX22/triangle.c)

add_executable(23 C/TP1/EX23/norme1.c )
