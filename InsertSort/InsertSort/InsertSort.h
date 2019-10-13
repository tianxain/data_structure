#pragma once
#include<stdio.h>
//打印数组
void Show(int *arr, int len);

//交换两个整形值
void mySwap(int *pa, int *pb);

//直接插入排序(从小到大)
void insertSort_1(int *arr, int len);
//直接插入排序(从大到小)
void insertSort_2(int *arr, int len);

//折半插入排序
void binaryInsertSort(int *arr, int len);
