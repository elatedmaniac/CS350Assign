//
// Created by Michael Austin on 2019-09-24.
//

#ifndef CS350ASSIGN_KNIGHT_H
#define CS350ASSIGN_KNIGHT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
 * Global variables for the board to be printed from the display board method,
 * total number of moves taken, int-boolean can_move indicates whether a move is possible,
 * and the current x and y position of the knight.
 */
int board[8][8]={
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1}
};

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
// prototype of the validity check for a calculated possible move
int valid_check(int,int,int final[8][8]);

// Takes in x-y coordinates to ensure they are within the board and cross-checks with the availability of the space.
int valid_check(int xchk, int ychk, int final[8][8]){
    if (xchk>=0 && ychk>=0 && xchk<=7 && ychk<=7&&final[xchk][ychk]==-1){
        return 1;
    }
    return 0;
}

// Produces randomly generated number 0 through 10 using current time since 1970 in seconds as the seed
int rand_choice(){
    srand(time(0));
    int limit = RAND_MAX - (RAND_MAX/10);
    int r = rand();
    while(r>=limit);

    return r%10;
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

/*
 * Calls all of the previous methods and uses loops to continue moving the knight until no moves left.
 */
int solve(int sx, int sy, int final[8][8], int count){
    if (count == 64){
        return 1;
    }
       int i;
       for (i=0;i<8;i++) {
           // Gets the next x-y coordinates and checks them for validity/ availability
           int x = sx + horizontal[i];
           int y = sy + vertical[i];
           if(valid_check(x,y,final)){
               // Move is good --> current move number replaces -1 in the solution matrix; move count incremented
               final[x][y] = count;
               count += 1;
               // Recursively calls the function to go down the full path.
               if(solve(x,y,final,count))
                   return 1;
                // If the path leads down a blind alley, backtrack at the point of zero moves; decrement count.
               else{
                   final[x][y] = -1;
                   count -= 1;
               }
           }
    }
       return 0;

}

int results(){
    // Displays the blank board and accessibility matrix
    printf("Starting Chessboard:\n");
    display_board(board);
    printf("Accessibility Matrix:\n");
    display_board(access_matrix);
    board[0][0]=0;
    if(solve(0,0,board,1)){
        printf("Final Chessboard:\n");
        display_board(board);
        return 1;
    }
    return 0;
}


#endif //CS350ASSIGN_KNIGHT_H
