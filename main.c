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
    dbdemo();
    //int test[5] = {16,8,13,9,10};
    //printf("reading input image ... \n");

    //imagePtr = read_pnm(argv[1], &rows, &cols, &type);
    /*imagePtr = read_pnm(f, &rows, &cols, &type);

    int i, j, n, s, s1, s2;
    n = 2;
    s = rows/n;

    printf("image read successfully \n");
    printf("rows=%d, cols=%d, type=%d \n", rows, cols, type);

    unsigned char test_out[s][s];
    unsigned char block[n];
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            for(s1=0;s1<rows;s1+n){
                for(s2=0;s2<cols;s2+n){
                    block[s2] = imagePtr[s1*cols +s2];
                }
            }
            test_out[i][j] = mean(n*n,block);
        }
    }



    image_ptr output_image = (image_ptr) test_out;

    printf("\n Now writing to image file ... \n");
    write_pnm(output_image,o,n,n,type);
    //write_pnm(output_image,argv[3],n,n,type);*/
    return 0;

}