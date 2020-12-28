#ifndef HEADER_H
#define HEADER_H

//Libraries 
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

//Functions for matrix rain
void mx_intro(); //Makes intro with text on the screen
void mx_initialize_color(); //Initialization of colors 
void mx_matrix_rain(); //Function that prints matrix rain on the screen
void mx_randomize_arr(int maxX, int start[], int arr[], int lenght[]);
void mx_randomize_char(int maxX, int maxY, int color, int arr[], int lenght[], int start[]);
void mx_change_speed_and_color(char ch, int speed, int color);

//Technical functions
void mx_print_usage();
unsigned int mx_strlen(const char*); 

#endif
