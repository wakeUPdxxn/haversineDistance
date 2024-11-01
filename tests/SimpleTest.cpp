#include <gtest/gtest.h>
#include "../include/haversine.hpp"

TEST(SimpleTest, RandomNumsTest) {
	EXPECT_EQ(
		float(6129859.5),
		float(haversineDistCount(65.83, 146.01, 39.37, 54.75))
	);
	EXPECT_EQ(
		float(3764262.25),
		float(haversineDistCount(-12.765964, 94.897381, 14.227647, 115.521271))
	);
	EXPECT_EQ(
		float(8160074.5),
		float(haversineDistCount(37.161179, 163.602411, 9.771900, 87.107417))
	);
}

TEST(SimpleFalseTest, wrongAnswerTest) {
	EXPECT_NE(
		100,
		haversineDistCount(32.161179, 150.602411, -1.771900, 60.107417)
	);
}