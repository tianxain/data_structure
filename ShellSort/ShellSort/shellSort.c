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
int shellsort(int *arr, int len)    /* �Զ��庯�� shsort()*/
{
	int i, j, d;
	d = len / 2;    /*ȷ���̶�����ֵ*/
	while (d >= 1)
	{
		for (i = d + 1; i <= len; i++)    /*�����±��d+1��ʼ����ֱ�Ӳ�������*/
		{
			arr[0] = arr[i];    /*���ü�����*/
			j = i - d;    /*ȷ��Ҫ���бȽϵ�Ԫ�ص����ұ�λ��*/
			while ((j > 0) && (arr[0] < arr[j]))
			{
				arr[j + d] = arr[j];    /*��������*/
				j = j - d;    /*������d��λ��V*/
			}
			arr[j + d] = arr[0];    /*��ȷ����λ�D����s[i]*/
		}
		d = d / 2;    /*�����Ϊԭ����һ��*/
	}
	return 0;
}