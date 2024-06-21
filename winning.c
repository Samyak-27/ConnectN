//C file to check if the winning conditions

#include <stdio.h>
#include <stdbool.h>
#include "winning.h"

bool checkWinHorizontal(int rows, int columns, char board[rows][columns], int row, int col, char playerPiece, int piecesToWin);
bool checkWinVertical(int rows, int columns, char board[rows][columns], int row, int col, char playerPiece, int piecesToWin);
bool checkWinDiagonal(int rows, int columns, char board[rows][columns], int row, int col, char playerPiece, int piecesToWin);

//checks if any player has won
bool checkWin(int rows, int columns, char board[rows][columns], int row, int col, char playerPiece, int piecesToWin) {//takes in rows, columns, board, current row and column and the number of pieces to win
    // Check if the player has won the game
    if (checkWinHorizontal(rows, columns, board, row, col, playerPiece, piecesToWin) ||
        checkWinVertical(rows, columns, board, row, col, playerPiece, piecesToWin) ||
        checkWinDiagonal(rows, columns, board, row, col, playerPiece, piecesToWin)) {//using OR to check if either one is true
        return true;
    }
    return false;
}

// Check if the player wins horizontally
bool checkWinHorizontal(int rows, int columns, char board[rows][columns], int row, int col, char playerPiece, int piecesToWin){//takes in rows, columns, board, current row and column and the number of pieces to win
    
    // Horizontal right
    int count = 1;
    for (int i = col + 1; i < columns && board[row][i] == playerPiece; i++) {
        count++;
    }
    
    // Horizontal win (left)
    for (int i = col - 1; i >= 0 && board[row][i] == playerPiece; i--) {
        count++;
    }

    if (count >= piecesToWin) {
        return true;
    }

    return false;
}

// Checks if the player wins vertically
bool checkWinVertical(int rows, int columns, char board[rows][columns], int row, int col, char playerPiece, int piecesToWin){//takes in rows, columns, board, current row and column and the number of pieces to win
    int count = 0;
    for (int i = row; i < rows; i++) {
        if (board[i][col] == playerPiece) {
            count++;
        } else {
            break;
        }
    }
    if (count >= piecesToWin) {
        return true;
    }
    return false;
}

//Checks if the player wins Diagonally
bool checkWinDiagonal(int rows, int columns, char board[rows][columns], int row, int col, char playerPiece, int piecesToWin){//takes in rows, columns, board, current row and column and the number of pieces to win
    // Check diagonally (top-left to bottom-right)
    int count = 0;
    for (int i = row, j = col; i < rows && j < columns; i++, j++) {
        if (board[i][j] == playerPiece) {
            count++;
        } else {
            break;
        }
    }
    if (count >= piecesToWin) {
        return true;
    }

    // Check diagonally (top-right to bottom-left)
    count = 0;
    for (int i = row, j = col; i < rows && j >= 0; i++, j--) {
        if (board[i][j] == playerPiece) {
            count++;
        } else {
            break;
        }
    }
    if (count >= piecesToWin) {
        return true;
    }

    return false;
}