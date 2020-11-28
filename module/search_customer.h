#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../struct/customer.h"

bool search(char *value) {
  curr_customer = head_customer[0];

  while(curr_customer) {
    if(strcmp(curr_customer->name, value) == 0) {
      return true;
    }
    curr_customer = curr_customer->next;
  }
  return false;
}

void search_cust(){
    Customer *key = (Customer*)malloc(sizeof(Customer));
    key->name = (char *)malloc(sizeof(char));
    printf("Insert the customer’s name to be searched: ");
    scanf("[^\n]", key->name);
    getchar();
    bool flag = search(key->name);
    if(flag == true) printf("%s is present", key->name);
    else printf("%s is not present", key->name);
    printf("Press enter to continue...");
    getchar();
}