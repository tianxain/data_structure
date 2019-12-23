#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void Swap(HPDataType* data1, HPDataType* data2);
void HeapPrint(Heap* hp);

//�����µ�����С�ѣ�
void AdjustDown(HPDataType* a, int n, int root);
//�����ϵ�����С�ѣ�
void AdjustUp(HPDataType* a, int n, int child);
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// ��������ж�����
void HeapSort(int* a, int n);
