#define _CRT_SECURE_NO_WARNINGS 1
#include"qsort.h"
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	//char *arr[] = {"aaaa","dddd","cccc","bbbb"}; 
	int i = 0;
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	printf("≈≈–Ú«∞£∫");
	Show(arr, arrLength);
	MyQsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	printf("≈≈–Ú∫Û£∫");
	Show(arr, arrLength);
	return 0;
}