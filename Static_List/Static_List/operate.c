#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"
//��λ�������ҵ�������ţ����򷵻�0
int LocateElem_SL(SLinkList S, ElemType e)
{
	int i = 0;
	i = S[0].cur; //iָʾ���е�һ�����
	while (i&&S[i].data != e) //�ڱ���˳������
	{
		i = S[i].cur;
	}
	return i;
}
//����������ռ��ʼ����һ������
void InitSpace_SL(SLinkList *space)
{
	//space[0].curΪͷָ�� 0��ʾ��ָ��
	int i = 0;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i]->cur = i + 1;
		space[MAXSIZE - 1]->cur = i + 1;

}
//�ӱ��ÿռ��ȡһ�����
int Malloc_SL(SLinkList *space)
{
	//�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
	int i = 0;
	i = space[0]->cur;
	if (space[0]->cur)
	{
		space[0]->cur = space[i]->cur;
	}
	return i;
}

//���±�Ϊk�Ŀ��н�����ӵ�����������
void Free_SL(SLinkList *space, int k)
{
	space[k]->cur = space[0]->cur;
	space[0]->cur = k;
}