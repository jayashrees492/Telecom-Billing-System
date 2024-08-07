#ifndef CUSTOMER_H
#define CUSTOMER_H

// Structure to represent a customer
struct Customer {
    int id;
    char name[50];
    char phoneNumber[15];
    float balance;
};

void addCustomer(struct Customer customers[], int *numCustomers);
void displayCustomerInfo(struct Customer customers[], int numCustomers);
void addFunds(struct Customer customers[], int numCustomers);
void deductFunds(struct Customer customers[], int numCustomers);

#endif
