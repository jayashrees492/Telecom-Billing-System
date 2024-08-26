#include <stdio.h>
#include "customer.h"

// Function to deduct funds from a customer's balance in Indian Rupees
void deductFunds(struct Customer customers[], int numCustomers) {
    int customerId;
    float amount;

    printf("Enter customer ID: ");
    scanf("%d", &customerId);

    if (customerId < 1 || customerId > numCustomers) {
        printf("Invalid customer ID!\n");
        return;
    }

    printf("Enter amount to deduct (in INR): Rs.");
    scanf("%f", &amount);

    if (amount < 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    if (amount > customers[customerId - 1].balance) {
        printf("Insufficient balance!\n");
        return;
    }

    customers[customerId - 1].balance -= amount;

    printf("Rs%.2f deducted successfully from customer ID %d's account!\n", amount, customerId);
    printf("Current balance: Rs%.2f\n", customers[customerId - 1].balance);
}

