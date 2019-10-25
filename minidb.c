//
// Created by Syndikit on 10/24/2019.
//
#include <stdio.h>

char options[9][40] = {"1 Initialize the database", "2 Input new records","3 Search for a record", "4 Delete a record",
                       "5 List all the records", "6 List all records (sorted form)", "7 Save database", "8 Load an existing database", "9 Exit"};

struct record{
    int record;
    char toolName[30];
    int quantity;
    float cost;
};

