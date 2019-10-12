#define _CRT_SECURE_NO_WARNINGS 1
#include"selectSort.h"
//��ӡ����
void Show(int *arr, int len)
{

	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//������������ֵ
void mySwap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//ѡ������(��С����)
void selectSort_1(int *arr,int len)
{
	int i = 0;
	int j = 0;
	for (int i =0; i < len; ++i)
	{
		int minIndex = i;
		// �ҳ���Сֵ��Ԫ���±�
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
			mySwap(&arr[i], &arr[minIndex]);
	}
}

//ѡ������(�Ӵ�С)
void selectSort_2(int *arr, int len)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++)
	{
		int maxIndex = i;
		// �ҳ����ֵ��Ԫ���±�
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