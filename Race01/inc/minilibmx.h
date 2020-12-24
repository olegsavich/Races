#ifndef CALC_H
#define CALC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#define NOT_INT -65535
#define INVALID_OPERATION 4
#define INVALID_OPERAND2 3
#define INVALID_OPERAND1 2
#define INVALID_RESULT 1

enum e_operation {
    ADD,
    SUB,
    MUL,
    DIV
};


bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_atoi(const char*);
void mx_printchar(char);
void mx_printint(int);
int mx_strncmp(const char*, const char*, int);
unsigned long mx_strlen(const char*);
char *mx_itoa(int);
char *mx_strnew(const int);
char *mx_strcpy(char*, const char*);
void mx_swap_char(char*, char*);
void mx_str_reverse(char*);
char *mx_strtrim(const char*);
char *mx_strndup(const char*, int);
char *mx_strncpy(char*, const char*, int);

#endif
