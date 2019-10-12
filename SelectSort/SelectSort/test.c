#define _CRT_SECURE_NO_WARNINGS 1
#include"selectSort.h"
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	printf("≈≈  –Ú  «∞£∫");
	Show(arr, arrLength);
	selectSort_1(arr, arrLength);
	printf("—°‘Ò≈≈–Ú∫Û£∫");
	Show(arr, arrLength);
	selectSort_2(arr, arrLength);
	printf("—°‘Ò≈≈–Ú∫Û£∫");
	Show(arr, arrLength);
}