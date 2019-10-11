#pragma once
#include<stdio.h>

//��ӡ����
void Show(int *arr, int len);

//��ȡ������������ֵ Ĭ��arr�ǿ�
int getMaxValue(const int *arr, int len);

/*������������ֵ*/
void mySwap(int *pa, int *pb);

//ð������
void BubbleSort_1(int *arr, int len);
void BubbleSort_2(int *arr, int len);

//ѡ������
void selectSort(int *arr, int bgn, int end);

/*����*/
void quickSort(int *arr, int bgn, int end);

/*��������*/
void insertSort(int *arr, int bgn, int end);

/*ϣ������*/
void shellSort(int *arr, int bgn, int end);

/*Ͱ����*/
void bucketSort(int *arr);

/*��������*/
//1. �������򣬰�������ֵ��λ��������
void countSort(int *arr, int exp);
//2. �ϲ�����λ����������
void radixSort(int *arr);

/*�鲢����*/
//����������������
void mergeSortInOrder(int *arr, int bgn, int mid, int end);

//UpToDown To DownToUp
void mergeSort(int *arr, int bgn, int end);

//������
//���ڵ�Ԫ���Զ������ƶ������ʵ�λ���Թ�������
void downToMaxHeap(int *arr, int bgn, int end);

//�����鹹��Ϊ����
void buildMaxHeap(int *arr, int bgn, int end);

//������
void heapSort(int *arr, int bgn, int end);


