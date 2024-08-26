#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "customer.h"

// Function to check if a string contains only alphabets
int isAlphabetic(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0; // Not alphabetic
        }
    }
    return 1; // All characters are alphabetic
}

// Function to check if a string contains exactly 10 digits
int isValidPhoneNumber(const char *str) {
    if (strlen(str) != 10) {
        return 0; // Not 10 digits long
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // Contains non-digit character
        }
    }
    return 1; // All characters are digits and length is 10
}

// Function to add a new customer
void addCustomer(struct Customer customers[], int *numCustomers) {
    struct Customer newCustomer;
    newCustomer.id = *numCustomers + 1;

    // Validate customer name
    do {
        printf("Enter customer name: ");
        scanf("%s", newCustomer.name);
        if (!isAlphabetic(newCustomer.name)) {
            printf("Invalid name. Please enter alphabets only.\n");
        }
    } while (!isAlphabetic(newCustomer.name));

    // Validate customer phone number
    do {
        printf("Enter customer phone number: ");
        scanf("%s", newCustomer.phoneNumber);
        if (!isValidPhoneNumber(newCustomer.phoneNumber)) {
            printf("Invalid phone number. Please enter a 10-digit number.\n");
        }
    } while (!isValidPhoneNumber(newCustomer.phoneNumber));

    newCustomer.balance = 0; // Initial balance

    customers[*numCustomers] = newCustomer;
    (*numCustomers)++;

    printf("Customer added successfully!\n");
}

