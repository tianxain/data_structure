#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	printf("排      序      前：");
	Show(arr, arrLength);
	printf("\n");

	//冒泡排序
	BubbleSort_1(arr, arrLength);
	printf("冒泡排序(从小到大)：");
	Show(arr, arrLength);
	BubbleSort_2(arr, arrLength);
	printf("冒泡排序(从大到小)：");
	Show(arr, arrLength);
	printf("\n");

	//选择排序
	selectSort_1(arr, arrLength);
	printf("选择排序(从小到大)：");
	Show(arr, arrLength);
	selectSort_2(arr, arrLength);
	printf("选择排序(从大到小)：");
	Show(arr, arrLength);
	printf("\n");

	//快速排序
	quickSort_1(arr, 0, arrLength - 1);
	printf("快速排序(从小到大)：");
	Show(arr, arrLength);
	quickSort_2(arr, 0, arrLength - 1);
	printf("快速排序(从大到小)：");
	Show(arr, arrLength);
	printf("\n");
}