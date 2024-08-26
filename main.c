#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "add.c"
#include "addfund.c"
#include "display.c"
#include "dedctfunds.c"
#include "filehandling.c"

int main() {
    struct Customer customers[100]; // Assuming maximum 100 customers
    int numCustomers = 0;
    int choice;
    char input[10];

    do {
        printf("\nTelecom Billing System\n");
        printf("1. Add new customer\n");
        printf("2. Display customer information\n");
        printf("3. Add funds\n");
        printf("4. Deduct funds\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Check if input is a valid number
            if (sscanf(input, "%d", &choice) != 1) {
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
                continue;
            }

            switch(choice) {
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
                    break;
                default:
                    printf("Invalid choice! Please enter a number between 1 and 5.\n");
            }
        } else {
            printf("Error reading input.\n");
        }
    } while(choice != 5);

    return 0;
}

