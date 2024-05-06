#ifndef ASSETS_H
#define ASSETS_H

#include "../structs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *assetsFiles[];
extern struct subMenu assetsMenu;
extern void initAssets();
extern void cleanAssets();

#endif // ASSETS_H
