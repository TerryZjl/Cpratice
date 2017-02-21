#include"DSeqList.h"

void InitSeqList(pSeqList pcon)
{
	assert(pcon);

	pcon->arr = (DataType *)malloc(LEN*sizeof(SeqList));
	if (pcon->arr == NULL)
	{
		perror("malloc");
		return;
	}
	pcon->count = 0;
	pcon->capacity = LEN;
	memset(pcon->arr, 0, sizeof(DataType)*LEN);
}

void OpenSpace(pSeqList p)
{
	assert(p != NULL);
	if (p->capacity == p->count)
	{
		DataType *tep = (DataType *)realloc(p->arr, (LEN + ADDLEN)*sizeof(DataType *));
		if (tep != NULL)
		{
			p->arr = tep;
		}
		p->capacity += ADDLEN;
	}
}

void PushBack(pSeqList pcon, DataType d)
{
	assert(pcon != NULL);
	OpenSpace(pcon);
	pcon->arr[pcon->count] = d;
	pcon->count++;
}

void Show(pSeqList pcon)
{
	assert(pcon != NULL);

	int i = 0;
	if (0 == pcon->count)
	{
		printf("通讯录为空\n");
		return;
	}
	for (i = 0; i < pcon->count; i++)
	{
		printf("%d ", pcon->arr[i]);
	}
	printf("\n");
}

void PopBack(pSeqList pcon)
{
	assert(pcon != NULL);
	pcon->count--;
}

void PushFront(pSeqList pcon, DataType d)
{
	assert(pcon != NULL);
	OpenSpace(pcon);
	int i = pcon->count;
	while (i>0)
	{
		pcon->arr[i] = pcon->arr[i - 1];
		i--;
	}
	pcon->arr[i] = d;
	pcon->count++;
}

void PopFront(pSeqList pcon)
{
	assert(pcon != NULL);
	int i = 0;
	while (i < pcon->count)
	{
		pcon->arr[i] = pcon->arr[i + 1];
		i++;
	}
	pcon->count--;
}

int Find(pSeqList pcon, DataType d)
{
	assert(pcon != NULL);
	
	int i = 0;
	while (i < pcon->count)
	{
		if (d == pcon->arr[i])
		{
			return i;
		}
		i++;
	}
	return -1;
}

void Remove(pSeqList pcon, DataType d)
{
	assert(pcon != NULL);
	int ret = 0;
	ret = Find(pcon, d);
	if (ret == -1)
	{
		printf("没有要删除的元素%d\n", d);
	}
	else
	{
		while (ret < pcon->count)
		{
			pcon->arr[ret] = pcon->arr[ret + 1];
			ret++;
		}
		pcon->count--;
		printf("%d已删除\n", d);
	}
}
void RemoveAll(pSeqList pcon, DataType d)
{
	assert(pcon != NULL);
	int num = pcon->count;
	int ret = 0;
	int i = 0;
	for (i = 0; i < pcon->count; i++)
	{
		if (pcon->arr[i] == d)
		{
			ret = i;
			while (ret < pcon->count)
			{
				pcon->arr[ret] = pcon->arr[ret + 1];
				ret++;
			}
			pcon->count--;
		}
	}
	if (num == pcon->count)
	{
		printf("没有找到要删除的元素%d\n", d);
	}
	else
	{
		printf("%d已删除\n", d);
	}
}

void Sort(pSeqList pcon)
{
	assert(pcon != NULL);
	int i = 0;
	int j = 0;
	DataType temp = 0;
	for (i = 0; i < pcon->count-1; i++)
	{
		for (j = 0; j < pcon->count - i - 1; j++)
		{
			if (pcon->arr[j]>pcon->arr[j + 1])
			{
				temp = pcon->arr[j];
				pcon->arr[j] = pcon->arr[j + 1];
				pcon->arr[j + 1] = temp;
			}
		}
	}
}

int BinarySearch(pSeqList pcon, DataType d)
{
	int left = 0;
	int right = pcon->count - 1;
	int temp = 0;
	while (left <= right)
	{
		temp = left - ((left - right) >> 1);
		if (d < pcon->arr[temp])
		{
			right = temp - 1;
		}
		else if (d>pcon->arr[temp])
		{
			left = temp + 1;
		}
		else
		{
			return temp;
		}
	}
	if (left > right)
	{
		return -1;
	}
}