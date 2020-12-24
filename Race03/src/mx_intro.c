#include "header.h"

void intro_1() {
    char *text1 = "Wake up , Neo..";
    refresh();
    for(unsigned int i = 0; i < mx_strlen(text1); i++){        
        mvaddch(5, i + 4, text1[i] | COLOR_PAIR(1));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
}

void intro_2() {
    char *text2 = "The Matrix has you..";
    for(unsigned int i = 0; i < mx_strlen(text2); i++){
        mvaddch(5, i + 4, text2[i] | COLOR_PAIR(1));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
}

void intro_3() {
    char *text3 = "Follow the white rabbit";
    for(unsigned int i = 0; i < mx_strlen(text3); i++){      
        mvaddch(5, i + 4, text3[i] | COLOR_PAIR(1));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
}

void intro_4() {
    char *text4 = "Knock, knock, Neo";
    for(unsigned int i = 0; i < mx_strlen(text4); i++){      
        mvaddch(5, i + 4, text4[i] | COLOR_PAIR(1));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
}

void mx_intro()
{
    initscr();
    mx_initialize_color();
    intro_1();
    intro_2();
    intro_3();
    intro_4();
    endwin();
}
