//
// Created by Michael Austin on 2019-10-28.
//
#include "a2_samples/iplib2New.c"
#include <math.h>

// Prototypes
float mean(int, int val[]);
float stdev(int, int val[]);


float mean(int n, int val[]){
    int i;
    int total = 0;
    float mean;
    for(i=0; i<n;i++){

        total += val[i];
    }
    mean = total/n;
    return mean;

}
// Computes standard deviation given an array of values and their count.
float stdev(int n, int vals[]){
    int i;
    float diff;
    float mn = mean(n,vals);
    for(i=0;i<n;i++){
        diff += pow((vals[i]-mn),2);
    }
    return diff/(n-1);
}





