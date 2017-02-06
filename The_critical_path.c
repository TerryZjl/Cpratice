#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#pragma warning(disable:4996)

//该结构体用来表示从某个顶点可以到达的其他顶点
struct ENode
{
	int secPoint;//顶点号
	int weight;
	ENode *next;//指向下一个顶点的指针
};


//该结构体表示每一个顶点的信息
struct PNode
{
	char value;//顶点的值
	int inDegree;
	int outDegree;
	ENode *next;//指向顶点可以到达的其他第一个顶点的指针
};


//图的结构体，该图最多有100个顶点
struct Map
{
	PNode point[100];//数组的下标就是这个顶点的顶点号
	int numPoint, numEdge;
};


//建图的函数
struct Map *CreateMap()
{
	struct Map *mp = (struct Map*)malloc(sizeof(struct Map));
	int i, j;
	int firP, secP, weight;
	int numP, numE;
	char infoP;

	memset(mp, 0, sizeof(struct Map));

	printf("请输入顶点数和边数,格式为‘顶点数，边数’：\n");
	scanf("%d,%d", &numP, &numE);
	mp->numPoint = numP;
	mp->numEdge = numE;

	printf("请输入各个顶点的信息，没有分隔符的连续输入：\n");
	fflush(stdin);
	for (i = 0; i<mp->numPoint; i++)
	{
		scanf("%c", &infoP);
		mp->point[i].value = infoP;
	}

	printf("请输入边和权重，格式为‘顶点-顶点，权重’\n");
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

//得到各个顶点的最早结束时间，和拓扑排序类似
void GetEarlyFinished(struct Map *mp, int *earlyFinished)
{
	int iPoint, iNoInPoint;
	int noInPoint[20];
	int curPoint;

	struct ENode *pNode;

	//找到所有始发节点（入度为0），只能找出一个，并将其最早结束时间设置为0
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

	//如果入度为零的数组不空
	while (iNoInPoint >= 0)
	{
		curPoint = noInPoint[iNoInPoint];
		iNoInPoint--;

		//遍历出度为零的所能到达的顶点，也就是已经确定最早结束时间的顶点的下一个顶点
		for (pNode = mp->point[curPoint].next; pNode != NULL; pNode = pNode->next)
		{

			//如果当前顶点的最早结束时间早于以确定时间的前一个顶点的时间加上当前活动所用的时间

			//则将最早结束时间延后
			if (earlyFinished[curPoint] + pNode->weight > earlyFinished[pNode->secPoint])
				earlyFinished[pNode->secPoint] = earlyFinished[curPoint] + pNode->weight;
			//入度减一            
			mp->point[pNode->secPoint].inDegree--;

			//若入度为零，则当前节点的最早结束时间确定，放入数组
			if (mp->point[pNode->secPoint].inDegree == 0)
			{
				iNoInPoint++;
				noInPoint[iNoInPoint] = pNode->secPoint;
			}
		}
	}
}

//得到各个顶点的最晚结束时间，和逆拓扑排序类似
void GetLastFinished(struct Map *mp, int *lastFinished)
{
	int iPoint, iNoOutPoint;
	int noOutPoint[20];
	int curPoint;

	struct ENode *pNode;

	//找出出度为0的顶点，只有一个，为终结活动
	for (iPoint = 0, iNoOutPoint = 0; iPoint<mp->numPoint; iPoint++)
	{
		if (mp->point[iPoint].outDegree == 0)
		{
			noOutPoint[iNoOutPoint] = iPoint;
			iNoOutPoint++;

			//将出度设置为-1，防止重复找出
			mp->point[iPoint].outDegree = -1;
		}
	}
	iNoOutPoint--;

	//若出度为0的数组中还有顶点
	while (iNoOutPoint >= 0)
	{
		curPoint = noOutPoint[iNoOutPoint];
		iNoOutPoint--;

		//遍历整个邻接表，找到可以到达当前节点的节点
		for (iPoint = 0; iPoint<mp->numPoint; iPoint++)
		{
			for (pNode = mp->point[iPoint].next; pNode != NULL; pNode = pNode->next)
			{

				//如果iPoint可以到达当前节点
				if (pNode->secPoint == curPoint)
				{

					//如果iPoint的最晚结束时间晚于当前节点的最晚结束时间减去当前活动的时间

					//iPoint的最晚结束时间提前
					if (lastFinished[curPoint] - pNode->weight < lastFinished[iPoint])
						lastFinished[iPoint] = lastFinished[curPoint] - pNode->weight;
					//出度减一            
					mp->point[iPoint].outDegree--;

					//出度为0则表示iPoint的最晚结束时间确定，放入数组，并将出度置为-1
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

	//将最晚结束时间初始化为较大的值
	memset(last, 100, sizeof(last));

	GetEarlyFinished(mp, early);

	//最后一个活动的最晚结束时间和最早结束时间相同
	last[(mp->numPoint) - 1] = early[(mp->numPoint) - 1];
	GetLastFinished(mp, last);

	printf("\n\n关键路径是:\n");
	for (i = 0; i<mp->numPoint; i++)
	{

		//最早结束时间和最晚结束时间相同的节点为关键路径节点
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

