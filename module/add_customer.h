#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../struct/customer.h"
Customer *createNode(char *name) {
  Customer *temp = (Customer*)malloc(sizeof(Customer));
  strcpy(temp->name, name);
  temp->next = NULL;
  return temp;
}

const int MAX_ELEMENT = 30;
unsigned long DJB2(char *str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
  return hash % MAX_ELEMENT;
}

void insert(char *str) {
  int index = DJB2(str);

  if(head_customer[index]) {
    Customer *temp = createNode(str);
    tail_customer[index]->next = temp;
    tail_customer[index] = temp;
  } 
  else {
    head_customer[index] = tail_customer[index] = createNode(str);
  }
}

void add_customer(){
    Customer *temp_cust = (Customer*)malloc(sizeof(Customer));
    temp_cust->name = (char *)malloc(sizeof(char));
    bool flag = false;
    while (!flag){
        printf("Insert the Customer's name [Without space]: ");
        scanf("%[^\n]", temp_cust->name);
        getchar();
        bool valid = false;
        for (int i = 0; temp_cust->name[i] != '\0'; i++){
            if (temp_cust->name[i] == ' '){
                valid = true;
            }
        }
        if (!valid){
            flag = true;
        }
    }
    insert(temp_cust->name);
    puts("Customer has been added!");
    printf("Press enter to continue...");
    getchar();
}