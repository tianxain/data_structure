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
	printf("������LAԪ�صĸ���n: ");
	scanf("%d", &n);
	Input_Sq(&LA, n);
	printf("������LBԪ�صĸ���n: ");
	scanf("%d", &m);
	Input_Sq(&LB, m);
	//Union(&LA, LB);
	MergList(LA, LB, &LC);
	Output_Sq(&LC, LC.length);
	/*while (a == 'Y')
	{
		printf("\n������Ҫ�����Ԫ�أ�");
		scanf("%d", &data);
		printf("\n������Ҫ�����λ�ã� ");
		scanf("%d", &position);
		ListInsert_Sq(&LA, position, data);
		printf(&LA.length);
		Output_Sq(&LA, n + 1);
		printf("\n������Ҫɾ����Ԫ�ص�λ�ã� ");
		scanf("%d", &position);
		ListDelete_Sq(&LA, position, e);
		Output_Sq(&LA, n);
		printf("\n�����Ƿ����?(Y:���� N:����)\n");
		getchar();
		scanf("%c", &a);
	}*/
	system("pause");
	return OK;
}