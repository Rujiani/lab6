#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n');
}

int main(){
    printf("Print input lines\n");
    List *list = list_new();
    char input;
    do{
        input = getchar();
        switch(input){
            case '1':
                printf("Do 1 func\n");
                break;
            case '2':
                printf("Do 2 func\n");
                break;
            case '3':
               printf("New line\n");
                  break;
            }
    }while(input != -1); 
    free_list(list);
    return 0;
}
