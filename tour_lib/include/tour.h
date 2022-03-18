#ifndef TOUR_H
#define TOUR_H
#include <stdio.h>
#include "add.h"

res_t add_new(FILE* stream);

int input_menu_item(FILE* stream);

void show(res_t* team, int num_of_team);

int tournament(FILE* stream);

#endif