#include "../inc/header.h"

void mx_print_usage()
{
    const char* error = "usage: ./matrix_rain [-s]\n";
    write(2, error, mx_strlen(error));
}
