#!/bin/bash

echo "Lezgo solve this"

gcc -O3 lotka-volterra.c -o lotka-volterra.out

time ./lotka-volterra.out
time gnuplot plot.plt

rm *.dat
rm *.out

echo "Equations Solved. EZ"