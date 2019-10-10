#define _CRT_SECURE_NO_WARNINGS 1
#include"qsort.h"
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	BubbleSort_1(arr, arrLength);
	Show(arr, arrLength);
	BubbleSort_2(arr, arrLength);
	Show(arr, arrLength);
	return 0;
}