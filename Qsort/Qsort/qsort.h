#pragma once
#include<stdio.h>

//´òÓ¡Êý×é
void Show(int *arr, int len);

//Qsort
void MyQsort(void *base, int count, int size, int(*cmp)(void *p1, void *p2));
int int_cmp(const void * p1, const void * p2);
void _swap(void *p1, void * p2, int size);
