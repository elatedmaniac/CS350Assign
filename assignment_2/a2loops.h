//
// Created by Michael Austin on 12/9/19.
//

#ifndef CS350ASSIGN_A2LOOPS_H
#define CS350ASSIGN_A2LOOPS_H

#include "../iplib2New.h"
#include "minidb.c"
#include "imSubsample.c"

void demoa2() {
    image_ptr imagePtr;

    image_ptr read_pnm(char *filename, int *rows, int *cols, int *type);
    int getnum(FILE *fp);
    void write_pnm(image_ptr ptr, char *filename, int rows, int cols, int type);


    int i, j, s, x, y;
    unsigned char avg;
    int rows, cols, type, n;
    dbdemo();


    char arg1[100];
    char arg2[100];
    char arg3[100];
    printf("Reading input image ... \n");
    scanf("%s", arg1);
    imagePtr = read_pnm(arg1, &rows, &cols, &type);
    scanf("%s", arg3);
    n = atoi(arg3);
    s = rows / n;
    unsigned char test_out[s][s];
    unsigned char block[n * n];
    printf("Image read successfully \n");
    printf("Rows=%d, Cols=%d, Type=%d\n", rows, cols, type);

    /*
     * Performs partitioning and image analysis, adding each mean to the array of unsigned chars that will be cast to the image pointer.
     * n is the reduction factor
     * s is the number of rows or columns (in the case of a square input image) found by dividing original rows/cols by reduction factor.
     */

    for (i = 0; i < rows; i = i + n) {
        for (j = 0; j < cols; j = j + n) {
            for (x = 0; x < n; x++) {
                for (y = 0; y < n; y++) {
                    block[x + y] = imagePtr[i * cols + j];
                }
            }
            avg = mean(n * n, block);
            test_out[i / n][j / n] = avg;
        }

    }

    image_ptr output_image = (image_ptr) test_out;
    printf("\nNow writing to image file ... \n");
    scanf("%s", arg2);
    write_pnm(output_image, arg2, s, s, type);
}

#endif //CS350ASSIGN_A2LOOPS_H
