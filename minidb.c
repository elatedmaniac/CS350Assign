//
// Created by Syndikit on 10/24/2019.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants and utilities
char options[9][40] = {"1 Initialize the database", "2 Input new records","3 Search for a record", "4 Delete a record",
                       "5 List all the records", "6 List all records (sorted form)", "7 Save database", "8 Load an existing database", "9 Exit"};
char fname[] = "CS350Assign\\database.dat";
FILE *output;
FILE *input;

int num_entries = 0;
int curr_choice =0;
int curr_rec = 0;

/*
 * Structure for each record. Record Number (int), Tool Name (string), Quantity (int), and Cost (double)
 * TutPoint Source: https://www.tutorialspoint.com/cprogramming/c_structures.htm
 */
typedef struct {
    int rec_num;
    char toolName[100];
    int quantity;
    float cost;
}Record;

Record db[1000];

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
    output = fopen(fname,"wb");
    Record r;
    for(int i=0;i<100; i++){
        r.rec_num= i;
        strcpy(r.toolName , "NULL");
        r.quantity = 0;
        r.cost = 0.0;
        db[i]=r;
        num_entries += 1;
        fwrite(&r, sizeof(Record),1,output);
    }

    fclose(output);
    //getSelection();

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
    Record new_r;

    //input = fopen(fname,"");

    printf("Enter the name of the tool:\n");
    scanf(" %s",new_r.toolName);
    printf("Enter the quantity:\n");
    scanf(" %d", &new_r.quantity);
    printf("Enter the cost:\n");
    scanf(" %f",&new_r.cost);
    if(curr_rec>99){
        new_r.rec_num = num_entries;
    }else{

        new_r.rec_num = curr_rec;

    }
    db[curr_rec] = new_r;
    for(int i=0;i<num_entries;i++){
        printf("%d\t%s\t%d\t%f\n", db[i].rec_num,db[i].toolName,db[i].quantity,db[i].cost);
    }
    num_entries+=1;
    output = fopen(fname,"wb");
    for(int i=0;i<num_entries; i++){
        fwrite(&db[i], sizeof(Record),1,output);
    }

    fclose(output);
    curr_rec +=1;




}
/*
 * Provides functionality for searching based on record number and tool name.
 */
void search(){
    char opt;
    printf("To search by tool ID, enter \'i\'.\nTo search by tool name, enter \'n\'.\n");
    scanf(" %c", &opt);
    if(opt != 'i' && opt != 'n'){
        printf("Error: that option is not available.");
        exit(1);
    }
    if(opt == 'i'){
        int num;
        printf("Enter the tool ID:\n");
        scanf("%d",&num);
        printf("%d\\t%s\\t%d\\t%f\\n", db[num].rec_num,db[num].toolName,db[num].quantity,db[num].cost);
    }
    if(opt == 'n'){
        char tname[100];
        int i;
        printf("What is the name of the tool?\n");
        scanf(" %s",&tname);
        for(i=0;i<num_entries;i++){
            if(strcmp(db[i].toolName,tname)==0){
                printf("%d\\t%s\\t%d\\t%f\\n", db[i].rec_num,db[i].toolName,db[i].quantity,db[i].cost);
            }else if(i==num_entries && strcmp(db[i].toolName,tname)!=0){
                printf("Tool could not be found. Sorry!\n");
            }
        }
    }

}

void delete(){
    int id, i;
    printf("What is the tool ID of the record you want to delete?\n");
    scanf(" %d",&id);
    for(i=(id-1);i<num_entries;i++){
        db[i] = db[i+1];
        db[i].rec_num -= 1;
    }
    num_entries -= 1;
    if(id<curr_rec){
        curr_rec -=1;
    }
    output = fopen(fname,"wb");
    for(int i=0;i<num_entries; i++){
        fwrite(&db[i], sizeof(Record),1,output);
    }

    fclose(output);



}

void list_entries(){
    input = fopen(fname,"rb");
    Record rin;
    if(input==NULL){
        printf("\nError: No such file exists!\n");
        exit (1);
    }
    for(int i=0;i<num_entries;i++){
        fread(&rin, sizeof(rin),1,input);
        printf("%d\t%s\t%d\t%f\n", rin.rec_num,rin.toolName,rin.quantity,rin.cost);
    }
    fclose(input);

}
/*
 * Sorting by name, by quantity, or by cost (dependent on user choice)
 */
void sorted_list(){
    char opt;
    int i,j;
    Record temp;
    printf("Please select \'n\' or \'q\' or \'c\' to sort by name, quantity, or cost, respectively.");
    scanf(" %c", &opt);

    if(opt=='n'){
        printf("Sorting by name.");

        for(i=1;i<num_entries;i++){
            for (j = 0; j < num_entries-i; ++j) {
                if(strcmp(db[j].toolName,db[j+1].toolName)>0 ){
                    temp = db[j];
                    db[j] = db[j+1];
                    db[j+1] = temp;
                }

            }
        }
        for(i=0;i<num_entries;i++){
            printf("%d\t%s\t%d\t%f\n", db[i].rec_num,db[i].toolName,db[i].quantity,db[i].cost);
        }


    }
    else if(opt=='q'){
        printf("Good");
        printf("Sorting by quantity.");

        for(i=1;i<num_entries;i++){
            for (j = 0; j < num_entries-i; ++j) {
                if(db[j].quantity > db[j+1].quantity){
                    temp = db[j];
                    db[j] = db[j+1];
                    db[j+1] = temp;
                }

            }
        }
        for(i=0;i<num_entries;i++){
            printf("%d\t%s\t%d\t%f\n", db[i].rec_num,db[i].toolName,db[i].quantity,db[i].cost);
        }


    }
    else if(opt=='c'){
        printf("Good");
        printf("Sorting by cost.");

        for(i=1;i<num_entries;i++){
            for (j = 0; j < num_entries-i; ++j) {
                if(db[j].cost > db[j+1].cost ){
                    temp = db[j];
                    db[j] = db[j+1];
                    db[j+1] = temp;
                }

            }
        }
        for(i=0;i<num_entries;i++){
            printf("%d\t%s\t%d\t%f\n", db[i].rec_num,db[i].toolName,db[i].quantity,db[i].cost);
        }



    }else{
        printf("Error: %c is not a valid option.\nSelect \'n\' or \'q\' or \'c\'.\n", opt);
    }
    getSelection();

}

void save(){
    Record r;
    output = fopen(fname,"wb");
    for(int i = 0; i< 100; i++){
        if(output != NULL){

            fwrite(&db[i], sizeof(r),1, output);
        }

    }
    fclose(output);

};

void load(){
    Record rec;
    char filename[40];
    FILE *fload;
    scanf(" %s",filename);
    fload = fopen(filename,"r");
    while(fscanf(fload,"%d %s %d %f", &rec.rec_num, rec.toolName, &rec.quantity, &rec.cost)!=EOF){
        db[rec.rec_num] = rec;
    }

}

void exitdb(){
    printf("Exiting...\n");
    exit(0);

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
            dbdemo();
        case 2:
            add();
            dbdemo();
        case 3:
            search();
            dbdemo();
        case 4:
            delete();
            dbdemo();
        case 5:
            list_entries();
            dbdemo();
        case 6:
            sorted_list();
            printf("Success!\n");
            dbdemo();
        case 7:
            save();
            dbdemo();
        case 8:
            load();
            dbdemo();
        case 9:
            exitdb();
            break;
    }

}