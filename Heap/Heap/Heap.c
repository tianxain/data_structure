#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//交换数据
void Swap(HPDataType* data1, HPDataType* data2)
{
	HPDataType temp;
	temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size;i++)
	{
		printf("%d  ",hp->_a[i]);
	}
	printf("\n");
}

//堆向下调整（小堆）
void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;

	while (child<n)
	{
		//选出小的那个孩子
		if (child+1< n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child],&a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//堆向上调整（小堆）
void AdjustUp(HPDataType* a, int n,int child)
{
	int parent = (child-1)/2;
	
	while (child> 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
		    //
			//
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a=(HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a,a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	//构建堆的算法
	for (int i = (n - 1-1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a,hp->_size,i);
	}

}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	free(hp->_a);
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = realloc(hp->_a,sizeof(HPDataType)*hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;

	AdjustUp(hp->_a,hp->_size,hp->_size-1);
}

// 堆的删除
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0],&hp->_a[hp->_size-1]);
	--hp->_size;
	AdjustDown(hp->_a, hp->_size, 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->_size;
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	return hp->_size==0 ? 1:0;
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	//建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i++)
	{
		AdjustDown(a,n,i);
	}
	int end = n-1;

	while (end > 0)
	{
       Swap(&a[0],a[end]);
	   AdjustDown(a,end,0);
	   --end;
	}
	
}

