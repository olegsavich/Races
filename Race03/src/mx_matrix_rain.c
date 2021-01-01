#include "../inc/header.h"

void mx_matrix_rain()
{
    mx_initialize_color();
    
    int maxY = 0, maxX = 0;    
    getmaxyx(stdscr, maxY, maxX);
    int start_arr[maxX];
    int lenght_arr[maxX];
    int arr[maxX];
    int speed = 100;
    int color = 2;
    mx_randomize_arr(maxX, start_arr, arr, lenght_arr);
    while (1) {
        
        mx_randomize_char(maxX, maxY, color, arr, lenght_arr, start_arr);
        usleep(1000 * speed);
        nodelay(stdscr,TRUE);
        noecho();
        char key = getch();
        if (key == 'q') 
        {
			clear();
			break;
		}
        switch (key) 
        {
            case '+':
                if (speed > 1) {
                    if (speed <= 11) {
                        speed--;
                    }
                    else {
                        speed -= 10;
                    }
                }
                break;
            case '-':
                if (speed < 300) {
                    if (speed <= 10) {
                            speed++;
                    }
                    else {
                        speed += 10;
                    }
                }
                break;
            case '0': 
                color = 1; 
                break;
            case '1': 
                color = 2; 
                break;
            case '2': 
                color = 3; 
                break;
            case '3': 
                color = 4; 
                break;
            case '4': 
                color = 5; 
                break;
            case '5': 
                color = 6; 
                break;
            case '6': 
                color = 7; 
                break;
            case '7': 
                color = 8; 
                break;
        }
        refresh();
    }
}
