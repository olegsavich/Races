#include "header.h"

void mx_randomize_arr(int maxX, int start[], int arr[], int lenght[]) {
    for (int i = 0; i < maxX; i++) {
        start[i] = -1 * (rand() % 80);
        arr[i] = start[i];
        lenght[i] = rand() % 50  - 1;
    }
}
