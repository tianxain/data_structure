#define _CRT_SECURE_NO_WARNINGS 1
#include"quickSort.h"
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	printf("��      ��      ǰ��");
	Show(arr, arrLength);
	quickSort_1(arr, 0, arrLength-1);
	printf("��������(��С����)��");
	Show(arr, arrLength);
	quickSort_2(arr, 0, arrLength - 1);
	printf("��������(�Ӵ�С)��");
	Show(arr, arrLength);
}