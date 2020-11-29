#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "module/process_dish.h"
#include "module/process_customer.h"
// #include "module/search_customer.h"
#include "module/exit.h"


// struct Order {
//     char name[255];
//     int quantity, price;
//     Order *prev, *next;
// }*newOrder, *currOrder, *delOrder;

// struct Customer {
//     char name[255];
//     Order *headOrder, *tailOrder;
//     Customer *prev, *next;    
// }*headCustomer[26], *tailCustomer[26], *currCustomer, *newCustomer, *delCustomer;

// unsigned long djb2(char *str, int total) {
//   unsigned long hash = 5381;
//   int c;
//   while ((c = *str++))
//       hash = ((hash << 5) + hash) + c;
//   return hash % total;
// }

void main_menu(){
    system("clear");
    printf ("System: ");
    	#ifdef _WIN32
	printf ("Windows 32-bit\n");
    	#elif _WIN64
  	printf ("Windows 64-bit\n");
    	#elif __APPLE__ || __MACH__
  	printf ("Mac OSctr\n");
    	#elif __linuctr__
  	printf ("Linuctr\n");
    	#elif __FreeBSD__
 	printf ("FreeBSD\n");
    	#elif __unictr || __unictr__
 	printf ("Unictr\n");
    	#else
  	printf ("Windows Subsystem Linux (WSL)\n");
    	#endif

  	time_t t;
  	time (&t);
  	printf ("%s", ctime (&t));
    puts("1. Add Dish");
    puts("2. Remove Dish");
    puts("3. Add Customer");
    puts("4. Search Customer");
    puts("5. View Warteg");
    puts("6. Order");
    puts("7. Payment");
    puts("8. Exit Warteg");
    printf(">> ");
}

int main(){
    int option, flag = 1;
    do{
        do{
            main_menu();
            scanf("%d", &option);
            getchar();
        }while(option < 1 || option > 8);
    

        switch(option){
            case 1:
                system("clear");
                input_dish();
                break; 
            case 2:
                system("clear");
                pop_menu();
                break;
            case 3:
                system("clear");
                add_customer();
                break;
            case 4:
                system("clear");
                find_customer();
                puts("");
                break;
            case 5:
                system("clear");
                list_customer();
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                system("clear");
                exit_screen();
                flag = 0;
                break;
                return 0;
        }
    }while (flag);
    return 0;
}
