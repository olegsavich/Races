#include "header.h"

void mx_randomize_char(int max_x, int max_y, int color, int arr[], int lenght[], int start[]) {
    for (int i = 0; i < max_x; i++) {       
            wchar_t random_char = (rand() % 93 + 33);
            if (i % 2 == 0) {
                random_char = ' ';
            }
            mvaddch(arr[i] + 1, i, random_char | COLOR_PAIR(2));      
            mvaddch(arr[i], i, random_char | COLOR_PAIR(color));
            mvaddch(arr[i] - lenght[i], i, ' ' | COLOR_PAIR(color));
            if (arr[i] - lenght[i] > max_y) {
                arr[i] = start[i];
            }
            arr[i]++;
        }

}
