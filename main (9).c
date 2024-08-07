#include <stdio.h>
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

    do {
        printf("\nTelecom Billing System\n");
        printf("1. Add new customer\n");
        printf("2. Display customer information\n");
        printf("3. Add funds\n");
        printf("4. Deduct funds\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}
