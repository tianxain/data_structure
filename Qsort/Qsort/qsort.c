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

//冒泡排序(从小到大)
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
				flags = 1;//不是有序的，flags设置为1；
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

//冒泡排序(从大到小)
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
				flags = 1;//不是有序的，flags设置为1；
			}
		}
		if (flags == 0)
			return ;
	}
}
