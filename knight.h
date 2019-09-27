//
// Created by Michael Austin on 2019-09-24.
//

#ifndef CS350ASSIGN_KNIGHT_H
#define CS350ASSIGN_KNIGHT_H

#include <stdlib.h>
#include <stdio.h>

int max_moves = 64;
int board[8][8]={0};
int moves_taken = 0;
int can_move = 1;
int curr_x,curr_y = 0;

int horizontal[8] = {2,1,-1,-2,-2,-1,1,2};
int vertical[8] = {-1,-2,-2,-1,1,2,2,1};

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

void display_board(int sboard[8][8]);

int * possible_moves(){
    int valid[8] = {9,9,9,9,9,9,9,9};
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

int * best_move(int opt[8]){
    // For-loop counter, current best move, and possible moves array
    int i;
    int best[2] = {0,0};
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

void solve(){
    // Displays the blank board and accessibility matrix
    display_board(board);
    display_board(access_matrix);
    //knight_move(3,4);
    //knight_move(3,7);
    //printf(can_move ? "true":"false");
    //display_board(board);
    int *options = possible_moves();
    int *mv = best_move(options);
    printf("%d\n%d\n",options[0],mv[0]);
    /*while (can_move==1){

        knight_move(mv[0],mv[1]);
    }*/
    //display_board(board);
}


#endif //CS350ASSIGN_KNIGHT_H
