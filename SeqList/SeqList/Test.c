#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h";

int main()
{
	SeqList SL_A;
	SeqListInit(&SL_A);//��ʼ����A
	int SL_len;//��
	int data;
	size_t pos;
	printf("������˳���A���ȣ�");
	scanf("%d",&SL_len);
	printf("��������Ԫ�أ�");
	for (size_t i = 0; i < SL_len; i++)
	{
		scanf("%d", &data);
		SeqListPushBack(&SL_A, data);
	}
	printf("��β����Ԫ�أ�");
	scanf("%d", &data);
	SeqListPushBack(&SL_A, data);
	SeqListPrint(&SL_A);

	printf("ɾ����βԪ�أ�\n");
	SeqListPopBack(&SL_A);
	SeqListPrint(&SL_A);

	printf("��ͷ����Ԫ�أ�");
	scanf("%d", &data);
	SeqListPushFront(&SL_A, data);
	SeqListPrint(&SL_A);

	printf("ɾ����ͷԪ��\n��");
	SeqListPopFront(&SL_A);
	SeqListPrint(&SL_A);

	printf("ָ��λ�ò���Ԫ��(Ԫ�أ�λ��)��");
	scanf("%d%u", &data, &pos);
	SeqListInsert(&SL_A, pos,data);
	SeqListPrint(&SL_A);

	printf("ɾ��ָ��λ��Ԫ�أ�");
	scanf("%u", &pos);
	SeqListErase(&SL_A, pos);
	SeqListPrint(&SL_A);
	
	printf("ɾ��ָ��Ԫ�أ�");
	scanf("%u", &data);
	SeqListRemove(&SL_A, data);
	SeqListPrint(&SL_A);

	SeqListDestory(&SL_A);//�ͷű�
	return 0;
}