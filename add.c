

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