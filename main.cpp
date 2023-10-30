#include <iostream>
using namespace std;

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

int main() {
    int array[5] = {99, 23, 3, -2, -1};
    int n = 5;
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
        print_linked_list(head);
    }
    print_linked_list(head);
    return 0;
}

int main2() {
    int array[5] = {99, 23, 3, -2, 5};
    int n = 5;
    for (int i = 1; i<5; i++) {
        int key = array[i];
        int j = i - 1;
        while (j > -1 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    for (int i = 0; i < 5; i++) {
        cout<< array[i] << " ";
    }
    return 0;
}
