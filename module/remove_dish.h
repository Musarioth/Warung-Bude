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
            printf("%d    %s        %.3d         %lld\n", i + 1, dish_curr->name, dish_curr->quantity, dish_curr->price);
            dish_curr = dish_curr->next;
        }
        sleep(1000);
    }
}

