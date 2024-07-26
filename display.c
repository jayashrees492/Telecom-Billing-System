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