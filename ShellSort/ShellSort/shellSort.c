#define _CRT_SECURE_NO_WARNINGS 1
#include"shellSort.h"

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

//希尔排序
void shellSort(int *arr, int len)
{
	int increment = (len / 3) + 1;//初始化增量值
	int temp = 0;
	int i, j;
	for (increment ; increment > 0; increment = (increment / 3) + 1)
	{
		//以increment为间隔分组
		for ( i = 0; i < increment; i++)
		{
			//对每一个分组进行插入排序
			for (j = i + increment; j < len; j += increment)
			{
				if (arr[j] < arr[j - increment])
				{
					temp = arr[j];//哨兵
					int k = j - increment;
					while (k >= 0 && arr[k] > temp)
					{
						arr[k + increment] = arr[k];
						k = k - increment;
					}
					//把挪出来的空位，放入temp
					arr[k + increment] = temp;
				}
			}
		}
	}
}