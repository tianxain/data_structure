#pragma once
#include<stdio.h>
//打印数组
void Show(int *arr, int len);

//交换两个整形值
void mySwap(int *pa, int *pb);

//快速排序(从小到大)
void quickSort_1( int *arr,int left, int right);
//快速排序(从大到小)
void quickSort_2(int *arr, int left, int right);