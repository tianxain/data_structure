#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"
int main()
{
	printf("�������ĳ��ȣ�");
	int n;
	LinkList L, p, s;
	scanf("%d", &n);
	CreatList_L1(&L, n);
	printf("�����");
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;

	}
	printf("\n");

	int i, e;
	printf("��ѯλ��: ");
	scanf("%d", &i);
	GetElem_L(L, i, &e);
	printf("e = %d\n", e);
	printf("�����");
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;

	}
	printf("\n");


	printf("����λ�á�Ԫ�أ�");
	scanf("%d%d", &i, &e);
	ListInsert_L(&L, i, e);
	p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;

	}
	printf("\n");
	
	printf("ɾ��λ�ã�");
	scanf("%d", &i);
	ListDelete_L(&L, i, &e);
	printf("e = %d\n", e);
	/*printf("�����");
	p = L->next;
	while (p != NULL) 
	{
		printf("%d ", p->data);
		p = p->next;

	}
	printf("\n");*/

	
	int a[] = { 3, 5, 8, 11 };
	int b[] = { 2, 6, 8, 9, 11, 15, 20 };
	LinkList La, Lb;
	La = (LinkList)malloc(sizeof(LNode));
	Lb = (LinkList)malloc(sizeof(LNode));
	La->next = Lb->next = NULL;
	p = La;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = a[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;

	p = Lb;
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = b[i];
		p->next = s;
		p = s;
	}
	p->next = NULL;

	printf("La = ");
	p = La->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	p = La->next;

	printf("Lb = ");
	p = Lb->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

	LinkList Lc;
	MergeList(La, Lb, &Lc);

	printf("MergeList = ");
	p = Lc->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}