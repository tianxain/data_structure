#define _CRT_SECURE_NO_WARNINGS 1
#include"qsort.h"
void Show(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//ð������(��С����)
void BubbleSort_1(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int flags = 0;
	for (i =0; i<len-1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			flags = 0;
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flags = 1;//��������ģ�flags����Ϊ1��
			}
		}
		if (flags == 0)
			return;

		/*for (j = i+1; j < len; j++)
		{
			if (arr[i] > arr[j]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}*/

	}
}

//ð������(�Ӵ�С)
void BubbleSort_2(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int flags = 0;
	for (i = 0; i < len-1; i++)
	{
		for (j = len - 2; j >= i ; j--)
		{
			flags = 0;
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flags = 1;//��������ģ�flags����Ϊ1��
			}
		}
		if (flags == 0)
			return ;
	}
}
