#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"

void Test()
{
	ListNode* pHead = ListCreate();
	ListPushBack(pHead,1);
	ListPushBack(pHead,2);
	ListPushBack(pHead,3);
	ListPushBack(pHead,4);
	ListPushBack(pHead,5);
	ListPrint(pHead);

	ListPopBack(pHead);
	ListPrint(pHead);

	ListPushFront(pHead, 0);
	ListPrint(pHead);

	ListPopFront(pHead);
	ListPrint(pHead);
}

int main()
{
	Test();
	return 0;
}