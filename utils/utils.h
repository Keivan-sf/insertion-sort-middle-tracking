#ifndef main_utils
#define main_utils
#include <chrono>
#include <iostream>
#include "../normal-insertion-sort/normal-insertion-sort.h"

using namespace std;

long date_time_in_ms();

void populate_with_random_numbers(int *array, int n, int min, int max);

void populate_with_perfect_middletracking_input(int *array, int n);

void populate_with_perfect_insertionsort_input(int *array, int n);

#endif
