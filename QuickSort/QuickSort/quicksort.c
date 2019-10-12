#define _CRT_SECURE_NO_WARNINGS 1
#include"quickSort.h"

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


//��������(��С����)
void quickSort_1(int *arr, int left, int right)
{
	int i, j, temp;
	if (left >= right)
		return;
	temp = arr[left]; //temp�д�ľ��ǻ�׼��
	i = left;
	j = right;
	while (i != j) 
	{ //˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
		while (arr[j] >= temp && i < j)
			j--;
		while (arr[i] <= temp && i < j)//�����ұߵ�
			i++;
		if (i < j)//�����������������е�λ��
		{
			mySwap( &arr[i], &arr[j]);
		}
	}
	//���ս���׼����λ
	arr[left] = arr[i];
	arr[i] = temp;
	quickSort_1(arr,left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ���
	quickSort_1(arr,i + 1, right);//���������ұߵ� ��������һ���ݹ�Ĺ���
}

//��������(�Ӵ�С)
void quickSort_2(int *arr, int left, int right)
{
	int i, j, temp;
	if (left >= right)
		return;
	temp = arr[left]; //temp�д�ľ��ǻ�׼��
	i = left;
	j = right;
	while (i != j)
	{ //˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��
		while (arr[j] <= temp && i < j)
			j--;
		while (arr[i] >= temp && i < j)//�����ұߵ�
			i++;
		if (i < j)//�����������������е�λ��
		{
			mySwap(&arr[i], &arr[j]);
		}
	}
	//���ս���׼����λ
	arr[left] = arr[i];
	arr[i] = temp;
	quickSort_2(arr, left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ���
	quickSort_2(arr, i + 1, right);//���������ұߵ� ��������һ���ݹ�Ĺ���
}
