//
// Created by Michael Austin on 2019-09-24.
//

#ifndef CS350ASSIGN_KNIGHT_H
#define CS350ASSIGN_KNIGHT_H

#include <stdlib.h>
#include <stdio.h>

int board[8][8]={0};
int moves_taken = 0;
int curr_x,curr_y = 0;
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
    int horizontal[8] = {2,1,-1,-2,-2,-1,1,2};
    int vertical[8] = {-1,-2,-2,-1,1,2,2,1};
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
    return valid;

}

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

void knight_move(int row,int col){
    if (row<0 || col<0){
        printf("Invalid move");
    }else{
        board[row][col]=9;
        moves_taken += 1;
    }

}


#endif //CS350ASSIGN_KNIGHT_H
