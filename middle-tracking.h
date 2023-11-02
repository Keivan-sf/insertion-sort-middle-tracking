#ifndef middletracking
#define middletracking

#include <iostream>

struct node {
    int value;
    node *next = NULL;
    node *prev = NULL;
};

node* insertion_sort_with_middle_tracking(int *array, int n);

#endif
