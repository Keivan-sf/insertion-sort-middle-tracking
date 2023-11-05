#ifndef linkedlist
#define linkedlist

#include <iostream>

struct node {
    int value;
    node *next = NULL;
    node *prev = NULL;
};

void print_linked_list(node* head);

#endif
