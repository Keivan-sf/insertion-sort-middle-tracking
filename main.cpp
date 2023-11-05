#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include "middle-tracking.h"

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
    insertion_sort(array, n);
    end = date_time_in_ms();
    cout << "normal insertion sort finished in: " << end - start << " ms" << endl;

    return 0;
}
