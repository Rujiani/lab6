#include <stdlib.h>
#include <stdio.h>

typedef struct item{
    struct item *previous;
    char *word;
    struct item *next;
}Item;

typedef struct list{
    Item *head;
    Item *tail;
}List;

#define MAX_WORD_LENGTH 100
List *list_new(){
    return (List *) calloc(1, sizeof(List)); 
}

void add_element(List *list, char *word_t){
    Item *ptr = malloc(sizeof(Item));
    ptr -> word = word_t;
    if(!(list->head)){
        list -> head = ptr;
        list -> tail = ptr;
    }
    else{
        ptr->previous = list->tail;
        list->tail->next = ptr;
        list->tail = ptr;
    }
}

void print_list(List *list){
    Item *n_element = list -> head;
    while(n_element){
        printf("%s ", n_element -> word);
        n_element = n_element -> next;
    }
    printf("\n");
}

void print_output_list(List *list){
    Item *n_element = list ->tail;
    while(n_element){
        printf("%s ", n_element -> word);
        n_element = n_element -> previous;
    }
    printf("\n");
}

void free_list(List *list){
    Item *n_element = list -> tail;
    while(n_element){
        free(n_element -> word);
        free(n_element -> next);
        n_element = n_element -> previous;
    }
    free(list->head);
    free(list);
}

void create_list(List *list){
    char currentchar;
    char *word = calloc(MAX_WORD_LENGTH, sizeof(char));
    int wordIndex = 0;
    while ((currentchar = getchar()) != '\n') {
        if (currentchar == ' ' || currentchar == '\t') {
            if (wordIndex > 0) {
                word[wordIndex] = '\0';
                add_element(list, word);
                wordIndex = 0;
                word = calloc(MAX_WORD_LENGTH, sizeof(char));
            }
            continue;
        }

        word[wordIndex++] = currentchar;

        if (wordIndex >= MAX_WORD_LENGTH - 1) {
            printf("ERROE VERY BIG WORD\n");
        }
    }

    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        add_element(list, word);
    }
    print_list(list);
    print_output_list(list);
}
