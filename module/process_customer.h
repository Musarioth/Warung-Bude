#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../struct/customer.h"
#define MAX_ELEMENT 255

struct Customer_Info{
  char *name;
  int index;
};

struct Order_Info
{
  char *name;
  long int amount;
};


unsigned long DJB2(char *str) { // untuk memberikan index random
  unsigned long hash = 5381;
  int c;
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
  return hash % MAX_ELEMENT;
}

void add_customer(){ // prompt add customer
  Customer *temp_cust = (Customer *)malloc(sizeof(Customer));
  temp_cust->name = (char*)malloc(sizeof(char));
  temp_cust->next = NULL;
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
  int index = DJB2(temp_cust->name);
  if(head_customer[index]) {
    tail_customer[index]->next = temp_cust;
    tail_customer[index] = temp_cust;
  } 
  else {
    head_customer[index] = tail_customer[index] = temp_cust;
  }
  puts("Customer has been added!");
  printf("Press enter to continue...");
  getchar();
}

Customer_Info *find(char *key){ //mengecek apakah ada customer atau tidak
  for(int i = 0; i < MAX_ELEMENT; i++){
    if(head_customer[i]){
      curr_customer = head_customer[i];
      while(curr_customer){
        if(strcmp(key, curr_customer->name) == 0){
          Customer_Info *info = (Customer_Info *)malloc(sizeof(Customer_Info));
          strcpy(info->name, curr_customer->name);
          info->index = i;
          return info;
        }
        curr_customer = curr_customer->next;
      }
    }
  }
  return NULL;
}


void find_customer(){ //untuk mencari customer (prompt)
  bool flag = false;
  char *target = (char *)malloc(sizeof(char));
  while (!flag){
    printf("Insert the customer’s name to be searched: ");
    scanf("%[^\n]", target);
    getchar();
    bool valid = false;
    for (int i = 0; target[i] != '\0'; i++){
      if (target[i] == ' '){
        valid = true;
        }
      }
    if (!valid){
      flag = true;
    }
  }
  Customer_Info *result = find(target);
  if(result){
    printf("%s is present with customer's ID: %d.\n", result->name, result->index);
    printf("Press enter to continue...");
    getchar();
    // free(result);
  }
  else if(!result){ // bila tidak ada customer maka akan terjadi segmentation fault
    printf("%s is not present.\n", result->name);
    printf("Press enter to continue...");
    getchar();
  }
  // free(target);
  // printf("Press enter to continue...");
  // getchar();
}

void list_customer() { // menampilkan list customer
    puts("Customer’s List");
    for (int i = 0; i < MAX_ELEMENT; i++) {
        if (head_customer[i]) {
            curr_customer = head_customer[i];
            while (curr_customer) {
                printf("%d. %s\n", i, curr_customer->name);
                curr_customer = curr_customer->next;
            }
        }
    }
    puts("");
    puts("Press enter to continue...");
    getchar();
}