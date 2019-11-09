#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
// 基本增删查改接口

void SeqListInit(SeqList* pSL)//初始化
{
	assert(pSL);
	pSL->_array = NULL;
	pSL->_size = 0;
	pSL->_capicity = 0;
}

void SeqListDestory(SeqList* pSL)//释放
{
	assert(pSL);
	pSL->_array = NULL;
	pSL->_size = 0;
	pSL->_capicity = 0;
}

void SLCheckCapacity(SeqList* pSL)//检查表的容量
{
	if (pSL->_size == pSL->_capicity)
	{
		size_t newcapicity = pSL->_capicity == 0 ? 4 : pSL->_capicity * 2;
		pSL->_array = realloc(pSL->_array, newcapicity * sizeof(SLDataType));
		pSL->_capicity = newcapicity;
	}
}
void SeqListPrint(SeqList* pSL)//打印表
{
	assert(pSL);
	for (size_t i = 0; i < pSL->_size; i++)
	{
		printf("%d  ", pSL->_array[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* pSL, SLDataType x)//尾插
{
	assert(pSL);

	SLCheckCapacity(pSL);
	pSL->_array[pSL->_size] = x;
	pSL->_size++;

}

void SeqListPopBack(SeqList* pSL)//尾删
{
	assert(pSL);
	assert(pSL->_size > 0);

	pSL->_size--;
}

void SeqListPushFront(SeqList* pSL, SLDataType x)//头插
{
	assert(pSL);

	SLCheckCapacity(pSL);

	//挪动数据
	int end = pSL->_size - 1;
	for (; end >= 0; end--)
	{
		pSL->_array[end + 1] = pSL->_array[end];
	}
	pSL->_array[0] = x;
	pSL->_size++;
}

void SeqListPopFront(SeqList* pSL)//头删
{
	assert(pSL);
	assert(pSL->_size > 0);

	if (pSL->_size == 1)
	{
		pSL->_size = 0;
	}
	else
	{
		for (size_t i = 0; i < pSL->_size - 1; i++)
		{
			pSL->_array[i] = pSL->_array[i + 1];
		}
		pSL->_size--;
	}
}

int SeqListFind(SeqList* pSL, SLDataType x)
{
	assert(pSL);
	for (size_t i = 0; i < pSL->_size; i++)
	{
		if (pSL->_array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* pSL, size_t pos, SLDataType x)
{

	assert(pSL&&pos<pSL->_size);
	SLCheckCapacity(pSL);

	//挪动数据
	size_t end = pSL->_size + 1;
	while (end > pos)
	{
		pSL->_array[end] = pSL->_array[end-1];
		end--;
	}
	/*for (; end >= pos; end--)
	{
		pSL->_array[end + 1] = pSL->_array[end];
	}*/
	pSL->_array[end] = x;
	pSL->_size++;
}
void SeqListErase(SeqList* pSL, size_t pos)//删除指定位置元素
{
	assert(pSL);

	//挪动数据
	for (size_t i=pos-1;i<pSL->_size-1;i++)
	{
		pSL->_array[i] = pSL->_array[i+ 1];
	}
	pSL->_size--;
}
void SeqListRemove(SeqList* pSL, SLDataType x)//删除指定元素
{
	assert(pSL);
	for (size_t i = 0; i < pSL->_size; i++)
	{
		if (pSL->_array[i] == x)
		{
			SeqListErase(pSL,i+1);
			i--;
		}
	}
	
}
void SeqListModify(SeqList* pSL, size_t pos, SLDataType x)
{
	assert(pSL);
	pSL->_array[pos - 1] = x;
}

// 扩展面试题实现
void SeqListBubbleSort(SeqList* pSL)//冒泡排序
{
	assert(pSL);

	for (size_t i = 0; i < pSL->_size-1; i++)
	{
		int exchange = 0;
		for (size_t j = 0; j < pSL->_size-1-i; j++)
		{
			if (pSL->_array[j] >pSL->_array[j + 1])
			{
                SLDataType temp = pSL->_array[j];
			    pSL->_array[j] = pSL->_array[j+1];
			    pSL->_array[j+1] = temp;
				exchange = 1;
			}		
		}
		if (exchange == 0)
		{
			return ;
		}
	}
}

int SeqListBinaryFind(SeqList* pSL, SLDataType x)//二分查找
{
	////[begin,end]
	//size_t begin = 0; size_t end = pSL->_size-1;
	//while (begin <= end)
	//{
	//	size_t mid = (begin + end) / 2;
	//	if (pSL->_array[mid] == x)
	//	{
 //           return mid;
	//	}
	//	
	//	if (pSL->_array[mid] > x)
	//	{
	//		end = mid -1;
	//	}
	//	else if (pSL->_array[mid] < x)
	//	{
	//		begin = mid +1;
	//	}	
	//}


	//[begin,end)
	size_t begin = 0; size_t end = pSL->_size;
	while (begin < end)
	{
		size_t mid = (begin+end) / 2;
		if (pSL->_array[mid] > x)
		{
			end = mid;
		}
		else if (pSL->_array[mid] < x)
		{
			begin = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}
