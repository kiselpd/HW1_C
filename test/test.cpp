#include <gtest/gtest.h>
#include <string>
#include <iostream>

extern "C" {
#include "add.h"
#include "tour.h"
}


TEST(TestCompare, variant1) {

	res_t first;
	res_t second;

	first.control_point = 20;
	second.control_point = 10;

	res_t* ptr_first = &first;
	res_t* ptr_second = &second;

	EXPECT_EQ(-10, compare(ptr_first, ptr_second));
	EXPECT_EQ(10, compare(ptr_second, ptr_first));

}

TEST(TestCompare, variant2) {

	res_t first;
	res_t second;

	first.control_point = 20;
	second.control_point = 20;
	first.time = 10;
	second.time = 20;

	res_t* ptr_first = &first;
	res_t* ptr_second = &second;

	EXPECT_EQ(-10, compare(ptr_first, ptr_second));
	EXPECT_EQ(10, compare(ptr_second, ptr_first));

}

TEST(TestMenuItem, CorrectInput) {

	const char* test = "1\n";

	FILE* stream = fmemopen((void*)test, strlen(test), "r"); 
	EXPECT_EQ(ADD_NEW, input_menu_item(stream));

	fclose(stream);
}

TEST(TestMenuItem, InCorrectInput) {

	const char* test = "sfbueb\n9\n3\n";

	FILE* stream = fmemopen((void*)test, strlen(test), "r");
	EXPECT_EQ(SHOW_TOP_10, input_menu_item(stream));

	fclose(stream);
}

TEST(Tournament, test1)
{
	const char* test = "1\n123\ntest_team\n123.123\n123\n4\n";

	FILE* stream = fmemopen((void*)test, strlen(test), "r");
	EXPECT_EQ(END, tournament(stream));

	fclose(stream);
}

TEST(Tournament, test2)
{
	const char* test = "1\n123\ntest team\n123.123\n123\n2\n\ntetert\n4\n";

	FILE* stream = fmemopen((void*)test, strlen(test), "r");
	EXPECT_EQ(END, tournament(stream));

	fclose(stream);
}

/*TEST(Tournament, test3)
{
	const char* test = "1\nshgbfbsfe\n123\ntest team\n123.3213\n313.31231\n123\n4\n";

	FILE* stream = fmemopen((void*)test, strlen(test), "r");
	EXPECT_EQ(END, tournament(stream));

	fclose(stream);
}*/



