//
// Created by Michael Austin on 2019-10-28.
//
#include "iplib2New.h"
#include <math.h>

// Define image
typedef struct image{
    int rows;
    int cols;
    int *pixels;
} IMG;

// Prototypes
float mean(int, int val[]);
float stdev(int, int val[]);
IMG resize(IMG *, int); // Method for performing reduction
int get_partitions(IMG, int);



float mean(int n, int val[]){
    int i;
    float total = 0;
    float mean;
    for(i=0; i<n;i++){

        total += (float) val[i];
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
float stdev(int n, int vals[]){
    int i;
    float diff;
    float mn = mean(n,vals);
    for(i=0;i<n;i++){
        diff += pow((vals[i]-mn),2);
    }

    return sqrtf((diff/(n-1)));
}

IMG *partition(IMG original, int s){
    int i,j;
    IMG one_part; //One partition block
    IMG *parts[s*s]; // Composite of all blocks

    malloc(sizeof(IMG)*s*s);
    int n = original.rows/s;
    if(s%original.rows !=0 || s%original.cols!=0){
        printf("%d is not a valid reduction size as it is not a multiple of %d", s, original.rows);
        exit(1);
    }
    for(i = 0; i<s*s; i++){
        for(j=0;j<n; j++){
            one_part.pixels[j] = original.pixels[j+i];
        }
        one_part.rows, one_part.cols = n;
        parts[i] = &one_part;
    }

    return parts;
}

IMG resize(IMG *partitions, int n){
    int i;
    IMG new_img;
    for(i=0;i<n*n; i++){
        int new_px = mean(partitions[i].rows, partitions[i].pixels);
        new_img.pixels[i] = new_px;
    }
    new_img.rows, new_img.cols = n;

    return new_img;
}







