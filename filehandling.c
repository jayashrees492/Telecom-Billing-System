#include <stdio.h>
#include "customer.h"

#define FILENAME "customers.dat"

// Function to load customers from a file
void loadCustomers(struct Customer customers[], int *numCustomers) {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        *numCustomers = 0;
        return;
    }

    *numCustomers = fread(customers, sizeof(struct Customer), 100, file);
    fclose(file);
}

// Function to save customers to a file
void saveCustomers(struct Customer customers[], int numCustomers) {
    FILE *file = fopen(FILENAME, "wb");
    if (!file) {
        printf("Error saving customers to file!\n");
        return;
    }

    fwrite(customers, sizeof(struct Customer), numCustomers, file);
    fclose(file);
}

