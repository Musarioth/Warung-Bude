#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
// #include "dish.h"

void pop_head_dish(){
    if(dish_head && dish_head == dish_tail){
        dish_head = dish_tail = NULL;
        free(dish_head);
       
    }
    else{
        Node_Dish *temp_head = dish_head->next;
        dish_head->next = temp_head->prev = NULL;
        free(dish_head);
        dish_head = temp_head;
    }   
}

void pop_tail_dish(){
    if(dish_tail && dish_tail == dish_head){
        dish_head = dish_tail = NULL;
        free(dish_head);

    }
    else{
        Node_Dish *temp_tail = dish_head->prev;
        dish_tail->prev = temp_tail->next = NULL;
        free(dish_tail);
        dish_tail = temp_tail;
    }
}

void print_list(){
    int i = 0;
    printf("%25s\n", "Bude's Menu");
    puts("=======================================");
    puts("No.    Nama       Quantity     Price");
    dish_curr = dish_head;
    if(!dish_curr){
        puts("No Dish available");
        puts("Press enter to continue...");
        getchar();
    }
    else{
        while(dish_curr){
            printf("%d    %s        %.3d         %lld\n", i + 1, dish_curr->dish.name, dish_curr->dish.quantity, dish_curr->dish.price);
            dish_curr = dish_curr->next;
        }
        // sleep(1000);
    }
}

bool search_and_delete(char *name){
    if(!dish_head){
        return false;

    }
    else if(strcmp(name, dish_head->dish.name) == 0){
        pop_head_dish();
        return true;
    }
    else if(strcmp(name, dish_tail->dish.name) == 0){
        pop_tail_dish();
        return true;
    }
    else{
        dish_curr == dish_head;
        while(dish_curr && strcmp(name, dish_curr ->dish.name) != 0){
            dish_curr = dish_curr->next;
        }
    }
}

void pop_menu (){
    dish_curr = dish_head;
    if(!dish_curr){
        puts("There is no available menu");
        printf("Press enter to continue...");
        getchar();
        return;
    }
    dish_curr = dish_head;
    print_list();
    bool deleted = false;
    char *temp_name = (char *)malloc(sizeof(char));
    while(!deleted){
        printf("Insert dish's name to be deleted: ");
        scanf("%[^\n]", temp_name);
        getchar();
        deleted =search_and_delete(temp_name);
    }
    free(temp_name);
    puts("The dish has been removed!");
    puts("Press enter to continue...");
    getchar();
}
