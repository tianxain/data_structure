#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"
int main()
{
	SLinkList *L;
	int e;
	int i;
	InitSpace_SL(L);
	//  insert(list,3);      
	//  insert(list,7);      
	//  insert(list,5);      
	//  insert(list,9);      
	scanf("%d%d",&i,&e);
	StaticLinkListInsert(L,i,e);
	return 0;
}
