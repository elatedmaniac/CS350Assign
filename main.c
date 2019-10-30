#include <stdio.h>
#include "minidb.c"
#include "imSubsample.c"
#include "iplib2New.h"

#define f "C:\\Users\\Syndikit\\CLionProjects\\CS350Assign\\data\\bg448x448.pgm"
#define o "C:\\Users\\Syndikit\\CLionProjects\\CS350Assign\\data\\SAMPLE_OUTPUT.pgm"

int ROWS, COLS, TYPE;
image_ptr imagePtr, imagePtr2;


int validate_in(int, int);
image_ptr read_pnm(char *filename, int *rows, int *cols, int *type);
int getnum(FILE *fp);
void write_pnm(image_ptr ptr, char *filename, int rows, int cols, int type);

int validate_in(int redfactor, int dim) {
    if(dim%redfactor!= 0){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char **argv) {
    int rows, cols, type;
    //dbdemo();
    //int test[5] = {1,5,7,9,10};
    //validate_in((int)argv[3], 2);
    //float out = stdev(5,test);

    //printf("Test std dev: %f",out);
    printf("reading input image ... \n");

    //imagePtr = read_pnm(argv[1], &rows, &cols, &type);
    imagePtr = read_pnm(f, &rows, &cols, &type);
    /*
     * if (!validate_in((int)argv[4],rows)){
        printf("Invalid reduction factor!\n");
        exit(1);
    }
     */

    int i, j, n, s;
    s = 2;
    n = rows/s;

    int blocks[s*s];
    printf("image read successfully \n");
    printf("rows=%d, cols=%d, type=%d \n", rows, cols, type);

    for (int k = 0; k < s*s; k++) {
        unsigned char subsample[n][n];
        for (i=0; i< n; i++){
            for (j=0; j< n; j++)
            {
                subsample[i][j]=imagePtr[i*cols + j];
            }


        }
        blocks[k] = mean(n,subsample);
    }

    image_ptr output_image = (image_ptr) blocks;

    printf("\n Now writing to image file ... \n");
    write_pnm(output_image,o,n,n,type);
    //write_pnm(output_image,argv[3],n,n,type);
    return 0;

}