#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#pragma warning(disable:4996)

//�ýṹ��������ʾ��ĳ��������Ե������������
struct ENode
{
	int secPoint;//�����
	int weight;
	ENode *next;//ָ����һ�������ָ��
};


//�ýṹ���ʾÿһ���������Ϣ
struct PNode
{
	char value;//�����ֵ
	int inDegree;
	int outDegree;
	ENode *next;//ָ�򶥵���Ե����������һ�������ָ��
};


//ͼ�Ľṹ�壬��ͼ�����100������
struct Map
{
	PNode point[100];//������±�����������Ķ����
	int numPoint, numEdge;
};


//��ͼ�ĺ���
struct Map *CreateMap()
{
	struct Map *mp = (struct Map*)malloc(sizeof(struct Map));
	int i, j;
	int firP, secP, weight;
	int numP, numE;
	char infoP;

	memset(mp, 0, sizeof(struct Map));

	printf("�����붥�����ͱ���,��ʽΪ������������������\n");
	scanf("%d,%d", &numP, &numE);
	mp->numPoint = numP;
	mp->numEdge = numE;

	printf("����������������Ϣ��û�зָ������������룺\n");
	fflush(stdin);
	for (i = 0; i<mp->numPoint; i++)
	{
		scanf("%c", &infoP);
		mp->point[i].value = infoP;
	}

	printf("������ߺ�Ȩ�أ���ʽΪ������-���㣬Ȩ�ء�\n");
	fflush(stdin);
	for (j = 0; j<mp->numEdge; j++)
	{
		scanf("%d-%d,%d", &firP, &secP, &weight);
		struct ENode *newNode = (struct ENode *)malloc(sizeof(struct ENode));
		mp->point[firP].outDegree++;
		mp->point[secP].inDegree++;
		newNode->secPoint = secP;
		newNode->weight = weight;
		newNode->next = mp->point[firP].next;
		mp->point[firP].next = newNode;
	}
	return mp;
}

//�õ�����������������ʱ�䣬��������������
void GetEarlyFinished(struct Map *mp, int *earlyFinished)
{
	int iPoint, iNoInPoint;
	int noInPoint[20];
	int curPoint;

	struct ENode *pNode;

	//�ҵ�����ʼ���ڵ㣨���Ϊ0����ֻ���ҳ�һ�����������������ʱ������Ϊ0
	for (iPoint = 0, iNoInPoint = 0; iPoint<mp->numPoint; iPoint++)
	{
		if (mp->point[iPoint].inDegree == 0)
		{
			noInPoint[iNoInPoint] = iPoint;
			earlyFinished[iPoint] = 0;
			iNoInPoint++;
		}
	}
	iNoInPoint--;

	//������Ϊ������鲻��
	while (iNoInPoint >= 0)
	{
		curPoint = noInPoint[iNoInPoint];
		iNoInPoint--;

		//��������Ϊ������ܵ���Ķ��㣬Ҳ�����Ѿ�ȷ���������ʱ��Ķ������һ������
		for (pNode = mp->point[curPoint].next; pNode != NULL; pNode = pNode->next)
		{

			//�����ǰ������������ʱ��������ȷ��ʱ���ǰһ�������ʱ����ϵ�ǰ����õ�ʱ��

			//���������ʱ���Ӻ�
			if (earlyFinished[curPoint] + pNode->weight > earlyFinished[pNode->secPoint])
				earlyFinished[pNode->secPoint] = earlyFinished[curPoint] + pNode->weight;
			//��ȼ�һ            
			mp->point[pNode->secPoint].inDegree--;

			//�����Ϊ�㣬��ǰ�ڵ���������ʱ��ȷ������������
			if (mp->point[pNode->secPoint].inDegree == 0)
			{
				iNoInPoint++;
				noInPoint[iNoInPoint] = pNode->secPoint;
			}
		}
	}
}

//�õ�����������������ʱ�䣬����������������
void GetLastFinished(struct Map *mp, int *lastFinished)
{
	int iPoint, iNoOutPoint;
	int noOutPoint[20];
	int curPoint;

	struct ENode *pNode;

	//�ҳ�����Ϊ0�Ķ��㣬ֻ��һ����Ϊ�ս�
	for (iPoint = 0, iNoOutPoint = 0; iPoint<mp->numPoint; iPoint++)
	{
		if (mp->point[iPoint].outDegree == 0)
		{
			noOutPoint[iNoOutPoint] = iPoint;
			iNoOutPoint++;

			//����������Ϊ-1����ֹ�ظ��ҳ�
			mp->point[iPoint].outDegree = -1;
		}
	}
	iNoOutPoint--;

	//������Ϊ0�������л��ж���
	while (iNoOutPoint >= 0)
	{
		curPoint = noOutPoint[iNoOutPoint];
		iNoOutPoint--;

		//���������ڽӱ��ҵ����Ե��ﵱǰ�ڵ�Ľڵ�
		for (iPoint = 0; iPoint<mp->numPoint; iPoint++)
		{
			for (pNode = mp->point[iPoint].next; pNode != NULL; pNode = pNode->next)
			{

				//���iPoint���Ե��ﵱǰ�ڵ�
				if (pNode->secPoint == curPoint)
				{

					//���iPoint���������ʱ�����ڵ�ǰ�ڵ���������ʱ���ȥ��ǰ���ʱ��

					//iPoint���������ʱ����ǰ
					if (lastFinished[curPoint] - pNode->weight < lastFinished[iPoint])
						lastFinished[iPoint] = lastFinished[curPoint] - pNode->weight;
					//���ȼ�һ            
					mp->point[iPoint].outDegree--;

					//����Ϊ0���ʾiPoint���������ʱ��ȷ�����������飬����������Ϊ-1
					if (mp->point[iPoint].outDegree == 0)
					{
						iNoOutPoint++;
						noOutPoint[iNoOutPoint] = iPoint;
						mp->point[iPoint].outDegree = -1;
					}
				}
			}
		}
	}
}

void KeyPath(struct Map *mp)
{
	int early[20] = { 0 }, last[20];
	int i;

	//���������ʱ���ʼ��Ϊ�ϴ��ֵ
	memset(last, 100, sizeof(last));

	GetEarlyFinished(mp, early);

	//���һ������������ʱ����������ʱ����ͬ
	last[(mp->numPoint) - 1] = early[(mp->numPoint) - 1];
	GetLastFinished(mp, last);

	printf("\n\n�ؼ�·����:\n");
	for (i = 0; i<mp->numPoint; i++)
	{

		//�������ʱ����������ʱ����ͬ�Ľڵ�Ϊ�ؼ�·���ڵ�
		if (last[i] == early[i])
			printf("%d", i);
	}
	printf("\n\n");
}

int main()
{

	struct Map *mp = CreateMap();
	KeyPath(mp);
	system("pause");
	return 1;
}

