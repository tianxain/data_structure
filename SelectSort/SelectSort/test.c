#define _CRT_SECURE_NO_WARNINGS 1
#include"selectSort.h"
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	printf("排  序  前：");
	Show(arr, arrLength);
	selectSort_1(arr, arrLength);
	printf("选择排序(从小到大)：");
	Show(arr, arrLength);
	selectSort_2(arr, arrLength);
	printf("选择排序(从大到小)：");
	Show(arr, arrLength);
}