#pragma once
#include<stdio.h>

//��ӡ����
void Show(int *arr, int len);

//��ȡ������������ֵ Ĭ��arr�ǿ�
int getMaxValue(const int *arr, int len);

//������������ֵ
void mySwap(int *pa, int *pb);

//ð������
void BubbleSort_1(int *arr, int len);//(��С����)
void BubbleSort_2(int *arr, int len);//(�Ӵ�С)

//����ѡ������
void selectSort_1(int *arr, int len);//(��С����)
void selectSort_2(int *arr, int len);//(�ӵ���С)


//��������
void quickSort_1(int *arr, int left, int right);//(��С����)
void quickSort_2(int *arr, int left, int right);//(�Ӵ�С)

//��������
void insertSort_1(int *arr, int bgn, int end);//(��С����)
void insertSort_2(int *arr, int bgn, int end);//(�Ӵ�С)

/*ϣ������*/
void shellSort(int *arr, int bgn, int end);
//ϣ������
void shellSort(int *arr, int len)��

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


