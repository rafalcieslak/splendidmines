#!/bin/sh

clang++ core/*.cpp gui/*.cpp frontend/*.cpp -o splendidmines -g -std=c++11 -Wall `pkg-config --cflags --libs gtkmm-3.0`
