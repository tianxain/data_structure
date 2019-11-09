#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h";

int main()
{
	SeqList SL_A;
	SeqListInit(&SL_A);//初始化表A
	int SL_len;//表长
	int data;
	size_t pos;
	printf("请输入顺序表A长度：");
	scanf("%d",&SL_len);
	printf("请输入表的元素：");
	for (size_t i = 0; i < SL_len; i++)
	{
		scanf("%d", &data);
		SeqListPushBack(&SL_A, data);
	}
	printf("表尾插入元素：");
	scanf("%d", &data);
	SeqListPushBack(&SL_A, data);
	SeqListPrint(&SL_A);

	printf("删除表尾元素：\n");
	SeqListPopBack(&SL_A);
	SeqListPrint(&SL_A);

	printf("表头插入元素：");
	scanf("%d", &data);
	SeqListPushFront(&SL_A, data);
	SeqListPrint(&SL_A);

	printf("删除表头元素\n：");
	SeqListPopFront(&SL_A);
	SeqListPrint(&SL_A);

	printf("指定位置插入元素(元素，位置)：");
	scanf("%d%u", &data, &pos);
	SeqListInsert(&SL_A, pos,data);
	SeqListPrint(&SL_A);

	printf("删除指定位置元素：");
	scanf("%u", &pos);
	SeqListErase(&SL_A, pos);
	SeqListPrint(&SL_A);
	
	printf("删除指定元素：");
	scanf("%u", &data);
	SeqListRemove(&SL_A, data);
	SeqListPrint(&SL_A);

	SeqListDestory(&SL_A);//释放表
	return 0;
}