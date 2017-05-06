// /*
// * @Author: han
// * @Date:   2017-05-06 21:27
// * @Last Modified by:   han
// * @Last Modified time: 2017-05-06 21:27
// */

#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/*
*	function:构建邻接表,并将其打印出来
*/
/**********************************************************/

/*表节点*/
typedef struct LinkNode
{
	int index; /*顶点*/
	int data; /*权值*/
	struct LinkNode* next;/*下一个表节点*/
} LinkNode, *LinkPtr;

/*顶点*/
typedef struct VexNode
{
	int m; /*顶点个数*/
	LinkPtr* first; /*表头结点数组*/
} VexNode;


/**
* [adjList 邻接表构建]
* @param Vex    [存储顶点信息的数组(即邻接表)]
* @param m      [存储顶点和边集信息的矩阵]
*/
void adjList(VexNode* Vex, int* m)
{
	int length = Vex->m;
	LinkNode* link_node = NULL; /*表节点*/
	LinkNode* first_node = NULL;/*头结点*/
	/*循环行*/
	for (int i = 0; i < length; i++)
	{
		link_node = malloc(sizeof(LinkNode));
		link_node->index = i;
		link_node->data = -1;
		link_node->next = NULL;
		/*循环列*/
		for (int j = 0; j < length; j++)
		{
			/*保存头结点*/
			if (j == 0)
				first_node = link_node;
			/*遇到非零的元素,将表节点保存到头结点后的最后一个位置*/
			if ((*(m + length * i + j)) != 0)
			{
				LinkNode* newNode = NULL;
				newNode = malloc(sizeof(LinkNode));
				newNode->index = j;
				newNode->data = *(m + length * i + j);
				newNode->next = NULL;
				link_node->next = newNode;
				link_node = newNode;
			}
		}
		/*头结点赋值保存到数组中*/
		Vex->first[i] = first_node;
		first_node = NULL;
	}
}

/**
* [printAdjList 打印邻接表]
* @param Vex    [邻接表]
*/
void printAdjList(VexNode* Vex)
{
	LinkNode* temp = NULL;
	/*循环遍历数组中的所有头结点*/
	for (int i = 0; i < Vex->m; i++)
	{
		temp = Vex->first[i];
		/*遍历单链表*/
		for (; temp != NULL;)
		{
			if (temp->index != -1)
			{
				printf("%d->", temp->index);
			}
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	char Vex[4] = {'A','B','C','D'};
	int m[4][4] = {
		{0,1,2,1},
		{0,0,1,1},
		{1,0,0,0},
		{0,0,1,0}
	};
	VexNode* mVex = NULL;
	mVex = malloc(sizeof(VexNode));
	int n = sizeof(m) / sizeof(m[0]);/*矩阵维度*/
	mVex->m = n;
	mVex->first = malloc(n * sizeof(LinkPtr));
	for (int i = 0; i < n; i++)
		*(mVex->first + i) = NULL;
	adjList(mVex, m);
	printAdjList(mVex);
	return 0;
}
