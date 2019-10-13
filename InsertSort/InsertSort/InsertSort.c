#define _CRT_SECURE_NO_WARNINGS 1
#include"insertSort.h"

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

//ֱ�Ӳ�������(��С����)
void insertSort_1(int *arr, int len)
{
	int temp, i, j;
	for (i = 1; i < len; i++)
	{
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];          //��һ����ʱ������һ��
			for (j = i - 1; arr[j] > temp && j >= 0; j--) {
				arr[j + 1] = arr[j];                   //���±�i�������ľ�Ҫ���ƣ���Ϊ����������ں���

			}
			arr[j + 1] = temp;   //������Ҫע�����j+1����bug������  ->@@

		}
	}
}

//ֱ�Ӳ�������(�Ӵ�С)
void insertSort_2(int *arr, int len)
{
	int temp, i, j;
	for (i = 1; i < len; i++)
	{
		if (arr[i] > arr[i - 1]) {
			temp = arr[i];          //��һ����ʱ������һ��
			for (j = i - 1; arr[j] < temp && j >= 0; j--) {
				arr[j + 1] = arr[j];                   //���±�i�������ľ�Ҫ���ƣ���Ϊ����������ں���

			}
			arr[j + 1] = temp;   //������Ҫע�����j+1����bug������  ->@@

		}
	}

}

//�۰��������
void binaryInsertSort(int *arr, int len)
{
	int i, temp, j;
	int low, high, mid;
	for (i = 1; i < len; i++)
	{
		temp = arr[i]; //��Ҫ�����Ԫ�ؿ���һ��
		low = 0, high = i - 1;
		while (low <= high) //�ڣۣ죮������ݡ���Ѱ�Ҳ����λ��
		{
			mid = (low + high) / 2;  //�۰�
	   if (arr[mid] <= temp)
			   {
				  low = mid + 1;     //���ڸ߰��� 
		  }
		  else {
				   high = mid - 1;    //���ڵͰ���

}
		}
		for (j = i - 1; j >= high + 1; --j) //�ڳ�high+1��λ��
		{
			arr[j + 1] = arr[j];   //��¼����
		}
		arr[high + 1] = temp;

	}
}