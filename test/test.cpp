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

