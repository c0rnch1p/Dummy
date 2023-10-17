#ifndef NETWORKING_H
#define NETWORKING_H

#include "../structs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *networkingFiles[];
extern struct subMenu networkingMenu;
extern void initNetworking();
extern void cleanNetworking();

#endif // NETWORKING_H
