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
	printf("������Ԫ�صĸ���n: ");
	scanf("%d", &n);
	Input_Sq(&TianXian, n);
	while (a == 'Y')
	{
		printf("\n������Ҫ�����Ԫ�أ�");
		scanf("%d", &data);
		printf("\n������Ҫ�����λ�ã� ");
		scanf("%d", &position);
		ListInsert_Sq(&TianXian, position, data);
		printf(&TianXian.length);
		Output_Sq(&TianXian, n + 1);
		printf("\n������Ҫɾ����Ԫ�ص�λ�ã� ");
		scanf("%d", &position);
		ListDelete_Sq(&TianXian, position, e);
		Output_Sq(&TianXian, n);
		printf("\n�����Ƿ����?(Y:���� N:����)\n");
		getchar();
		scanf("%c", &a);
	}
	system("pause");
	return OK;
}