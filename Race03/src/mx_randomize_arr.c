#include "header.h"

void mx_randomize_arr(int max_x, int start[], int arr[], int lenght[]) {
    for (int i = 0; i < max_x; i++) {
        start[i] = -1 * (rand() % 80);
        arr[i] = start[i];
        lenght[i] = rand() % 50  - 1;
    }
}
