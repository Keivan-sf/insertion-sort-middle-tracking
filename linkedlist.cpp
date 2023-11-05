#include <iostream>
#include "linkedlist.h"
using namespace std;

void print_linked_list(node* head) {
    node *current = head;
    while (current) {
        cout << current->value << ", ";
        current = current->next;
    }
    cout <<"\n";
}

int* convert_linked_list_to_array(node* head, int n) {
    int* array = new int[n];
    node* curr = head;
    for(int i = 0; curr != NULL; i++) {
        array[i] = curr->value;
        curr = curr -> next;
    }
    return array;
}
