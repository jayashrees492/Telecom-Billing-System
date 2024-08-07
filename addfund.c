#include <stdio.h>
#include "customer.h"

// Function to add funds to a customer's balance
void addFunds(struct Customer customers[], int numCustomers) {
    int customerId;
    float amount;

    printf("Enter customer ID: ");
    scanf("%d", &customerId);

    if (customerId < 1 || customerId > numCustomers) {
        printf("Invalid customer ID!\n");
        return;
    }

    printf("Enter amount to add: ");
    scanf("%f", &amount);

    customers[customerId - 1].balance += amount;

    printf("Funds added successfully!\n");
}
