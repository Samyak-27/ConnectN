// C file containing information about initializing the board, printing the board, checking if the move is valid anf playing the game
#include <stdio.h>
#include <stdbool.h>
#include "connectn.h"
#include "winning.h"

// Initialize the game board with empty spaces
void initializeBoard(int rows, int columns, char board[rows][columns]) {// takes in the number of rows and columns required for the game and a board with that specfic dimensions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = '*';
        }
    }
}

// Print the game board
void printBoard(int rows, int columns, char board[rows][columns]) {// takes in the number of rows and columns required for the game and a board with that specfic dimensions
    for (int i = 0; i < rows; i++) {
        printf("%d ", rows - (i + 1));
        for (int j = 0; j < columns; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < columns; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

// Check if the move is valid (within bounds and column not full)
bool isValidMove(int rows, int columns, char board[rows][columns], int column) {//takes in the number of rows and colums and the current board structure and the column where the user enetred the key at
    return column >= 0 && column < columns && board[0][column] == '*';
}

int getValidInput(int columns){ // prints the prompt, checks if the retirement age is more than current ages
    int column;
    scanf("%d", &column);
    while (column < 0 || column > columns) {
        printf("Enter a column between 0 and %d to play in: ", columns - 1);
        while (getchar() != '\n'); // Clear input buffer
        scanf("%d", &column);
    }
    return column;
}

// Play the connectN game
void playConnectN(int rows, int columns, int piecesToWin) {//takes in the number of rows, columns and pieces to win as per user input
    char board[rows][columns];//creating a 2D array of the board
    char players[] = {'X', 'O'}; //initializing array with the given pieces
    int currentPlayerIndex = 0;//using index to find the current player piece
    int movesCount = 0;//counts the number of moves
    int n = 0;

    initializeBoard(rows, columns, board);//initialize the board

    while (true) {
        printBoard(rows, columns, board);//prints the board

        int column;
        do {
            printf("Enter a column between 0 and %d to play in: ", columns - 1);
            column = getValidInput(columns);
            n += 1;
        } while (!isValidMove(rows, columns, board, column) && n < 20);//checks if the move is valid

        // Make the move
        int row;
        for (row = rows - 1; row >= 0; row--) {
            if (board[row][column] == '*') {
                board[row][column] = players[currentPlayerIndex];
                break;
            }
        }

        // Check for a win
        if (checkWin(rows, columns, board, row, column, players[currentPlayerIndex], piecesToWin)) {
            printBoard(rows, columns, board);
            printf("Player %d Won!\n", currentPlayerIndex + 1);
            break;
        }

        // Check for a tie
        movesCount++;
        if (movesCount == rows * columns) {
            printBoard(rows, columns, board);
            printf("Tie game!\n");
            break;
        }

        // Switch players
        currentPlayerIndex = 1 - currentPlayerIndex;
    }
}
