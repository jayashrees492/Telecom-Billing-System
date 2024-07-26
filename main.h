#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Customer {
    int id;
    char name[50];
    char phoneNumber[15];
    float balance;
};

void addCustomer(struct Customer customers[], int *numCustomers);
void makeCall(struct Customer customers[], int numCustomers);
void displayCustomerInfo(struct Customer customers[], int numCustomers);

#endif