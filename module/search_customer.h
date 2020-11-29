#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 30
// #include "../struct/customer.h"

Customer *find (char *key){
  for(int i = 0; i < MAX_ELEMENT; i++){
    if (head_customer[i])
    {
      Customer *curr_customer = head_customer[i];
      while(curr_customer){
        if(strcmp(key, curr_customer->name)){
                    Customer *info = (CustInfo*)malloc(sizeof(info));
                    strcpy(info->name, curr->name);
                    info->index = i;
                    return info;
        }
      }
    }
  }
}