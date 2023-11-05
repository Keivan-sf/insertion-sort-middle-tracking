#ifndef linkedlist
#define linkedlist

#include <iostream>

struct node {
    int value;
    node *next = NULL;
    node *prev = NULL;
};

void print_linked_list(node* head);
int* convert_linked_list_to_array(node* head, int n);

#endif
