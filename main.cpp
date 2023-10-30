#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <chrono>
#include <ctime>

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

long date_time_in_ms() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

int main() {
    int random = rand() % 1000;
    cout << random << endl;
}

int main232() {
    int array[9] = {100, 80, 81, 2, 99, 23, 3, -2, -1};
    int n = 9;
    int l = 0, r = 0;
    node *last = new(node);
    node *head = last;
    node *mid = last;

    last->value = array[0];
    for(int i =1; i<n; i++) {
        int target = array[i];
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
        print_linked_list(head);
        cout << "And the middle is = " << mid->value << "\n";
    }
    print_linked_list(head);
    return 0;
}

int main_reversed() {
    int array[5] = {99, 23, 3, -2, -1};
    int n = 5;
    node *last = new(node);
    node *head = last;
    last->value = array[0];
    for(int i =1; i<n; i++) {
        int target = array[i];
        node *newNode = new(node);
        newNode -> value = target;
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
        print_linked_list(head);
    }
    print_linked_list(head);
    return 0;
}

int main_linked_list() {
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
