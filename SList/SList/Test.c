#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void Test1()
{
	SListNode* pList=NULL;
	SListPushBack(&pList,1);
	SListPushBack(&pList,2);
	SListPushBack(&pList,3);
	SListPushBack(&pList,4);
	SListPrint(pList);

	SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	
}
void Test2()
{
	SListNode* pList = NULL;
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPrint(pList);

	SListPopFront(&pList);
	SListPrint(pList);
	SListPopFront(&pList);
	SListPrint(pList);
	SListPopFront(&pList);
	SListPrint(pList);
	SListPopFront(&pList);
	SListPrint(pList);
}
int main()
{
	///Test1();
	Test2();
	return 0;
}