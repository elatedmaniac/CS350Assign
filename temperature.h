//
// Created by Michael Austin on 2019-09-24.
//

#ifndef CS350ASSIGN_TEMPERATURE_H
#define CS350ASSIGN_TEMPERATURE_H

#include <stdio.h>

double celsius(double murica){
    double cels_conv = 5.0/9.0;
    double sub = murica-32.0;
    //printf("%f degrees Celsius\n",cels_conv*sub);
    return cels_conv*sub;
}

double fahrenheit(int cels){
    double f_conv = 9.0/5.0;
    double sum = (f_conv*cels)+32;
    //printf("%f\n",sum);
    return sum;
}

void charts(){
    printf("Celsius:\tFahrenheit:\n");
    for (int i =0;i<=100;i++){
        double fah = fahrenheit(i);
        printf("%d\t\t\t%f\n",i,fah);
    }
    printf("Fahrenheit:\tCelsius:\n");
    for (int i =32;i<=212;i++){
        double cel = celsius(i);
        printf("%d\t\t\t%f\n",i,cel);
    }
}

#endif //CS350ASSIGN_TEMPERATURE_H
