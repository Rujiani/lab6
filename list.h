#ifndef LIST_H
#define LIST_H
typedef struct item{
    struct item *previous;
    char *word;
    struct item *next;
}Item;


typedef struct list{
    Item *head;
    Item *tail;
}List;

List *list_new();
int create_list(List *list);
void print_list(List *list);
void print_output_list(List *list);
void free_list(List *list);
#endif
