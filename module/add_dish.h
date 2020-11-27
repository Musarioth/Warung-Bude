#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dish.h"

void add_dish(Dish temp){
    Node_Dish *temp_node = (Node_Dish*)malloc(sizeof(Node_Dish));
    temp_node->dish = temp;
    temp_node->next = temp_node->prev = NULL;
    
    if(!dish_head){
        dish_head = dish_tail = temp_node;
    }
    else{
        dish_tail->next = temp_node;
        temp_node->prev = dish_tail;
        dish_tail = temp_node;
    }
}

void input_dish(){
    bool flag = true;
    Dish *temp_dish = (Dish*)malloc(sizeof(Dish));
    temp_dish->name = (char *)malloc(sizeof(char));
    do{
        printf("Insert the name of the dish [Lowercase letters]: ");
        scanf("%[^\n]", temp_dish->name);
        getchar();
        for(int i = 0; i != '\0'; i++){
            if(temp_dish->name[i] > 64 && temp_dish->name[i] < 91){
                flag = false;
                break;
            }
        }
    } while(flag == false);
    temp_dish->quantity = 0;
    temp_dish->price = 0;
    while(temp_dish->price < 1000 || temp_dish->price > 50000){
        printf("Insert the price of the dish [1000..50000]: ");
        scanf("%d", &temp_dish->price);
        getchar();
    }
    while(temp_dish->quantity < 1 || temp_dish->quantity > 999){
        printf("Insert the quantity of the dish [1..999]: ");
        scanf("%d", &temp_dish->quantity);
        getchar();
    }
    add_dish(*temp_dish);
    puts("");
    puts("The dish has been added!");
    puts("Press enter to continue... ");
    getchar();
}
