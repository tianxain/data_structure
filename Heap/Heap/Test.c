#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void test1()
{
	HPDataType a[10] = {4,1,8,5,7,3,4,5,8,5};
	Heap hp;
	HeapCreate(&hp,a,10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPush(&hp,12);
	HeapPrint(&hp);

}

int main()
{
	test1();
	return 0;
}