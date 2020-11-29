struct Order {
    char *name;
    int quantity, price;
    Order *prev, *next;
}*newOrder, *currOrder, *delOrder;

struct Customer {
     char *name;
     Order *headOrder, *tailOrder;
     Customer *prev, *next;    
}*head_customer[255], *tail_customer[255], *curr_customer, *new_customer, *del_customer;

