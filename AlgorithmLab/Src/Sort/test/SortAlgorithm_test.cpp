#include "../../stdafx.h"
#include "../SortAlgorithm.h"
#include "SortAlgorithm_test.h"

void SortAlgorithmtest()
{
	int a[] = { 3 ,7, 9, 0, 5, 1, 6, 8, 4, 2, 0, 6, 1, 5, 7, 3, 4, 9, 8, 2 };

	//HeapSort(a, 4);
	SortAlgorithm sa;
	//sa.CountingSort(a,4,16);
	//sa.BubbleSort(a, 20);
	//sa.ShellSort2(a, 20);

	sa.ShellSortWithSedgewick(a, 20);

	for (size_t i = 0; i < 20; i++)
	{
		printf("%d   \n", a[i]);
	}
	printf("\n");
}