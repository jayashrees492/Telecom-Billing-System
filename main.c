#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "add.c"
#include "addfunds.c"
#include "display.c"
#include "deductfunds.c"
#include "filehandling.c"

// Function to display menu options
void displayMenu() {
    printf("TELECOM BILLING SYSTEM\n");
    printf("-----------------------\n");
    printf("1. Add new customer\n");
    printf("2. Display customer information\n");
    printf("3. Add funds\n");
    printf("4. Deduct funds\n");
    printf("5. Exit\n");
}

// Function to get a valid choice from the user
int getValidChoice() {
    int choice;
    char ch;
    while (1) {
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) == 1) {
            ch = getchar();
            if (ch == '\n') {
                return choice;
            } else {
                printf("Invalid Choice. Please enter a valid option.\n");
                while (ch != '\n' && ch != EOF) {
                    ch = getchar();
                }
            }
        } else {
            printf("Invalid Choice. Please enter a valid option.\n");
            while (getchar() != '\n'); // Clear the input buffer
        }
    }
}

int main() {
    struct Customer customers[100]; // Assuming a maximum of 100 customers
    int numCustomers = 0;
    int choice;

    // Load customers from file at the start
    loadCustomers(customers, &numCustomers);

    do {
        displayMenu();
        choice = getValidChoice();

        switch (choice) {
            case 1:
                addCustomer(customers, &numCustomers);
                break;
            case 2:
                displayCustomerInfo(customers, numCustomers);
                break;
            case 3:
                addFunds(customers, numCustomers);
                break;
            case 4:
                deductFunds(customers, numCustomers);
                break;
            case 5:
                printf("Exiting...\n");
                // Save customers to file before exiting
                saveCustomers(customers, numCustomers);
                break;
            default:
                printf("Invalid Choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

