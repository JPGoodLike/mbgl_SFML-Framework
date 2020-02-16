#!/bin/bash

cd ~/Desktop/dev/cpp/SFML/mbglFramework_SFML/
g++ ./*.cpp ./Scenes/*.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system