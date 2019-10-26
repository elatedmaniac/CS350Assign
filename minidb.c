//
// Created by Syndikit on 10/24/2019.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants and utilities
char options[9][40] = {"1 Initialize the database", "2 Input new records","3 Search for a record", "4 Delete a record",
                       "5 List all the records", "6 List all records (sorted form)", "7 Save database", "8 Load an existing database", "9 Exit"};
char fname[] = "C:\\Users\\Syndikit\\CLionProjects\\CS350Assign\\database";
FILE *output;
FILE *input;

int num_entries = 0;
int curr_null = 0;
int curr_choice;

/*
 * Structure for each record. Record Number (int), Tool Name (string), Quantity (int), and Cost (double)
 * TutPoint Source: https://www.tutorialspoint.com/cprogramming/c_structures.htm
 */
typedef struct {
    int rec_num;
    char toolName[100];
    int quantity;
    double cost;
}Record;

Record db[100];

// Function prototypes
int getSelection();
void initializeDB();
void search();
void delete();
void print_head();
void list_entries();
void sorted_list();
void dbdemo();

/*
 * User input option we return to after each function call except exit.
 */
int getSelection(){
    printf("Please make a selection using a single digit, based on the following menu:\n");
    for(int i =0; i<9;i++){
        printf("%s\n",options[i]);
    }
    scanf("%d",&curr_choice);
    return curr_choice;
}
void initializeDB(){
    Record r;
    for(int i=0;i<100; i++){
        r.rec_num= i;
        strcpy(r.toolName , "NULL");
        r.quantity = 0;
        r.cost = 0.0;
        db[i]=r;
        num_entries += 1;
    }
    output = fopen(fname,"wb");
    for(int i = 0; i< 100; i++){
        if(output != NULL){

            fwrite(&db[i], sizeof(r),1, output);
        }

    }
    fclose(output);
    getSelection();

}
/*
 * Allows me to debug/ provides additional functionality for the database. Similar to the head() of Pandas in Python.
 * Prints off the first five records.
 * SO File I/O help: https://stackoverflow.com/questions/16997141/writing-structs-to-a-file-in-c
 * SO-2 File I/O: https://www.tutorialspoint.com/read-write-structure-to-a-file-using-c
 */
void print_head(){
    input = fopen(fname,"rb");
    Record rin;
    if(input==NULL){
        printf("\nError: No such file exists!\n");
        exit (1);
    }
    printf("Record\tTool Name\tQuantity\tCost\n");

    for(int i=0;i<5;i++){
        fread(&rin, sizeof(rin),1,input);
        printf("%d\t%s\t%d\t%f\n", rin.rec_num,rin.toolName,rin.quantity,rin.cost);
    }
    fclose(input);
}

void add(){

}

void search(){

}

void delete(){

}

void list_entries(){
    input = fopen(fname,"rb");
    Record rin;
    if(input==NULL){
        printf("\nError: No such file exists!\n");
        exit (1);
    }
    printf("Record\tTool Name\tQuantity\tCost\n");

    for(int i=0;i<num_entries;i++){
        fread(&rin, sizeof(rin),1,input);
        printf("%d\t%s\t%d\t%f\n", rin.rec_num,rin.toolName,rin.quantity,rin.cost);
    }
    fclose(input);
    dbdemo();
}

void sorted_list(){

}

void load(){

}

void exitdb(){

}

/*
* "1 Initialize the database", "2 Input new records","3 Search for a record",
 * "4 Delete a record", "5 List all the records", "6 List all records (sorted form)",
 * "7 Save database", "8 Load an existing database", "9 Exit"
*/
void dbdemo(){
    int select = getSelection();
    switch (select){
        case 1:
            initializeDB();
        case 2:
            add();
        case 3:
            search();
        case 4:
            delete();
        case 5:
            list_entries();
        case 6:
            list_entries();
        case 7:
            sorted_list();
        case 8:
            load();
        case 9:
            exitdb();
    }
    initializeDB();
    //print_head();
    //add();
}