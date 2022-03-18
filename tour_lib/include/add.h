#ifndef ADD_H
#define ADD_H

typedef struct Results_t
{
	int number;
	int control_point;
	char* name;
	double time;
}res_t;

enum MenuItem
{
	ERROR = -1,
	END,
	ADD_NEW,
	SHOW_ALL,
	SHOW_TOP_10,
	EXIT,
	TOP = 10
};

int compare(const void* first, const void* second);

#endif