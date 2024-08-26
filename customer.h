#ifndef CUSTOMER_H
#define CUSTOMER_H

// Structure to represent a customer
struct Customer {
    int id;
    char name[50];
    char phoneNumber[15];
    float balance;
};

// Function prototypes
void addCustomer(struct Customer customers[], int *numCustomers);
void displayCustomerInfo(struct Customer customers[], int numCustomers);
void addFunds(struct Customer customers[], int numCustomers);
void deductFunds(struct Customer customers[], int numCustomers);
void loadCustomers(struct Customer customers[], int *numCustomers);
void saveCustomers(struct Customer customers[], int numCustomers);

#endif
