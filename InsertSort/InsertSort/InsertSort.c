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
	int i, temp, j;
	int low, high, mid;
	for (i = 1; i < len; i++)
	{
		temp = arr[i]; //将要插入的元素拷贝一份
		low = 0, high = i - 1;
		while (low <= high) //在［ｌ．．．ｈ］　中寻找插入的位置
		{
			mid = (low + high) / 2;  //折半
	   if (arr[mid] <= temp)
			   {
				  low = mid + 1;     //插在高半区 
		  }
		  else {
				   high = mid - 1;    //插在低半区

}
		}
		for (j = i - 1; j >= high + 1; --j) //腾出high+1的位置
		{
			arr[j + 1] = arr[j];   //记录后移
		}
		arr[high + 1] = temp;

	}
}