#ifndef MENUADMIN_H
#define MENUADMIN_H

#include <stdio.h>

typedef struct {
    char username[50];
    char password[50];
} Admin;


void menuadmin();
void gererprofileadmin();

#endif
