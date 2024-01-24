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


List *list_new(){
    return (List *) calloc(1, sizeof(List)); 
}

char *create_word(){
    char *word = calloc(100, sizeof(char));
    char currentChar;
    int index = 0;
      while ((currentChar = getchar()) != '\n') {
          if((int)currentChar == -1){
              free(word);
              return NULL;
          }
            if (currentChar == ' ' || currentChar == '\t') {
            continue;
            }
            word[index] = currentChar;
            index++;
        }
    word[index] = '\0';
    return word;
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


void create_list(List *list){
    char *word = create_word();
    while(word){
        add_element(list, word);
        word = create_word();
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
