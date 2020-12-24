#ifndef HEADER_H
#define HEADER_H

#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

void mx_intro();
unsigned int mx_strlen(const char*);
void mx_initialize_color();
void mx_rain();
void mx_print_usage();
void mx_randomize_arr(int max_x, int start[], int arr[], int lenght[]);
void mx_randomize_char(int max_x, int max_y, int color, int arr[], int lenght[], int start[]);
void mx_change_speed_and_color(char ch, int speed, int color);

#endif
