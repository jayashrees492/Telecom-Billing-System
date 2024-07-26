// Function to make a call and update balance
void makeCall(struct Customer customers[], int numCustomers) {
    int customerId;
    int callDuration;
    
    printf("Enter customer ID: ");
    scanf("%d", &customerId);
    
    if (customerId < 1 || customerId > numCustomers) {
        printf("Invalid customer ID!\n");
        return;
    }
    
    printf("Enter call duration in minutes: ");
    scanf("%d", &callDuration);
    
    float callCost = callDuration * 0.50; // Assuming rate per minute is $0.50
    customers[customerId - 1].balance += callCost;
    
    printf("Call made successfully!\n");
}