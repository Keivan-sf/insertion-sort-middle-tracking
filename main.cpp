#include <iostream>
#include "linkedlist.h"
#include "./normal-insertion-sort/normal-insertion-sort.h"
#include "./middle-tracking/middle-tracking.h"
#include "./utils/utils.h"
using namespace std;

int main() {
    cout << "Processing...\n\n";
    int array[30000];
    int n = 30000;
    int start, end;
    srand(date_time_in_ms() % 11);

    start = date_time_in_ms();
    populate_with_perfect_insertionsort_input(array,n);
    end = date_time_in_ms();
    long random_number_generation_time = end - start;

    start = date_time_in_ms();
    node* head = insertion_sort_with_middle_tracking(array, n);
    end = date_time_in_ms();
    long middle_tracking_time = end - start;

    start = date_time_in_ms();
    convert_linked_list_to_array(head,n);
    end = date_time_in_ms();
    long middle_tracking_array_convertion_time = middle_tracking_time + (end - start);

    start = date_time_in_ms();
    insertion_sort(array, n);
    end = date_time_in_ms();
    long normal_insertion_sort_time = end - start;

    cout << "Normal insertion-sort " << normal_insertion_sort_time << " ms\n\n";
    cout << "Middle-tracking: " << middle_tracking_time << " ms\n\n";
    cout << "Middle-tracking with array conversion: " << middle_tracking_array_convertion_time << " ms\n\n";
    cout << "Input generation: " << random_number_generation_time << " ms\n";

    return 0;
}
