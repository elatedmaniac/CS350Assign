//
// Created by Syndikit on 10/24/2019.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
// Constants and utilities
char options[9][40] = {"1 Initialize the database", "2 Input new records","3 Search for a record", "4 Delete a record",
                       "5 List all the records", "6 List all records (sorted form)", "7 Save database", "8 Load an existing database", "9 Exit"};
FILE *output;
FILE *input;
char fname[20] = "database.bat";

typedef struct {
    int rec_num;
    char toolName[100];
    int quantity;
    double cost;
}Record;

Record db[100];

// Function prototypes
void initializeDB();
void print_head();
void dbdemo();

void initializeDB(){
    output = fopen(fname,"wb");

    int i;
    for(i=0;i<100; i++){
        Record r;
        r.rec_num= i;
        strcpy(r.toolName , "NULL");
        r.quantity = 0;
        r.cost = 0.0;
        fwrite(&r, sizeof(r),1, output);
    }
    fclose(output);
}

void print_head(){
    int i;
    input = fopen(fname,"rb");
    //Record *rin = malloc(sizeof(rin));
    Record rin;
    if(input==NULL){
        printf("\nError: No such file exists!\n");
        exit (1);
    }
    printf("Record\tTool Name\tQuantity\tCost\n");
    fread(&rin, sizeof(rin),1,input);
    for(i=0;i<5;i++){
        printf("%d\t%s\t%d\t%f\n", rin.rec_num,rin.toolName,rin.quantity,rin.cost);
    }
    fclose(input);
}

void dbdemo(){
    initializeDB();
    print_head();
}