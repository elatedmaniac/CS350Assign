#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "iplib2New.h"

typedef struct analytics{
    float mean;
    float std_dev;
} Model;
int i,j,k,j;
image_ptr read_pnm(char *filename, int *rows, int *cols, int *type);
int getnum(FILE *fp);
void write_pnm(image_ptr ptr, char *filename, int rows, int cols, int type);
void *threadFunction(void *tnum);
Model perform_analysis(image_ptr input);

// pthread attributes for threads and mutex locking.
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;


int s=0,m=0, n=0, totalM = 0, p=0,count = 0;
int rows=0, cols=0, type=0;
unsigned char redImg[750][750];

// Stats global variables
float stdDev = 0, avg = 0;
image_ptr imagePtr;

int main(int argc, char **argv) {
    image_ptr outPtr;

    printf("Reading input image ... \n");
    imagePtr = read_pnm(argv[1], &rows, &cols, &type);
    printf("Image read successfully \n");
    printf("Rows=%d, Cols=%d, Type=%d\n", rows, cols, type);
    count=0;
    m=rows;

    // Reduction Factor
    n = atoi(argv[3]);
    p = atoi(argv[4]);
    // Side dimensions for new image
    s = rows / n;
    totalM=m*m;
    unsigned char redCopy[s][s];
    pthread_t thread_id[p];
    int threads[p];
    for(k=0;k<p;k++){
        threads[k]=k;
        pthread_create(&thread_id[k],NULL,threadFunction,(void *)&threads[k]);
    }

    for(j=0;j<p;j++){
        pthread_join(thread_id[j],NULL);
    }

    int b,d;
    for(b=0;b<s;b++){
        for(d=0;d<s;d++){
            redCopy[b][d]=redImg[b][d];
        }
    }

    outPtr = (image_ptr) redCopy;

    printf("\nNow writing to image file ... \n");
    write_pnm(outPtr, argv[2], s, s, type);
    return 0;
}

void *threadFunction(void *vargp){

    pthread_mutex_lock(&mut);
    int *tnum = (int *)vargp;
    int worker_num = *tnum;

    int i=0,j=0,k=0,value=0,y=0;
    int J,K;
    Model blk;
    int X, Y, currX, currY;
    image_ptr imagePtr2;
    unsigned char imgBlock[n][n];

    int threadcontrol=-1;
    int worker = worker_num;

    X = n;
    Y = n;
    J =0;
    K=0;

    for(i=0;i<s;i++){
        for(y=0;y<s;y++){
            threadcontrol++;
            currX =0,currY=0;
            if(Y>m){
                Y=n;
                X+=n,J +=n;
                K = 0;
            }
            for(j=J;j<X;j++){
                for(k=K;k<Y;k++){
                    imgBlock[currX][currY]=imagePtr[j*cols + k];
                    currY++;
                }
                currX++;
            }
            K += n;

            if(worker == threadcontrol%p){
                count++;

                imagePtr2 = (image_ptr) imgBlock;
                blk = perform_analysis(imagePtr2);
                redImg[i][y]=blk.mean;
                stdDev += blk.std_dev;
                avg += blk.mean;
            }
            Y+=n;
        }
    }
    pthread_mutex_unlock(&mut);
    return NULL;
}

Model perform_analysis(image_ptr input){
    Model new_model;
    int counter =n;
    int total = n*n;
    float vals[total];
    float sum=0, var=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum+= input[i*n+j];
        }
    }

    new_model.mean = (float)sum/(float) total;
    for(i=0;i<counter;i++){
        var+=powf(vals[i]-new_model.mean,2.0);
    }
    return new_model;
}
