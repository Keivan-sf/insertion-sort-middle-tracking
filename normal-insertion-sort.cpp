#include <iostream>
#include "linkedlist.h"
using namespace std;

node* insertion_sort_with_linked_list(int *array, int n) {
    node *last = new(node);
    node *head = last;
    last->value = array[0];
    for(int i =1; i<n; i++) {
        int target = array[i];
        node *newNode = new(node);
        newNode -> value = target;
        newNode -> prev = last;
        last -> next = newNode;
        node *current = last;
        node *placement = head;
        last = newNode;
        while(true) {
            if(current -> value <= target) {
                placement = current -> next;
                break;
            } else if(!(current -> prev)) {
                current -> next -> value = current -> value;
                break;
            } else {
                current -> next -> value = current -> value;
                current = current -> prev;
            }
        }
        placement->value = target;
    }
    return head;
}

int insertion_sort_out_of_place(int *array, int n) {
    int output_array[n];
    for (int i = 1; i<n; i++) {
        int key = array[i];
        output_array[i] = array[i];
        int j = i - 1;
        while (j > -1 && output_array[j] > key) {
            output_array[j + 1] = output_array[j];
            j--;
        }
        output_array[j + 1] = key;
    }
    return 0;
}

void insertion_sort(int *array, int n) {
    for (int i = 1; i<n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j > -1 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
