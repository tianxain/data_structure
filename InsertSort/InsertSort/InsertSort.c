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

//直接插入排序(从小到大)
void insertSort_1(int *arr, int len) 
{
	int temp, i, j;
	for (i = 1; i < len; i++)
	{
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];          //用一个临时变量存一下
			for (j = i - 1; arr[j] > temp && j >= 0; j--) {
				arr[j + 1] = arr[j];                   //凡事比i这个数大的就要后移，因为大的数总是在后面

			}
			arr[j + 1] = temp;   //这里需要注意的是j+1，调bug好累勒  ->@@

		}
	}
}

//直接插入排序(从大到小)
void insertSort_2(int *arr, int len)
{
	int temp, i, j;
	for (i = 1; i < len; i++)
	{
		if (arr[i] > arr[i - 1]) {
			temp = arr[i];          //用一个临时变量存一下
			for (j = i - 1; arr[j] < temp && j >= 0; j--) {
				arr[j + 1] = arr[j];                   //凡事比i这个数大的就要后移，因为大的数总是在后面

			}
			arr[j + 1] = temp;   //这里需要注意的是j+1，调bug好累勒  ->@@

		}
	}

}

//折半插入排序
void binaryInsertSort(int *arr, int len)
{
	int i, j, temp;
	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		int low, high, mid;
	}
}