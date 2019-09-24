#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"
int main()
{
	SqList TianXian;
	char a = 'Y';
	int n=0;
	int data=0;
	int position=0;
	int *e=0;
	InitList_Sq(&TianXian);
	printf("请输入元素的个数n: ");
	scanf("%d", &n);
	Input_Sq(&TianXian, n);
	while (a == 'Y')
	{
		printf("\n请输入要插入的元素：");
		scanf("%d", &data);
		printf("\n请输入要插入的位置： ");
		scanf("%d", &position);
		ListInsert_Sq(&TianXian, position, data);
		printf(&TianXian.length);
		Output_Sq(&TianXian, n + 1);
		printf("\n请输入要删除的元素的位置： ");
		scanf("%d", &position);
		ListDelete_Sq(&TianXian, position, e);
		Output_Sq(&TianXian, n);
		printf("\n请问是否继续?(Y:继续 N:结束)\n");
		getchar();
		scanf("%c", &a);
	}
	system("pause");
	return OK;
}