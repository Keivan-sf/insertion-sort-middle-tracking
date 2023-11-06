#include <chrono>
#include <iostream>
#include "../normal-insertion-sort/normal-insertion-sort.h"

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
