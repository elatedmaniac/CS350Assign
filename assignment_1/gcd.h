//
// Created by Michael Austin on 2019-09-24.
//

#ifndef CS350ASSIGN_GCD_H
#define CS350ASSIGN_GCD_H

#include <stdio.h>
void gcd(int num1, int num2){

    int least;
    int i;
    int gcf = 0;
    if(num1<num2){
        least = num1;
    }
    else if(num2<num1){
        least = num2;
    }

    for (i=1;i<=least;i++){
        if(num1%i==0 && num2%i==0){
            gcf = i;

        }
    }
    if (gcf==0){
        printf("There is no common factor between %d and %d.\n",num1,num2);
    }
    else{
        printf("The GCD of %d and %d is %d\n",num1,num2,gcf);
    }
}

int gcd_recurs(int num1, int num2){

    int least;
    int big;
    int gcf = 0;
    if(num1<num2){
        least = num1;
        big = num2;
    }
    else if(num2<num1){
        least = num2;
        big = num1;
    }

    if (least==0){
        gcf = big;
        printf("The GCD is: %d\n",gcf);
        return gcf;
    }
    else{
        return gcd_recurs(least,big%least);
    }



}

#endif //CS350ASSIGN_GCD_H
