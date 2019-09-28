#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"
//定位函数
int LocateElem_SL(SLinkList S, ElemType e)
{
	int i = 0;
	i = S[0].cur; //i指示表中第一个结点
	while (i&&S[i].data != e) //在表中顺链查找
	{
		i = S[i].cur;
	}
	return i;
}