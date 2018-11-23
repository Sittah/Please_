#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList1.h";
#include "linkedlistop.h";


/*
	iterateLinkedList 

		ㄴ   헤더노드 부터 position 까지 이동 하고나서 출력 하는게 아닌
			헤드포인터방식처럼 *pNode 에 첫 시작노드를 담고 거기서 부터 데이터를 출력한다
			*/
void iterateLinkedList(LinkedList *pList)
{
	ListNode *pNode = NULL;
	int count = 0;
	if (pList != NULL)
	{
		pNode = pList->headerNode.pLink; // 기존 &(pList->headerNode) 와 다른 부분이다

		while (pNode != NULL)
		{
			printf("[%d] , %d \n", count, pNode->data);
			count++;
			pNode = pNode->pLink;
		}
		printf("노드 개수 : %d \n", count);
	}
	else
	{
		printf("pList is Empty !! -- iterateLinkedList() \n");
	}
}

void concatLinkedList(LinkedList *pListA, LinkedList *pListB)
{
	ListNode *pNodeA = NULL, *pNodeB = NULL;

	if (pListA != NULL && pListB != NULL)
	{
		pNodeA = pListA->headerNode.pLink;
		while (pNodeA->pLink != NULL)
		{
			pNodeA = pNodeA->pLink;
		}

		pNodeA->pLink = pListB->headerNode.pLink;
		pListA->currentElementCount += pListB->currentElementCount;

		pListB->headerNode.pLink = NULL;
		pListB->currentElementCount = 0;

	}
	else
	{
		if (pListA == NULL)
		{
			printf("Error, pListB is Empty ! -- concatLinkedList() \n");
		}
		else
		{
			printf("Error, pListA is Empty ! -- concatLinkedList() \n");
		}
		
	}
}

void reverseLinkedList(LinkedList *pList)
{
	ListNode *pNode = NULL, *pCurrentNode = NULL, *pPreNode = NULL;

	if (pList != NULL)
	{
		pNode = pList->headerNode.pLink;
		while (pNode != NULL)
		{
			pPreNode = pCurrentNode;		//이전노드 설정 
			pCurrentNode = pNode;			//현재노드 설정
			pNode = pNode->pLink;			//순회노드 다음노드로
			pCurrentNode->pLink = pPreNode;	//현재노드의 다음노드는 이전노드로 설정
			/*
				1 - 2 - 3 - 4

				(1) 이전노드를 현재노드로  
				(2) 현재노드를 순환노드로
				(3) 순환노드를 다음노드로
				(4) 현재노드의 다음노드를 이전노드로
				pPreNode = pCurrentNode;		//이전노드 설정 
				pCurrentNode = pNode;			//현재노드 설정
				pCurrentNode->pLink = pPreNode;	//현재노드의 다음노드는 이전노드로 설정
				pNode = pNode->pLink;			//순회노드 다음노드로

				이렇게 순서를 바꾸면 안되는 이유

				& 2번째 줄에서 pCurrentNode = pNode; 인 상황에서
				pCurrentNode->pLink = pPreNode == pNode->pLink = pPreNode;
				와 같은 상황이 되어 버린다.
				그래서 pNode->pLink = NULL로 만든후에 pNode = pNode -> pLink 를 하면
				pNode = NULL; 이 되어버리면서 연결이 바로 끊겨버린다.

				순서를

				
			*/
			
		}
		// pNode 는 NULL을 가르키고 있음 pPreNode 는 NULL의 바로이전값 // 즉 마지막 노드를 가르킴
		pList->headerNode.pLink = pCurrentNode;

		printf("pList 노드개수 : %d \n", pList->currentElementCount);
	}
	else
	{
		printf("Error, pList is Empty ! -- reverseLinkedList() \n");
	}
}