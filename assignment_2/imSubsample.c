//
// Created by Michael Austin on 2019-10-28.
//
#include <math.h>


// Prototypes
unsigned char mean(int n,unsigned char val[]);
float stdev(int, unsigned char val[]);




unsigned char mean(int n, unsigned char val[]){
    int i;
    unsigned char total = 0;
    unsigned char mean;
    for(i=0; i<n;i++){

        total += val[i];
    }
    mean = total/n;
    return mean;

}

/*
 * Computes standard deviation given an array of values and their count.
 * Works in testing. Displays out to 6 decimal places.
 * Input: array of integers and their count.
 * Output: float value containing the
 */
float stdev(int n, unsigned char vals[]){
    int i;
    float diff =0;
    int mn = (int) mean(n,vals);
    for(i=0;i<n;i++){
        diff += pow((vals[i]-mn),2);
    }

    return sqrtf((diff/(n-1)));
}