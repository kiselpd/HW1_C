#include <stdio.h>
#include "add.h"


int compare(const void* first, const void* second)
{
	const res_t* first_res = (const res_t*)first;
	const res_t* second_res = (const res_t*)second;

	if (first_res->control_point == second_res->control_point)
		return first_res->time - second_res->time;
	else
		return second_res->control_point - first_res->control_point;
}