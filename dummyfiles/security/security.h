#ifndef SECURITY_H
#define SECURITY_H

#include "../structs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *securityFiles[];
extern struct subMenu securityMenu;
extern void initSecurity();
extern void cleanSecurity();

#endif // SECURITY_H
