#include <iostream>
#include "linkedlist.h"
#include "./normal-insertion-sort/normal-insertion-sort.h"
#include "./middle-tracking/middle-tracking.h"
#include "./utils/utils.h"
using namespace std;

int main() {
    int array[30000];
    int n = 30000;
    int start, end;
    srand(date_time_in_ms() % 11);

    start = date_time_in_ms();
    /* populate_with_perfect_middletracking_input(array, n); */
    populate_with_perfect_insertionsort_input(array,n);
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
