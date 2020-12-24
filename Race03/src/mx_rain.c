#include "header.h"

void mx_rain()
{
    mx_initialize_color();
    
    int max_y = 0, max_x = 0;    
    getmaxyx(stdscr, max_y, max_x);
    int start[max_x];
    int lenght[max_x];
    int arr[max_x];
    int speed = 100;
    int color = 1;
    mx_randomize_arr(max_x, start, arr, lenght);
    while (1) {
        
        mx_randomize_char(max_x, max_y, color, arr, lenght, start);
        usleep(1000 * speed);
        nodelay(stdscr,TRUE);
        noecho();
        char ch = getch();
        if (ch == 'q') 
        {
			clear();
			break;
		}
        switch (ch) 
        {
            case '+':
                if (speed > 1) {
                    if (speed <= 11)
                        speed--;
                    else
                        speed -= 10;
                }
                break;
            case '-':
                if (speed < 300) {
                    if (speed <= 10)
                            speed++;
                        else
                            speed += 10;
                }
                break;
            case '0': color = 1; break;
            case '1': color = 2; break;
            case '2': color = 3; break;
            case '3': color = 4; break;
            case '4': color = 5; break;
            case '5': color = 6; break;
            case '6': color = 7; break;
            case '7': color = 8; break;
        }
        refresh();
    }
}
