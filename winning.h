#include<stdbool.h>
#ifndef WINNING_H
#define WINNING_H

bool checkWin(int rows, int columns, char board[rows][columns], int row, int col, char playerPiece, int piecesToWin);

#endif