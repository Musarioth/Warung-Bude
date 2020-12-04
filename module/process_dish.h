#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../struct/dish.h"

void add_dish(Dish temp){ // create node dan push dish
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

void input_dish(){ // memberikan prompt
    Dish *temp_dish = (Dish*)malloc(sizeof(Dish));
    temp_dish->name = (char *)malloc(sizeof(char));
    bool flag = false;
    while (!flag){
        printf("Insert the name of the dish [Lowercase letters]: ");
        scanf("%[^\n]", temp_dish->name);
        getchar();
        bool valid = false;
        for (int i = 0; temp_dish->name[i] != '\0'; i++) {
            if (temp_dish->name[i] > 64 && temp_dish->name[i] < 91){
                valid = true;
            }
        }
        if (!valid){
            flag = true;
        }
    }
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

void print_list(){ // untuk print list dari dish (tidak mengerti cara padding)
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

bool search_and_delete(char *name){ // untuk mengecek apakah dish available dan untuk menghapus
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

void pop_menu (){ //memberi tampilan untuk menghapus nama dish
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
