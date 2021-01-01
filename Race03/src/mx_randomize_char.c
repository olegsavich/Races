#include "../inc/header.h"

void mx_randomize_char(int maxX, int maxY, int color, int arr[], int lenght[], int start[]) {
    for (int i = 0; i < maxX; i++) {       
            wchar_t random_char = (rand() % 93 + 33);
            if (i % 2 == 0) {
                random_char = ' ';
            }
            mvaddch(arr[i] + 1, i, random_char | COLOR_PAIR(2));      
            mvaddch(arr[i], i, random_char | COLOR_PAIR(color));
            mvaddch(arr[i] - lenght[i], i, ' ' | COLOR_PAIR(color));
            if (arr[i] - lenght[i] > maxY) {
                arr[i] = start[i];
            }
            arr[i]++;
        }

}
