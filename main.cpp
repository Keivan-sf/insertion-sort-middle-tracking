#include <iostream>
using namespace std;

int main() {
    int array[5] = {99, 23, 3, -2, 5};
    int n = 5;
    cout << "hello" << endl;
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
}
