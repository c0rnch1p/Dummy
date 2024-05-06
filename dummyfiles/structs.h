#ifndef STRUCTS_H
#define STRUCTS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subMenu{
    char *title;
    char **list;
    int size;
};

#endif // STRUCTS_H
