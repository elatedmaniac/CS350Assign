#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

void triples(){
    for(int i=1;i<20;i++){
        int i_sq = pow(i,2);
        for(int j=1;j<i;j++){
            int j_sq = pow(j,2);
            for(int hyp=1;hyp<j;hyp++){
                double hyp_sq = i_sq + j_sq;
                double hyp_root = sqrt(hyp_sq);
                float total = i_sq+j_sq+hyp_sq;
                if(total<=500){
                    printf("The triples %d,%d, and %f sum to %f\n",i,j,hyp_root,total);
                }else{
                    continue;
                }
            }
        }
    }
}

double celsius(double murica){
    double cels_conv = 5.0/9.0;
    double sub = murica-32.0;
    //printf("%f degrees Celsius\n",cels_conv*sub);
    return cels_conv*sub;
}

double fahrenheit(int cels){
    double f_conv = 9.0/5.0;
    double sum = (f_conv*cels)+32;
    //printf("%f\n",sum);
    return sum;
}

void charts(){
    printf("Celsius:\tFahrenheit:\n");
    for (int i =0;i<=100;i++){
        double fah = fahrenheit(i);
        printf("%d\t\t\t%f\n",i,fah);
    }
    printf("Fahrenheit:\tCelsius:\n");
    for (int i =32;i<=212;i++){
        double cel = celsius(i);
        printf("%d\t\t\t%f\n",i,cel);
    }
}

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



 void main() {
    //triples();
    //charts();
    display_board(board);
    knight_move(0,0);
    //display_board(board);
    int *arr;
    arr = possible_moves();
    for (int i =0;i<8;i++){
        printf("%d",arr[i]);
    }
    display_board(access_matrix);
    printf("\nSize of access matrix: %d", sizeof(access_matrix));
}