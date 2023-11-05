#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include "middle-tracking.h"
#include "linkedlist.h"
#include "normal-insertion-sort.h"

using namespace std;

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

void populate_with_perfect_insertionsort_input(int *array, int n) {
    populate_with_random_numbers(array, n, 0, 1000000);
    insertion_sort(array, n);
}

int main() {
    int array[300000];
    int n = 300000;
    int start, end;
    srand(date_time_in_ms() % 11);

    start = date_time_in_ms();
    populate_with_perfect_middletracking_input(array, n);
    /* populate_with_perfect_insertionsort_input(array,n); */
    /* populate_with_random_numbers(array, n, 0, 1000000); */
    end = date_time_in_ms();
    cout << "random number geneartion finished in: " << end - start << " ms" << endl;

    start = date_time_in_ms();
    node* head = insertion_sort_with_middle_tracking(array, n);
    end = date_time_in_ms();
    cout << "middle tracking finished in: " << end - start << " ms" << endl;

    int middle_tracking_time = end - start;

    start = date_time_in_ms();
    convert_linked_list_to_array(head,n);
    end = date_time_in_ms();
    cout << "middle tracking with array output finished in: " << middle_tracking_time + (end - start)<< " ms" << endl;

    start = date_time_in_ms();
    insertion_sort(array, n);
    end = date_time_in_ms();
    cout << "normal insertion sort finished in: " << end - start << " ms" << endl;

    return 0;
}
