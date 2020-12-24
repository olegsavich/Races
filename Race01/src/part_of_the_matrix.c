#include "../inc/minilibmx.h"

int mx_pow(int num, int pow) {
    int temp = num;
    for (int i = 1; i < pow; i++)
        num *= temp;
    return num;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        write(2, "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n", 71);
        return -1;
    }
    int error = 0;

    // return  esli est' bol'she odnogo ne-probela
    char c_operation = '\0';
    for (int i = 0; i < (int)mx_strlen(argv[2]); i++) {
        if (!mx_isspace(argv[2][i]) && !c_operation)
            c_operation = argv[2][i];
        else if (!mx_isspace(argv[2][i]) && c_operation && error < INVALID_OPERATION)
            error = INVALID_OPERATION;
    }

    // initialize length of operands
    int a_length = mx_strlen(argv[1]);
    int b_length = mx_strlen(argv[3]);
    int c_length = mx_strlen(argv[4]);

    // zerofill operands in strings
    char *a_str = (char*)malloc(8 * a_length + 1);
    char *b_str = (char*)malloc(8 * b_length + 1);
    char *c_str = (char*)malloc(8 * c_length + 1);

    char *a_str_end = (char*)malloc(8 * a_length + 1);
    char *b_str_end = (char*)malloc(8 * b_length + 1);
    char *c_str_end = (char*)malloc(8 * c_length + 1);

    a_str_end[0] = '9';
    b_str_end[0] = '9';
    c_str_end[0] = '9';

    for (int i = 0; i < a_length; i++) {
        a_str[i] = '0';
        a_str_end[i] = '9';
    }
    a_str[a_length] = '\0';
    for (int i = 0; i < b_length; i++) {
        b_str[i] = '0';
        b_str_end[i] = '9';
    }
    b_str[b_length] = '\0';
    for (int i = 0; i < c_length; i++) {
        c_str[i] = '0';
        c_str_end[i] = '9';
    }
    c_str[c_length] = '\0';

    int *a_ranks = (int*)malloc(8 * a_length);
    int *b_ranks = (int*)malloc(8 * b_length);
    int *c_ranks = (int*)malloc(8 * c_length);

    int a_ranks_size = 0;
    int b_ranks_size = 0;
    int c_ranks_size = 0;

    // filling other characters
    char *a_operand = mx_strtrim(argv[1]);
    char *b_operand = mx_strtrim(argv[3]);
    char *c_operand = mx_strtrim(argv[4]);

    for (int i = 0; i < a_length; i++) {
        if (a_operand[i] == '?')
            a_ranks[a_ranks_size++] = i;
        else {
            a_str[i] = a_operand[i];
            a_str_end[i] = a_operand[i];
        }
    }
    for (int i = 0; i < b_length; i++) {
        if (b_operand[i] == '?')
            b_ranks[b_ranks_size++] = i;
        else {
            b_str[i] = b_operand[i];
            b_str_end[i] = b_operand[i];
        }
    }
    for (int i = 0; i < c_length; i++) {
        if (c_operand[i] == '?')
            c_ranks[c_ranks_size++] = i;
        else {
            c_str[i] = c_operand[i];
            c_str_end[i] = c_operand[i];
        }
    }
    
    int a_int_1 = mx_atoi(a_str);
    int b_int_1 = mx_atoi(b_str);
    int c_int_1 = mx_atoi(c_str);

    int a_int_2 = mx_atoi(a_str_end);
    int b_int_2 = mx_atoi(b_str_end);
    int c_int_2 = mx_atoi(c_str_end);
    
    if (a_int_1 == NOT_INT) {
        if (error < INVALID_OPERAND1)
            error = INVALID_OPERAND1;
    }
    if (b_int_1 == NOT_INT) {
        if (error < INVALID_OPERAND2)
            error = INVALID_OPERAND2;
    }
    if (c_int_1 == NOT_INT) {
        if (error < INVALID_RESULT)
            error = INVALID_RESULT;
    }
    
    enum e_operation operation;
    switch (c_operation) {
        case '+':
            operation = ADD;
            break;
        case '-':
            operation = SUB;
            break;
        case '*':
            operation = MUL;
            break;
        case '/':
            operation = DIV;
            break;
        default:
            if (error < INVALID_OPERATION)
                error = INVALID_OPERATION;
    }

    if (!error) {
        int a_start = mx_atoi(a_str);
        int b_start = mx_atoi(b_str);
        int c_start = mx_atoi(c_str);
        for (int a_count = a_start; a_count <= a_int_2; a_count++) {
            char *a_word = (char*)malloc(8 * a_ranks_size);
            a_word = mx_itoa(a_count);
            for (int ai = 0; ai < a_ranks_size; ai++) {
                a_str[a_ranks[ai]] = a_word[a_ranks[ai]];
            }
            // end of first number
            for (int b_count = b_start; b_count <= b_int_2; b_count++) {
                char *b_word = (char*)malloc(8 * b_ranks_size);
                b_word = mx_itoa(b_count);
                for (int bi = 0; bi < b_ranks_size; bi++) {
                    b_str[b_ranks[bi]] = b_word[b_ranks[bi]];
                }
                // end of second number
                for (int c_count = c_start; c_count <= c_int_2; c_count++) {
                    char *c_word = (char*)malloc(8 * c_ranks_size);
                    c_word = mx_itoa(c_count);

                    for (int ci = 0; ci < c_ranks_size; ci++)
                        c_str[c_ranks[ci]] = c_word[c_ranks[ci]];
                    int a = mx_atoi(a_str);
                    int b = mx_atoi(b_str);
                    int c = mx_atoi(c_str);

                    if (operation == ADD) {
                        if (a + b == c) {
                            write(1, a_str, a_length);
                            mx_printchar(' ');
                            mx_printchar('+');
                            mx_printchar(' ');
                            write(1, b_str, b_length);
                            mx_printchar(' ');
                            mx_printchar('=');
                            mx_printchar(' ');
                            write(1, c_str, c_length);
                            mx_printchar('\n');
                        }
                    }
                    else if (operation == SUB) {
                        if (a - b == c) {
                            write(1, a_str, a_length);
                            mx_printchar(' ');
                            mx_printchar('-');
                            mx_printchar(' ');
                            write(1, b_str, b_length);
                            mx_printchar(' ');
                            mx_printchar('=');
                            mx_printchar(' ');
                            write(1, c_str, c_length);
                            mx_printchar('\n');
                        }
                    }
                    else if (operation == MUL) {
                        if (a * b == c) {
                            write(1, a_str, a_length);
                            mx_printchar(' ');
                            mx_printchar('*');
                            mx_printchar(' ');
                            write(1, b_str, b_length);
                            mx_printchar(' ');
                            mx_printchar('=');
                            mx_printchar(' ');
                            write(1, c_str, c_length);
                            mx_printchar('\n');
                        }
                    }
                    else if (operation == DIV) {
                        if (b != 0)
                            if (a / b == c) {
                                write(1, a_str, a_length);
                                mx_printchar(' ');
                                mx_printchar('/');
                                mx_printchar(' ');
                                write(1, b_str, b_length);
                                mx_printchar(' ');
                                mx_printchar('=');
                                mx_printchar(' ');
                                write(1, c_str, c_length);
                                mx_printchar('\n');
                            }
                    }
                    free(c_word);
                }
                free(b_word);
            }
            free(a_word);
        }
    }
    free(a_ranks);
    free(b_ranks);
    free(c_ranks);
    free(a_str);
    free(b_str);
    free(c_str);
    free(a_str_end);
    free(b_str_end);
    free(c_str_end);
    free(a_operand);
    free(b_operand);
    free(c_operand);

    if (error)
        switch (error) {
            case 4:
                write(2, "Invalid operation: ", 19);
                write(2, argv[2], mx_strlen(argv[2]));
                mx_printchar('\n');
                break;
            case 3:
                write(2, "Invalid operand: ", 17);
                write(2, argv[3], mx_strlen(argv[3]));
                mx_printchar('\n');
                break;
            case 2:
                write(2, "Invalid operand: ", 17);
                write(2, argv[1], mx_strlen(argv[1]));
                mx_printchar('\n');
                break;
            case 1:
                write(2, "Invalid result: ", 16);
                write(2, argv[4], mx_strlen(argv[4]));
                mx_printchar('\n');
                break;
        }
}
