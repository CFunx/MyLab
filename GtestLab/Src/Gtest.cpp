#include <stdio.h>

#include "gtest/gtest.h"



GTEST_API_ int main(int argc, char **argv)
{
	printf("Running main() from gtest_main.cc\n");
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	getchar();
	return 0;	
}
