#define _CRT_SECURE_NO_WARNINGS 1
#include"insertSort.h"

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