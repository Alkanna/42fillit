# 42fillit

This program takes a mapfile with at most 26 valid pieces of tetris each separated into a 4*4 dotted map, written as a junction of 4 #'s.
It then attempts to store them into a square map to fit them all in the most condensed way possible, without rotating the pieces.

This version of the project features some bonuses, mainly color arguments.

## Getting Started

Compilation is pretty straightforward :

```
make
```

You can also run ```make help``` to have some insight on what the Makefile can do for you.

## Usage

Simply run ```./fillit (arg) [mapfile]``` to use the program, however note than only one argument at a time is supported.

Available arguments are :

```
-c : Will assign one random color to each group of letters
-cfr : Will go full random on colored letters, without assigning them by groups
-cm : Displays a pretty output map, with fixed colors for each piece, you can see the color macros in ./includes/colors.h
-cmr : Displays a pretty output map, with random colors for each piece
```

Fully coded in C.

Have fun !
