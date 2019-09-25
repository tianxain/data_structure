#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"
int main()
{
	SqList LA;
	SqList LB;
	SqList LC;
	char a = 'Y';
	int n = 0, m = 0;
	int data=0;
	int position=0;
	int *e=0;
	InitList_Sq(&LA);
	InitList_Sq(&LB);
	printf("请输入LA元素的个数n: ");
	scanf("%d", &n);
	Input_Sq(&LA, n);
	printf("请输入LB元素的个数n: ");
	scanf("%d", &m);
	Input_Sq(&LB, m);
	//Union(&LA, LB);
	MergList(LA, LB, &LC);
	Output_Sq(&LC, LC.length);
	/*while (a == 'Y')
	{
		printf("\n请输入要插入的元素：");
		scanf("%d", &data);
		printf("\n请输入要插入的位置： ");
		scanf("%d", &position);
		ListInsert_Sq(&LA, position, data);
		printf(&LA.length);
		Output_Sq(&LA, n + 1);
		printf("\n请输入要删除的元素的位置： ");
		scanf("%d", &position);
		ListDelete_Sq(&LA, position, e);
		Output_Sq(&LA, n);
		printf("\n请问是否继续?(Y:继续 N:结束)\n");
		getchar();
		scanf("%c", &a);
	}*/
	system("pause");
	return OK;
}