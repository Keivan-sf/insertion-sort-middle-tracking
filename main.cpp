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

int insertion_sort_with_middle_tracking(int *array, int n) {
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
    /* print_linked_list(head); */
    return 0;
}

int insertion_sort_reversed(int *array, int n) {
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
    }
    /* print_linked_list(head); */
    return 0;
}

int insertion_sort_with_linked_list(int *array, int n) {
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
    /* print_linked_list(head); */
    return 0;
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

int insertion_sort(int *array, int n) {
    for (int i = 1; i<n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j > -1 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    /* for (int i = 0; i < n; i++) { */
    /*     cout<< array[i] << " "; */
    /* } */
    return 0;
}

long date_time_in_ms() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

void populate_with_random_numbers(int *array, int n, int min, int max) {
    for(int i = 0; i<n; i++) {
        *(array + i) = min + rand() % max;
    }
}

int main() {
    int array[200000];
    int n = 200000;
    int start, end;
    srand(date_time_in_ms() % 11);

    start =date_time_in_ms();
    populate_with_random_numbers(array, n/2, 1, 1000000);
    populate_with_random_numbers(array + n/2, n/2, 1000001, 9999999);
    end = date_time_in_ms();
    cout << "random number geneartion finished in: " << end - start << " ms" << endl;

    start = date_time_in_ms();
    insertion_sort_with_middle_tracking(array, n);
    end = date_time_in_ms();
    cout << "middle tracking finished in: " << end - start << " ms" << endl;

    start = date_time_in_ms();
    insertion_sort_with_linked_list(array, n);
    end = date_time_in_ms();
    cout << "insertion sort with linked list finished in: " << end - start << " ms" << endl;

    start = date_time_in_ms();
    insertion_sort_out_of_place(array, n);
    end = date_time_in_ms();
    cout << "out-of-place insertion sort finished in: " << end - start << " ms" << endl;

    /* int array[10] = {8, 100, 80, 81, 2, 99, 23, 3, -2, -1}; */
    /* int n = 10; */
    /* insertion_sort_with_middle_tracking(array, n); */
    /* int random = rand() % 1000; */
    return 0;
}
