struct Order {
    char name[255];
    int quantity, price;
    Order *prev, *next;
}*newOrder, *currOrder, *delOrder;

struct Customer {
     char name[255];
     Order *headOrder, *tailOrder;
     Customer *prev, *next;    
}*headCustomer[26], *tailCustomer[26], *currCustomer, *newCustomer, *delCustomer;
