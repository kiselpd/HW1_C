#include <stdio.h>
#include <stdlib.h>
#include "add.h"
#include "tour.h"

res_t add_new(FILE* stream)
{
	res_t add_team;

	int input_int = ERROR;
	double input_double = ERROR;

	printf("Enter team number: ");
	do
	{
		char* str = NULL;
		size_t count = 0;
		getline(&str, &count, stream);
		char* end;

		input_int = strtol(str, &end, 10);
		if (*end != '\n')
		{
			input_int = ERROR;
			printf("Incorrect input. Return please: ");
		}

		free(str);
		str = NULL;
	} while (input_int == ERROR);
	add_team.number = input_int;

	printf("Enter team name: ");
	char* str = NULL;
	size_t count = 0;
	int len = getline(&str, &count, stdin);
	str[len - 1] = '\0';
	add_team.name = str;
	free(str);
	str = NULL;

	input_double = ERROR;
	printf("Enter time in minutes: ");
	do
	{
		char* str = NULL;
		size_t count = 0;
		getline(&str, &count, stream);
		char* end;

		input_double = strtod(str, &end);
		if (*end != '\n')
		{
			input_double = ERROR;
			printf("Incorrect input. Return please: ");
		}

		free(str);
		str = NULL;
	} while (input_double == ERROR);
	add_team.time = input_double;

	input_int = ERROR;
	printf("Enter number of control points: ");
	do
	{
		char* str = NULL;
		size_t count = 0;
		getline(&str, &count, stream);
		char* end;

		input_int = strtol(str, &end, 10);
		if (*end != '\n')
		{
			input_int = ERROR;
			printf("Incorrect input. Return please: ");
		}

		free(str);
		str = NULL;
	} while (input_int == ERROR);
	add_team.control_point = input_int;

	return add_team;
}

void show(res_t* team, int num_of_team)
{
	printf("Enter something to exit.\n\n");
	printf("|team number||         team name         || time in seconds ||control points|\n");
	for (size_t i = 0; i < 77; i++)
	{
		printf("-");
	}
	printf("\n");

	for (size_t i = 0; i < num_of_team; i++)
	{
		printf("|%10d || %25s || %15.4f || %13d|\n", team[i].number, team[i].name, team[i].time, team[i].control_point);
	}

	for (size_t i = 0; i < 77; i++)
	{
		printf("-");
	}
	printf("\n");

	while (getchar() != '\n');
}

int input_menu_item(FILE* stream)
{
	char* menu_item_str = NULL;
	size_t count_str = 0;
	int check_menu_item = 0;
	int menu_item = 0;

	do
	{
		check_menu_item = getline(&menu_item_str, &count_str, stream);
		
		if ((check_menu_item == 2) && (atoi(menu_item_str) <= EXIT) && (atoi(menu_item_str) >= END))
			menu_item = atoi(menu_item_str);
		else
			printf("Incorrect input. Return please: ");
		
	} while (!((check_menu_item == 2) && (atoi(menu_item_str) <= EXIT) && (atoi(menu_item_str) >= END)));

	free(menu_item_str);
	return menu_item;
}

int tournament(FILE* stream)
{
	int size_team = 1;
	int team_count = 0;
	res_t* team = (res_t*)malloc(sizeof(res_t) * size_team);
	int menu_item = END;

	do
	{
		printf("Choose option from menu:\n"
			"1.Add new team\n"
			"2.Show all team\n"
			"3.Show top 10 team\n"
			"4.Exit\n"
			"Enter menu_item:");

		menu_item = input_menu_item(stream);

		switch (menu_item) {

		case ADD_NEW:
			if (size_team == team_count)
			{
				size_team *= 2;
				res_t* tmp = (res_t*)realloc(team, sizeof(res_t) * size_team);
				if (tmp == NULL)
					perror("Memory allocation error: ");
				team = tmp;
				free(tmp);
			}
			team[team_count] = add_new(stream);
			team_count++;
			break;


		case SHOW_ALL:
			printf("All team. ");
			show(team, team_count);
			break;


		case SHOW_TOP_10:
			printf("Top 10 team. ");
			qsort(team, team_count, sizeof(res_t), compare);
			if (team_count < TOP)
				show(team, team_count);
			else
				show(team, TOP);
			break;

		case EXIT:
			for (size_t i = 0; i < team_count; i++)
			{
				free(team[i].name);
			}
			free(team);
			menu_item = END;
			break;
		
			default:
			for (size_t i = 0; i < team_count; i++)
			{
				free(team[i].name);
			}
			free(team);
			return ERROR;
		}

			
	} while (menu_item != END);

	return END;
}