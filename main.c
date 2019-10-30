#include <stdio.h>
#include "minidb.c"
#include "imSubsample.c"
#include "iplib2New.h"


int validate_in(int, int);

int validate_in(int redfactor, int dim) {
    if(dim%redfactor!= 0){
        return 1;
    }else{
        return 0;
    }
}

int main() {

    //dbdemo();
    //int test[5] = {1,5,7,9,10};
    //validate_in((int)argv[3], 2);
    //float out = stdev(5,test);

    //printf("Test std dev: %f",out);

    return 0;

}