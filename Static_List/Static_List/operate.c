#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"
//��λ����
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