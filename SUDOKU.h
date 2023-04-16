
#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include "stdTypes.h"
#include <windows.h>
#include "conio.h"

typedef struct{
    s32 square;
    s32 row;
    s32 column;
    s32 ack;
}coordinate;

void SUDOKU_create ();
void SUDOKU_initialize ();
void SUDOKU_original ();
void SUDOKU_set ();
coordinate SUDOKU_scanCoordinate ();
s32 SUDOKU_scanNumber ();
coordinate SUDOKU_check ( coordinate desiredCoordinate, s32 number);
s32 SUDOKU_youAreTheWinner ();
void SUDOKU_play ();
void SUDOKU ();

void SUDOKU_storeElements ();
void SUDOKU_initializeElements ();
void SUDOKU_initializeElements ();
void SUDOKU_storeFixedElements ();
void SUDOKU_initializeFixedElements ();

void SUDOKU_storePlayNumber ();
void SUDOKU_initializePlayNumber ();

#endif