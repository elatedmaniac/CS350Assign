#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "knight.h"
#include "temperature.h"
#include "gcd.h"

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

 void main() {
    //triples();
    //charts();
    /*
    int *arr;
    arr = possible_moves();
    for (int i =0;i<8;i++){
        printf("%d\n",arr[i]);
    }
    */
    //gcd_recurs(2,4);
    //gcd_recurs(13,52);
    //gcd_recurs(1,4);
    results();
}