struct Order {
    char *name;
    int quantity, price;
    Order *prev, *next;
}*newOrder, *currOrder, *delOrder;

struct Customer {
     char *name;
     Order *headOrder, *tailOrder;
     Customer *prev, *next;    
}*head_customer[26], *tail_customer[26], *curr_customer, *new_customer, *del_customer;
