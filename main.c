#include <stdio.h>
#include "minidb.c"
#include "imSubsample.c"
#include "iplib2New.h"

//#define f "bg448x448.pgm"
//#define o "data//SAMPLE_OUTPUT.pgm"


image_ptr imagePtr;

image_ptr read_pnm(char *filename, int *rows, int *cols, int *type);
int getnum(FILE *fp);
void write_pnm(image_ptr ptr, char *filename, int rows, int cols, int type);


int main(int argc, char **argv) {
    int i, j, s, x, y;
    unsigned char avg;
    int rows, cols, type, n;
    //dbdemo();



    printf("Reading input image ... \n");
    imagePtr = read_pnm(argv[1], &rows, &cols, &type);
    n = atoi(argv[3]);
    s = rows/n;
    unsigned char test_out[s][s];
    unsigned char block[n*n];
    printf("Image read successfully \n");
    printf("Rows=%d, Cols=%d, Type=%d\n", rows, cols, type);

    /*
     * Performs partitioning and image analysis, adding each mean to the array of unsigned chars that will be cast to the image pointer.
     * n is the reduction factor
     * s is the number of rows or columns (in the case of a square input image) found by dividing original rows/cols by reduction factor.
     */

    for(i=0;i<rows;i=i+n){
        for(j=0;j<cols;j=j+n){
            for(x=0;x<n;x++){
                for(y=0;y<n;y++) {
                    block[x+y] = imagePtr[i*cols+j];
                }
            }
            avg = mean(n*n,block);
            test_out[i/n][j/n] = avg;
        }

    }

    image_ptr output_image = (image_ptr) test_out;
    printf("\nNow writing to image file ... \n");

    write_pnm(output_image,argv[2],s,s,type);
    return 0;

}