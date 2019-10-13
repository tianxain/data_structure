#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
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

//获取整形数组的最大值
//NOTE: 默认arr非空
int getMaxValue(const int *arr, int len)
{
	int max = *arr;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

//交换两个整形值
void mySwap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//冒泡排序(从小到大)
void BubbleSort_1(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int flags = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			flags = 0;
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flags = 1;//不是有序的，flags设置为1；
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



//冒泡排序(从大到小)
void BubbleSort_2(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int flags = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = len - 2; j >= i; j--)
		{
			flags = 0;
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flags = 1;//不是有序的，flags设置为1；
			}
		}
		if (flags == 0)
			return;
	}
}



//选择排序(从小到大)
void selectSort_1(int *arr, int len)
{
	int i = 0;
	int j = 0;
	for (int i = 0; i < len; ++i)
	{
		int minIndex = i;
		// 找出最小值得元素下标
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
			mySwap(&arr[i], &arr[minIndex]);
	}
}

//选择排序(从大到小)
void selectSort_2(int *arr, int len)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++)
	{
		int maxIndex = i;
		// 找出最大值得元素下标
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] > arr[maxIndex])
			{
				maxIndex = j;
			}
		}
		if (maxIndex != i)
			mySwap(&arr[i], &arr[maxIndex]);

	}
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
			mySwap(&arr[i], &arr[j]);
		}
	}
	//最终将基准数归位
	arr[left] = arr[i];
	arr[i] = temp;
	quickSort_1(arr, left, i - 1);//继续处理左边的，这里是一个递归的过程
	quickSort_1(arr, i + 1, right);//继续处理右边的 ，这里是一个递归的过程
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

//插入排序
void insertSort(int *arr, int bgn, int end)
{
	for (int i = bgn + 1; i < end; ++i)
	{
		// 分为1,2两部分处理，可以囊括j = beg - 1时的情况
		// 即需要将arr[i]插入到首元素前的位置，若使用一个for
		// 包括这两部分，则会在发生这种情况时退出

		//第一部分
		int j = i - 1;
		for (; j >= bgn; --j)
			if (arr[j] <= arr[i])
				break;
		//第二部分
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


///*希尔排序*/
//void shellSort(int *arr, int bgn, int end)
//{
//	for (int step = (end - bgn) / 2; step > 0; step /= 2)
//	{
//		for (int i = bgn; i < step; ++i)
//		{
//			/*
//			* 以下，insertSort的变异
//			*/
//			for (int j = i + step; j < end; j += step)
//			{
//				int k = j - step;
//				for (; k >= i; k -= step)
//					if (arr[k] <= arr[j])
//						break;
//				if (k != j - step)
//				{
//					int tmp = arr[j];
//					for (int m = j; m > k + step; m -= step)
//						arr[m] = arr[m - step];
//					arr[k + step] = tmp;
//				}
//			}
//		}
//	}
//}
//
///*桶排序*/
//void bucketSort(int *arr)
//{
//	int max = getMaxValue(arr);
//	int *pBuf = new int[max + 1];
//
//	memset(pBuf, 0, (max + 1) * sizeof(int));
//	for (auto const i : arr)
//		++pBuf[i];
//
//	for (int i = 0, j = 0; i <= max; ++i)
//	{
//		while (pBuf[i]--)
//			arr[j++] = i;
//	}
//	delete[]pBuf;
//}
//
///*基数排序*/
////1. 计数排序，按整形数值单位进行排序
//void countSort(int *arr, int exp)
//{
//	int bucket[10] = { 0 };
//	int arrSize = arr.size();
//	int *pTemp = new int[arrSize];
//	memset(pTemp, 0, arrSize * sizeof(int));
//
//	//统计单位exp各数值计数值
//	for (auto const val : arr)
//		++bucket[(val / exp) % 10];
//
//	//计数分层
//	for (int i = 1; i < 10; ++i)
//		bucket[i] += bucket[i - 1];
//
//	//按exp位大小用数组arr元素填充pTemp
//	for (int i = arrSize - 1; i >= 0; --i)
//		pTemp[--bucket[(arr[i] / exp) % 10]] = arr[i];
//	/*bugs*/
//#if 0
//	//bug1: bucket各层次的计数值没遍历一次相应自减1
//	for (auto const val : arr)
//		pTemp[bucket[(val / exp) % 10] - 1] = val;
//	//bug2: arr数组元素每次排序时，下标应从大到小遍历，否则无法实现排序
//	for (auto const val : arr)
//		pTemp[--bucket[(val / exp) % 10]] = val;
//#endif
//
//	//pTemp -> arr
//	for (int i = 0; i < arrSize; ++i)
//		arr[i] = pTemp[i];
//	delete[]pTemp;
//}
////2. 合并各单位计数排序结果
//void radixSort(int *arr)
//{
//	int max = getMaxValue(arr);
//	for (int exp = 1; max / exp != 0; exp *= 10)
//		countSort(arr, exp);
//}
//
///*归并排序*/
////排序两个有序数列
//void mergeSortInOrder(int *arr, int bgn, int mid, int end)
//{
//	int *pBuf = new int[end - bgn];
//	int *pTemp = pBuf;
//	int lindex = bgn;
//	int rindex = mid;
//
//	while ((lindex < mid) && (rindex < end))
//		*(pTemp++) = (arr[lindex] < arr[rindex]) ? arr[lindex++] : arr[rindex++];
//
//	while (lindex < mid)
//		*pTemp++ = arr[lindex++];
//	while (rindex < end)
//		*pTemp++ = arr[rindex++];
//
//	//pTemp -> arr
//	pTemp = pBuf;
//	for (int i = bgn; i < end; i++)
//		arr[i] = *pTemp++;
//
//	delete[]pBuf;
//}
////UpToDown To DownToUp
//void mergeSort(int *arr, int bgn, int end)
//{
//	//数组arr空or仅有一个元素则退出
//	if (bgn >= end - 1)
//		return;
//
//	int mid = (bgn + end) / 2;
//	mergeSort(arr, bgn, mid);
//	mergeSort(arr, mid, end);
//	mergeSortInOrder(arr, bgn, mid, end);
//}
//
///*堆排序*/
////根节点元素自顶向下移动到合适的位置以构成最大堆
//void downToMaxHeap(int *arr, int bgn, int end)
//{
//	int child;
//	int parent = bgn;
//
//	/*假根节点向下移动至合适的位置 --整个堆排序的核心代码块*/
//	while ((child = parent * 2 + 1) < end)
//	{
//		if ((child < end - 1) && (arr[child] < arr[child + 1]))
//			++child;    //右孩子节点
//		if (arr[child] > arr[parent])
//			mySwap(&arr[child], &arr[parent]);
//		else
//			break;
//		parent = child;
//	}
//}
////将数组构造为最大堆
//void buildMaxHeap(int *arr, int bgn, int end)
//{
//	if (bgn >= end - 1)
//		return;
//
//	int parent = end / 2 - 1;
//	while (parent >= 0)
//	{
//		downToMaxHeap(arr, parent, end);
//		--parent;
//	}
//}
////堆排序
//void heapSort(int *arr, int bgn, int end)
//{
//	//构造最大堆
//	buildMaxHeap(arr, bgn, end);
//
//	while (end > 1)
//	{
//		mySwap(&arr[0], &arr[--end]);
//		downToMaxHeap(arr, 0, end);
//	}
//}
