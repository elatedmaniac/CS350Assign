#include <stdio.h>
#include "minidb.c"
#include "imSubsample.c"


int validate_in(int redfactor, int dim);

int validate_in(int redfactor, int dim) {
    if(dim%redfactor!= 0){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char **argv) {

    dbdemo();

    validate_in((int)argv[3], 2);

    return 0;

}