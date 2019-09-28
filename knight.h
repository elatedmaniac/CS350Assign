//
// Created by Michael Austin on 2019-09-24.
//

#ifndef CS350ASSIGN_KNIGHT_H
#define CS350ASSIGN_KNIGHT_H

#include <stdlib.h>
#include <stdio.h>

#define max_moves 64
/*
 * Global variables for the board to be printed from the display board method,
 * total number of moves taken, int-boolean can_move indicates whether a move is possible,
 * and the current x and y position of the knight.
 */
int board[8][8]={0};
int moves_taken = 0;
int can_move = 1;
int curr_x,curr_y = 0;

/*
 * All posible x-y combinations of knight moves on the chessboard.
 */
int horizontal[8] = {2,1,-1,-2,-2,-1,1,2};
int vertical[8] = {-1,-2,-2,-1,1,2,2,1};

// Initial accessiblity matrix
int access_matrix[8][8] = {
        {2,3,4,4,4,4,3,2},
        {3,4,6,6,6,6,4,3},
        {4,6,8,8,8,8,6,4},
        {4,6,8,8,8,8,6,4},
        {4,6,8,8,8,8,6,4},
        {4,6,8,8,8,8,6,4},
        {3,4,6,6,6,6,4,3},
        {2,3,4,4,4,4,3,2}
};

// prototype of the display_board method.
void display_board(int sboard[8][8]);

int * possible_moves(){
    static int valid[8];
    int arr_counter = 0;
    for (int i =0;i<8;i++){
        int x = horizontal[i]+curr_x;
        int y = vertical[i]+curr_y;
        if (x<0 || y<0){
            continue;
        }else{
            valid[arr_counter]=i;
            arr_counter += 1;
        }
    }
    if (valid[0] == 9 || moves_taken==max_moves-1){
        can_move = 0;
    }
    return valid;

}

int * best_move(int opt[]){
    // For-loop counter, current best move, and possible moves array
    int i;
    static int best[2] = {0,0};
    int acc_num = 9;

    // Iterates through possible options and compares value in accessibility matrix
    for (i=0;i<8;i++){
        if (acc_num>opt[i]){
            acc_num = opt[i];
            best[0] = horizontal[acc_num];
            best[1] = vertical[acc_num];
        }

    }
    return best;


}

// Iterates through 2-D array of chessboard and prints to console.
void display_board(int sboard[8][8]){
    int i,j;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            printf("%d ",sboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Takes care of marking knight movement, updating current x and y,
// and incrementing move counter
void knight_move(int row,int col){

    curr_x = row;
    curr_y = col;
    board[row][col]=moves_taken;
    moves_taken += 1;

}

/*
 * Calls all of the previous methods and uses loops to continue moving the knight until no moves left.
 */
void solve(){
    // Displays the blank board and accessibility matrix
    static int mv[2];
    static int options[8];
    display_board(board);
    display_board(access_matrix);

    //printf("%d\n%d\n",options[0],mv[0]);
    while (can_move==1){
        options[8] = possible_moves();
        mv[2] = best_move(options);
        knight_move(mv[1],mv[0]);
    }
    display_board(board);
}


#endif //CS350ASSIGN_KNIGHT_H
