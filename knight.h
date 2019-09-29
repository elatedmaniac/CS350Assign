//
// Created by Michael Austin on 2019-09-24.
//

#ifndef CS350ASSIGN_KNIGHT_H
#define CS350ASSIGN_KNIGHT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max_moves 64
/*
 * Global variables for the board to be printed from the display board method,
 * total number of moves taken, int-boolean can_move indicates whether a move is possible,
 * and the current x and y position of the knight.
 */
int board[8][8]={
        {1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1}
};
int moves_taken = 2;
int curr_x,curr_y = 0;


/*
 * All possible x-y combinations of knight moves on the chessboard.
 */
int horizontal[8] = {2,1,-1,-2,-2,-1,1,2};
int vertical[8] = {-1,-2,-2,-1,1,2,2,1};

// Initial accessibility matrix
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

/*int * possible_moves(){
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

}*/

/*
int getx(){
    for (int i =0;i<8;i++){
        int x = horizontal[i]+curr_x;
        if (x<0 || x>8){
            break;
        }else{
            return x;
        }
    }

}

int gety(){
    //
    for (int i =0;i<8;i++){
        // Gets me an x candidate
        int y = vertical[i]+curr_x;
        if (y<0 || y>8){
            break;
        }else{
            return y;
        }
    }

}
*/

/*int * best_move(int opt[]){
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


}*/

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
void knight_move(int row,int col, int move){
    board[row][col]=move;
    curr_y = col;
    curr_x = row;


}
int rand_choice(){
    srand(time(0));
    int limit = RAND_MAX - (RAND_MAX/10);
    int r = rand();
    while(r>=limit);

    return r%10;
}
/*
 * Calls all of the previous methods and uses loops to continue moving the knight until no moves left.
 */
void solve(){
   while (moves_taken<=64){
       int newx, newy;
       int ascore = 9;
       int i;
       for (i=0;i<8;i++) {
           int y = horizontal[i]+curr_y;
           int x = vertical[i]+curr_x;
           if(x>=0 && y>=0 && x<=7 && y<=7){
               if(board[x][y] == -1) {
                   if(access_matrix[x][y]<ascore){
                       newx = x;
                       newy=y;
                   }
                   else if(access_matrix[x][y]==ascore){
                       int ran = rand_choice();
                       if(ran>=5){
                           newx = x;
                           newy=y;
                       }
                   }

               }
           }
       }
       printf("Move # %d\tNew X = %d\tNew Y = %d\n",moves_taken,newx,newy);
       knight_move(newx, newy, moves_taken);
       moves_taken += 1;
    }

}



void results(){
    // Displays the blank board and accessibility matrix
    display_board(board);
    display_board(access_matrix);
    solve();
    display_board(board);
}


#endif //CS350ASSIGN_KNIGHT_H
