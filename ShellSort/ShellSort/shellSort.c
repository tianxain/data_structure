#define _CRT_SECURE_NO_WARNINGS 1
#include"shellSort.h"

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

//ϣ������
void shellSort(int *arr, int len)
{
	int increment = (len / 3) + 1;//��ʼ������ֵ
	int temp = 0;
	int i, j;
	for (increment ; increment > 0; increment = (increment / 3) + 1)
	{
		//��incrementΪ�������
		for ( i = 0; i < increment; i++)
		{
			//��ÿһ��������в�������
			for (j = i + increment; j < len; j += increment)
			{
				if (arr[j] < arr[j - increment])
				{
					temp = arr[j];//�ڱ�
					int k = j - increment;
					while (k >= 0 && arr[k] > temp)
					{
						arr[k + increment] = arr[k];
						k = k - increment;
					}
					//��Ų�����Ŀ�λ������temp
					arr[k + increment] = temp;
				}
			}
		}
	}
}