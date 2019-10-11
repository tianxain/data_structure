#define _CRT_SECURE_NO_WARNINGS 1
#include"qsort.h"
void Show(int *arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//��ȡ������������ֵ
//NOTE: Ĭ��arr�ǿ�
int getMaxValue(const int *arr,int len)
{
	int max = *arr;
	int i = 0;
	for (i=0;i<len;i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

/*������������ֵ*/
void mySwap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//ð������(��С����)
void BubbleSort_1(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int flags = 0;
	for (i =0; i<len-1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			flags = 0;
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flags = 1;//��������ģ�flags����Ϊ1��
			}
		}
		if (flags == 0)
			return;

		/*for (j = i+1; j < len; j++)
		{
			if (arr[i] > arr[j]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}*/

	}
}

//ð������(�Ӵ�С)
void BubbleSort_2(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int flags = 0;
	for (i = 0; i < len-1; i++)
	{
		for (j = len - 2; j >= i ; j--)
		{
			flags = 0;
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flags = 1;//��������ģ�flags����Ϊ1��
			}
		}
		if (flags == 0)
			return ;
	}
}



/*ѡ������*/
void selectSort(int *arr, int bgn, int end)
{
	for (int i = bgn; i < end; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < end; ++j)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
			mySwap(&arr[i], &arr[minIndex]);
	}
}

/*����*/
void quickSort(int *arr, int bgn, int end)  //arr must be the reference of real param
{
	//����arr��or����һ��Ԫ�����˳�
	if (bgn >= end - 1)
		return;

	int lindex = bgn;
	int rindex = end - 1;
	int std = arr[lindex];
	while (lindex < rindex)
	{
		while (lindex < rindex)
		{
			if (arr[rindex] < std)
			{
				arr[lindex++] = arr[rindex];
				break;
			}
			--rindex;
		}

		while (lindex < rindex)
		{
			if (arr[lindex] >= std)
			{
				arr[rindex--] = arr[lindex];
				break;
			}
			++lindex;
		}
	}

	arr[lindex] = std;
	quickSort(arr, bgn, lindex);
	quickSort(arr, rindex + 1, end);
}

/*��������*/
void insertSort(int *arr, int bgn, int end)
{
	for (int i = bgn + 1; i < end; ++i)
	{
		/*
		* ��Ϊ1,2�����ִ�����������j = beg - 1ʱ�����
		* ����Ҫ��arr[i]���뵽��Ԫ��ǰ��λ�ã���ʹ��һ��for
		* �����������֣�����ڷ����������ʱ�˳�
		*/
		/*1*/
		int j = i - 1;
		for (; j >= bgn; --j)
			if (arr[j] <= arr[i])
				break;
		/*2*/
		if (j != i - 1)
		{
			int temp = arr[i];
			for (int k = i; k > j + 1; --k)
			{
				arr[k] = arr[k - 1];
			}
			arr[j + 1] = temp;
		}
	}
}


/*ϣ������*/
void shellSort(int *arr, int bgn, int end)
{
	for (int step = (end - bgn) / 2; step > 0; step /= 2)
	{
		for (int i = bgn; i < step; ++i)
		{
			/*
			* ���£�insertSort�ı���
			*/
			for (int j = i + step; j < end; j += step)
			{
				int k = j - step;
				for (; k >= i; k -= step)
					if (arr[k] <= arr[j])
						break;
				if (k != j - step)
				{
					int tmp = arr[j];
					for (int m = j; m > k + step; m -= step)
						arr[m] = arr[m - step];
					arr[k + step] = tmp;
				}
			}
		}
	}
}

/*Ͱ����*/
void bucketSort(int *arr)
{
	int max = getMaxValue(arr);
	int *pBuf = new int[max + 1];

	memset(pBuf, 0, (max + 1) * sizeof(int));
	for (auto const i : arr)
		++pBuf[i];

	for (int i = 0, j = 0; i <= max; ++i)
	{
		while (pBuf[i]--)
			arr[j++] = i;
	}
	delete[]pBuf;
}

