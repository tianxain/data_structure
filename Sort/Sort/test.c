#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int arrLength = sizeof(arr) / sizeof(arr[0]);
	printf("��      ��      ǰ��");
	Show(arr, arrLength);
	printf("\n");

	//ð������
	BubbleSort_1(arr, arrLength);
	printf("ð������(��С����)��");
	Show(arr, arrLength);
	BubbleSort_2(arr, arrLength);
	printf("ð������(�Ӵ�С)��");
	Show(arr, arrLength);
	printf("\n");

	//ѡ������
	selectSort_1(arr, arrLength);
	printf("ѡ������(��С����)��");
	Show(arr, arrLength);
	selectSort_2(arr, arrLength);
	printf("ѡ������(�Ӵ�С)��");
	Show(arr, arrLength);
	printf("\n");

	//��������
	quickSort_1(arr, 0, arrLength - 1);
	printf("��������(��С����)��");
	Show(arr, arrLength);
	quickSort_2(arr, 0, arrLength - 1);
	printf("��������(�Ӵ�С)��");
	Show(arr, arrLength);
	printf("\n");
}