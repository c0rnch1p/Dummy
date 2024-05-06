#ifndef PACKAGES_H
#define PACKAGES_H

#include "../structs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *packagesFiles[];
extern struct subMenu packagesMenu;
extern void initPackages();
extern void cleanPackages();

#endif // PACKAGES_H
