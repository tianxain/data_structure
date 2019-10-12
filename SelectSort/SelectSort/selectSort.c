#define _CRT_SECURE_NO_WARNINGS 1
#include"selectSort.h"
//打印数组
void Show(int *arr, int len)
{

	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//交换两个整形值
void mySwap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//选择排序(从小到大)
void selectSort_1(int *arr,int len)
{
	int i = 0;
	int j = 0;
	for (int i =0; i < len; ++i)
	{
		int minIndex = i;
		// 找出最小值得元素下标
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
			mySwap(&arr[i], &arr[minIndex]);
	}
}

//选择排序(从大到小)
void selectSort_2(int *arr, int len)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++)
	{
		int maxIndex = i;
		// 找出最大值得元素下标
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[maxIndex])
			{
				maxIndex = j;
			}			
		}
		if (maxIndex != i)
			mySwap(&arr[i], &arr[maxIndex]);

	}
}