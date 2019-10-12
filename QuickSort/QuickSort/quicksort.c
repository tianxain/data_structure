#define _CRT_SECURE_NO_WARNINGS 1
#include"quickSort.h"

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


//快速排序(从小到大)
void quickSort_1(int *arr, int left, int right)
{
	int i, j, temp;
	if (left >= right)
		return;
	temp = arr[left]; //temp中存的就是基准数
	i = left;
	j = right;
	while (i != j) 
	{ //顺序很重要，要先从右边开始找
		while (arr[j] >= temp && i < j)
			j--;
		while (arr[i] <= temp && i < j)//再找右边的
			i++;
		if (i < j)//交换两个数在数组中的位置
		{
			mySwap( &arr[i], &arr[j]);
		}
	}
	//最终将基准数归位
	arr[left] = arr[i];
	arr[i] = temp;
	quickSort_1(arr,left, i - 1);//继续处理左边的，这里是一个递归的过程
	quickSort_1(arr,i + 1, right);//继续处理右边的 ，这里是一个递归的过程
}

//快速排序(从大到小)
void quickSort_2(int *arr, int left, int right)
{
	int i, j, temp;
	if (left >= right)
		return;
	temp = arr[left]; //temp中存的就是基准数
	i = left;
	j = right;
	while (i != j)
	{ //顺序很重要，要先从右边开始找
		while (arr[j] <= temp && i < j)
			j--;
		while (arr[i] >= temp && i < j)//再找右边的
			i++;
		if (i < j)//交换两个数在数组中的位置
		{
			mySwap(&arr[i], &arr[j]);
		}
	}
	//最终将基准数归位
	arr[left] = arr[i];
	arr[i] = temp;
	quickSort_2(arr, left, i - 1);//继续处理左边的，这里是一个递归的过程
	quickSort_2(arr, i + 1, right);//继续处理右边的 ，这里是一个递归的过程
}
