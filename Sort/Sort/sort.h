#pragma once
#include<stdio.h>

//打印数组
void Show(int *arr, int len);

//获取整形数组的最大值 默认arr非空
int getMaxValue(const int *arr, int len);

//交换两个整形值
void mySwap(int *pa, int *pb);

//冒泡排序
void BubbleSort_1(int *arr, int len);//(从小到大)
void BubbleSort_2(int *arr, int len);//(从大到小)

//基本选择排序
void selectSort_1(int *arr, int len);//(从小到大)
void selectSort_2(int *arr, int len);//(从到大小)


//快速排序
void quickSort_1(int *arr, int left, int right);//(从小到大)
void quickSort_2(int *arr, int left, int right);//(从大到小)

//插入排序
void insertSort_1(int *arr, int bgn, int end);//(从小到大)
void insertSort_2(int *arr, int bgn, int end);//(从大到小)

/*希尔排序*/
void shellSort(int *arr, int bgn, int end);
//希尔排序
void shellSort(int *arr, int len)；

/*桶排序*/
void bucketSort(int *arr);

/*基数排序*/
//1. 计数排序，按整形数值单位进行排序
void countSort(int *arr, int exp);
//2. 合并各单位计数排序结果
void radixSort(int *arr);

/*归并排序*/
//排序两个有序数列
void mergeSortInOrder(int *arr, int bgn, int mid, int end);

//UpToDown To DownToUp
void mergeSort(int *arr, int bgn, int end);

//堆排序
//根节点元素自顶向下移动到合适的位置以构成最大堆
void downToMaxHeap(int *arr, int bgn, int end);

//将数组构造为最大堆
void buildMaxHeap(int *arr, int bgn, int end);

//堆排序
void heapSort(int *arr, int bgn, int end);


