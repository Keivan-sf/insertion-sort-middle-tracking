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

int insertion_sort_middle_tracking_array(int *array, int n) {
    int helper[n*2 - 1];
    int start = n - 1;
    int end = n - 1;
    helper[start] = array[0];
    for (int i = 1; i<n; i++) {
        int key = array[i];
        if(key > array[(start + end) / 2]) {
            helper[end + 1] = key;
            int j = end;
            end = end + 1;
            while(j > start - 1 && helper[j] > key) {
                helper[j + 1] = helper[j];
                j--;
            }
            helper[j+1] = key;
        } else {
            helper[start - 1] = key;
            int j = start;
            start = start - 1;
            while(j < end + 1 && helper[j] < key) {
                helper[j - 1] = helper[j];
                j++;
            }
            helper[j-1] = key;
        }

    }
    /* for(int i = 0; i < 2*n - 1; i++) { */
    /*     cout << helper[i] << ", "; */
    /* } */
    /* cout << endl; */
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
}

long date_time_in_ms() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

void populate_with_random_numbers(int *array, int n, int min, int max) {
    for(int i = 0; i<n; i++) {
        int random = min + rand() % max;
        array[i] = random;
    }
}

void populate_with_perfect_middletracking_input(int *array, int n) {
    /* int min, max; */
    /* int small[n/2]; */
    /* int big[n/2]; */
    /* populate_with_random_numbers(small, n/2, 0, 1000000); */
    /* populate_with_random_numbers(big, n/2, 1000001, 9999999); */
    /* insertion_sort(small, n/2); */
    /* insertion_sort(big, n/2); */
    /* for(int i = 0; i<n; i++) { */
    /*     if(i%2 == 0) { */
    /*         array[i] = small[i/2]; */
    /*     } else { */
    /*         array[i] = big[(i - 1) / 2]; */
    /*     } */
    /* } */
    int helper[n];
    populate_with_random_numbers(helper, n, 0, 1000000);
    insertion_sort(helper, n);
    for(int i=0; i<n; i++) {
        array[i] = helper[n - i -1];
    }
}

int main() {
    int array[100000];
    int n = 100000;
    int start, end;
    srand(date_time_in_ms() % 11);

    start = date_time_in_ms();
    populate_with_perfect_middletracking_input(array, n);
    end = date_time_in_ms();
    cout << "random number geneartion finished in: " << end - start << " ms" << endl;

    start = date_time_in_ms();
    insertion_sort_with_middle_tracking(array, n);
    end = date_time_in_ms();
    cout << "middle tracking finished in: " << end - start << " ms" << endl;

    start = date_time_in_ms();
    insertion_sort_middle_tracking_array(array, n);
    end = date_time_in_ms();
    cout << "middle tracking insertion sort with array finished in: " << end - start << " ms" << endl;

    start = date_time_in_ms();
    insertion_sort(array, n);
    end = date_time_in_ms();
    cout << "normal insertion sort finished in: " << end - start << " ms" << endl;

    /* int array[10] = {8, 100, 80, 81, 2, 99, 23, 3, -2, -1}; */
    /* int n = 10; */
    /* insertion_sort_with_middle_tracking(array, n); */
    /* int random = rand() % 1000; */
    return 0;
}
