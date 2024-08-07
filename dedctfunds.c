#include <stdio.h>
#include "customer.h"

// Function to deduct funds from a customer's balance
void deductFunds(struct Customer customers[], int numCustomers) {
    int customerId;
    float amount;

    printf("Enter customer ID: ");
    scanf("%d", &customerId);

    if (customerId < 1 || customerId > numCustomers) {
        printf("Invalid customer ID!\n");
        return;
    }

    printf("Enter amount to deduct: ");
    scanf("%f", &amount);

    if (amount > customers[customerId - 1].balance) {
        printf("Insufficient balance!\n");
        return;
    }

    customers[customerId - 1].balance -= amount;

    printf("Funds deducted successfully!\n");
}
