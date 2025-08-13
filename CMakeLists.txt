cmake_minimum_required(VERSION 3.27)
project(fastDisableDefender C)

set(CMAKE_C_STANDARD 11)

# Liste des fichiers sources (C + RC)
add_executable(fastDisableDefender
    main.c
    resources.rc
)
