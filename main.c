//main program 
#include <stdio.h>
#include <stdlib.h>
#include "connectn.h"
#include "winning.h"


int main(int argc, char *argv[]) {//takes in number of arguments (argument count)
    if (argc < 4) {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else if (argc > 4){
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }

    //takes in the argument vectors
    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);
    int piecesToWin = atoi(argv[3]);

    // Checks the validity of user input
    if (rows <= 0 || columns <= 0 || piecesToWin <= 0) {
        printf("Invalid input values\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        return 1;
    }

    playConnectN(rows, columns, piecesToWin);// play the game

    return 0;
}
