#include "header.h"

static void intro_1() {
    char *intro1 = "Wake up , Neo..";
    refresh();
    for(unsigned int i = 0; i < mx_strlen(intro1); i++){        
        mvaddch(5, i + 4, intro1[i] | COLOR_PAIR(2));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
}

static void intro_2() {
    char *intro2 = "The Matrix has you..";
    for(unsigned int i = 0; i < mx_strlen(intro2); i++){
        mvaddch(5, i + 4, intro2[i] | COLOR_PAIR(2));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
}

static void intro_3() {
    char *intro3 = "Follow the white rabbit";
    for(unsigned int i = 0; i < mx_strlen(intro3); i++){      
        mvaddch(5, i + 4, intro3[i] | COLOR_PAIR(2));
        refresh();
        usleep(100000);
    }
    usleep(200000);
    clear();
    refresh();
}

static void intro_4() {
    char *intro4 = "Knock, knock, Neo";
    for(unsigned int i = 0; i < mx_strlen(intro4); i++){      
        mvaddch(5, i + 4, intro4[i] | COLOR_PAIR(2));
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
