#define _CRT_SECURE_NO_WARNINGS 1
#include"qsort.h"
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

int int_cmp(const void * p1, const void * p2)
{
	return (*(int *)p1 - *(int *)p2);
}

void _swap(void *p1, void * p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		//一个字节一个字节的交换
		char tmp = *(((char *)p1) + i);
		*(((char *)p1) + i) = *(((char *)p2) + i);
		*(((char *)p2) + i) = tmp;
	}
}


//Qsort
void MyQsort(void *base, int count, int size, int(*cmp)(void *p1, void *p2))
{
	//冒泡排序
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (cmp((char *)base + j * size, (char *)base + (j + 1)*size) > 0)
			{
				_swap((char *)base + j * size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}