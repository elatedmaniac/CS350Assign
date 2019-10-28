//
// Created by Syndikit on 10/24/2019.
//
#include <stdio.h>
#include <math.h>
#include "knight.h"
#include "temperature.h"
#include "gcd.h"

void triples(){
    for(int i=1;i<500.0;i++){
        int i_sq = pow(i,2);
        for(int j=1;j<500;j++){
            int j_sq = pow(j,2);
            for(int hyp=1;hyp<500;hyp++){
                double hyp_sq = i_sq + j_sq;
                double hyp_root = sqrt(hyp_sq);
                float total = i_sq+j_sq+hyp_sq;
                if(total<500) {
                    if((i_sq+j_sq) != (hyp*hyp)){
                        continue;
                    }
                    printf("The triples %d,%d, and %f sum to %f\n", i, j, hyp_root, total);
                }
            }
        }
    }
}

void a1_calls(){
    triples();
    charts();

    gcd(63,81);
    gcd(191,2);
    gcd(11,11);

    gcd_recurs(2,4);
    gcd_recurs(13,52);
    gcd_recurs(1,4);
    results();
}

#ifndef CS350ASSIGN_ASSIGN1CALLS_H
#define CS350ASSIGN_ASSIGN1CALLS_H

#endif //CS350ASSIGN_ASSIGN1CALLS_H
