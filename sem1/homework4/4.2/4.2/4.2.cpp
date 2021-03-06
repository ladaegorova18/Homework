#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include "shellsort.h"
#include <assert.h>

void test(int *array)
{
	for (int i = 1; i < SIZE; i++)
	{
		assert(array[i] >= array[i - 1]);
	}
}

int main()
{
	FILE *file = fopen("array.txt", "r");
	if (!file)
	{
		printf("File not found!");
		return 0;
	}
	int *array = (int*)malloc(SIZE * sizeof(int));
	int i = 0;
	while (!feof(file))
	{
		fscanf(file, "%d ", &array[i]);
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	fclose(file);
	shellSort(array, 0, SIZE);
	test(array);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\nThe first most popular element is %d", maxRepeating(array, SIZE));
	free(array);
	return 0;
}
