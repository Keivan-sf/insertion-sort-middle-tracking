#include <iostream>
using namespace::std;

struct node {
    int value;
    node *next = NULL;
    node *prev = NULL;
};

void print_linked_list(node* head) {
    node *current = head;
    while (current) {
        cout << current->value << ", ";
        current = current->next;
    }
    cout <<"\n";
}

node* insertion_sort_with_middle_tracking(int *array, int n) {
    int l = 0, r = 0;
    node *last = new(node);
    node *head = last;
    node *mid = last;

    last->value = *array;
    for(int i =1; i<n; i++) {
        int target = *(array + i);
        node *newNode = new(node);
        newNode -> value = target;
        if (target > mid->value) {
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
            if(r%2 == 0 && mid->next) mid = mid ->next;
            r++;
        } else {
            newNode -> next = head;
            head -> prev = newNode;
            node *current = head;
            node *placement = last;
            head = newNode;
            while(true) {
                if(current -> value > target) {
                    placement = current -> prev;
                    break;
                } else if(!(current -> next)) {
                    current -> prev -> value = current -> value;
                    break;
                } else {
                    current -> prev -> value = current -> value;
                    current = current -> next;
                }
            }
            placement->value = target;
            if(l%2 == 0 && mid->prev) mid = mid ->prev;
            l++;
        }
    }
    return head;
}