/*��������*/
//1. �������򣬰�������ֵ��λ��������
void countSort(int *arr, int exp)
{
	int bucket[10] = { 0 };
	int arrSize = arr.size();
	int *pTemp = new int[arrSize];
	memset(pTemp, 0, arrSize * sizeof(int));

	//ͳ�Ƶ�λexp����ֵ����ֵ
	for (auto const val : arr)
		++bucket[(val / exp) % 10];

	//�����ֲ�
	for (int i = 1; i < 10; ++i)
		bucket[i] += bucket[i - 1];

	//��expλ��С������arrԪ�����pTemp
	for (int i = arrSize - 1; i >= 0; --i)
		pTemp[--bucket[(arr[i] / exp) % 10]] = arr[i];
	/*bugs*/
#if 0
	//bug1: bucket����εļ���ֵû����һ����Ӧ�Լ�1
	for (auto const val : arr)
		pTemp[bucket[(val / exp) % 10] - 1] = val;
	//bug2: arr����Ԫ��ÿ������ʱ���±�Ӧ�Ӵ�С�����������޷�ʵ������
	for (auto const val : arr)
		pTemp[--bucket[(val / exp) % 10]] = val;
#endif

	//pTemp -> arr
	for (int i = 0; i < arrSize; ++i)
		arr[i] = pTemp[i];
	delete[]pTemp;
}
//2. �ϲ�����λ����������
void radixSort(int *arr)
{
	int max = getMaxValue(arr);
	for (int exp = 1; max / exp != 0; exp *= 10)
		countSort(arr, exp);
}

/*�鲢����*/
//����������������
void mergeSortInOrder(int *arr, int bgn, int mid, int end)
{
	int *pBuf = new int[end - bgn];
	int *pTemp = pBuf;
	int lindex = bgn;
	int rindex = mid;

	while ((lindex < mid) && (rindex < end))
		*(pTemp++) = (arr[lindex] < arr[rindex]) ? arr[lindex++] : arr[rindex++];

	while (lindex < mid)
		*pTemp++ = arr[lindex++];
	while (rindex < end)
		*pTemp++ = arr[rindex++];

	//pTemp -> arr
	pTemp = pBuf;
	for (int i = bgn; i < end; i++)
		arr[i] = *pTemp++;

	delete[]pBuf;
}
//UpToDown To DownToUp
void mergeSort(int *arr, int bgn, int end)
{
	//����arr��or����һ��Ԫ�����˳�
	if (bgn >= end - 1)
		return;

	int mid = (bgn + end) / 2;
	mergeSort(arr, bgn, mid);
	mergeSort(arr, mid, end);
	mergeSortInOrder(arr, bgn, mid, end);
}

/*������*/
//���ڵ�Ԫ���Զ������ƶ������ʵ�λ���Թ�������
void downToMaxHeap(int *arr, int bgn, int end)
{
	int child;
	int parent = bgn;

	/*�ٸ��ڵ������ƶ������ʵ�λ�� --����������ĺ��Ĵ����*/
	while ((child = parent * 2 + 1) < end)
	{
		if ((child < end - 1) && (arr[child] < arr[child + 1]))
			++child;    //�Һ��ӽڵ�
		if (arr[child] > arr[parent])
			mySwap(&arr[child], &arr[parent]);
		else
			break;
		parent = child;
	}
}
//�����鹹��Ϊ����
void buildMaxHeap(int *arr, int bgn, int end)
{
	if (bgn >= end - 1)
		return;

	int parent = end / 2 - 1;
	while (parent >= 0)
	{
		downToMaxHeap(arr, parent, end);
		--parent;
	}
}
//������
void heapSort(int *arr, int bgn, int end)
{
	//��������
	buildMaxHeap(arr, bgn, end);

	while (end > 1)
	{
		mySwap(&arr[0], &arr[--end]);
		downToMaxHeap(arr, 0, end);
	}
}
