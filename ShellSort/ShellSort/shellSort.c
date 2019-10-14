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
int shellsort(int *arr, int len)    /* 自定义函数 shsort()*/
{
	int i, j, d;
	d = len / 2;    /*确定固定增虽值*/
	while (d >= 1)
	{
		for (i = d + 1; i <= len; i++)    /*数组下标从d+1开始进行直接插入排序*/
		{
			arr[0] = arr[i];    /*设置监视哨*/
			j = i - d;    /*确定要进行比较的元素的最右边位置*/
			while ((j > 0) && (arr[0] < arr[j]))
			{
				arr[j + d] = arr[j];    /*数据右移*/
				j = j - d;    /*向左移d个位置V*/
			}
			arr[j + d] = arr[0];    /*在确定的位罝插入s[i]*/
		}
		d = d / 2;    /*增里变为原来的一半*/
	}
	return 0;
}