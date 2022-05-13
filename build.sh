#!/bin/bash

gcc src/*.c -o Pacman -O2 -std=c99 -Wall -I hdr/ \
	-I ~/raylib/src/external -I ~/raylib/src -I ~/raylib/src/extras \
	-DPLATFORM_DESKTOP -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

./Pacman
rm Pacman
