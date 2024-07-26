#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a customer
struct Customer {
    int id;
    char name[50];
    char phoneNumber[15];
    float balance;
};

// Function to add a new customer
void addCustomer(struct Customer customers[], int *numCustomers) {
    struct Customer newCustomer;
    newCustomer.id = *numCustomers + 1;
    
    printf("Enter customer name: ");
    scanf("%s", newCustomer.name);
    printf("Enter customer phone number: ");
    scanf("%s", newCustomer.phoneNumber);
    newCustomer.balance = 0; // Initial balance
    
    customers[*numCustomers] = newCustomer;
    (*numCustomers)++;
    
    printf("Customer added successfully!\n");
}

// Function to display customer information
void displayCustomerInfo(struct Customer customers[], int numCustomers) {
    int customerId;
    
    printf("Enter customer ID: ");
    scanf("%d", &customerId);
    
    if (customerId < 1 || customerId > numCustomers) {
        printf("Invalid customer ID!\n");
        return;
    }
    
    struct Customer customer = customers[customerId - 1];
    printf("Customer ID: %d\n", customer.id);
    printf("Name: %s\n", customer.name);
    printf("Phone Number: %s\n", customer.phoneNumber);
    printf("Balance: $%.2f\n", customer.balance);
}

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

// Function to display all customers
void displayAllCustomers(struct Customer customers[], int numCustomers) {
    if (numCustomers == 0) {
        printf("No customers to display!\n");
        return;
    }
    
    for (int i = 0; i < numCustomers; i++) {
        printf("\nCustomer ID: %d\n", customers[i].id);
        printf("Name: %s\n", customers[i].name);
        printf("Phone Number: %s\n", customers[i].phoneNumber);
        printf("Balance: $%.2f\n", customers[i].balance);
    }
}

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
        printf("5. Display all customers\n");
        printf("6. Exit\n");
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
                displayAllCustomers(customers, numCustomers);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 6);
    
    return 0;
}

