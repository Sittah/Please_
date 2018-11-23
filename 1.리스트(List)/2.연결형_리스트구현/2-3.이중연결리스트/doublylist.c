#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylist.h";

DoublyList* createDoublyList()
{
	DoublyList * pList = NULL;

	pList = (DoublyList *)malloc(sizeof(DoublyList));

	if (pList != NULL)
	{
		memset(pList, 0, sizeof(DoublyList));
		pList->headerNode.pLLink = &(pList->headerNode);
		pList->headerNode.pRLink = &(pList->headerNode);
	}
	else
	{
		printf("Error, pList dynamic allocation is failled!! - createDoublyList() \n");
	}
	return pList;
}

int addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
	int ret = FALSE;
	int i = 0;
	DoublyListNode *pNewNode = NULL, *pPreNode = NULL;

	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pNewNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));

			if (pNewNode != NULL)
			{
				*pNewNode = element;
				pPreNode = &(pList->headerNode);

				for (i = 0; i < position; i++)
				{
					pPreNode = pPreNode->pRLink;
				}

				pNewNode->pLLink = pPreNode;			// 새노드의 전 노드를 설정
				pNewNode->pRLink = pPreNode->pRLink;// 새노드의 다음 노드를 전노드의 다음노드로 설정
				pPreNode->pRLink = pNewNode;			// 전 노드의 다음 노드를 새노드로 설정
				pNewNode->pRLink->pLLink = pNewNode;	// 전노드의 다음 노드의 다음노드의 전 노드

				pList->currentElementCount++;
				ret = TRUE;

														/* 즉, 헤더 - 2 - (새노드) - 3 - 4 노드가 있고
														 포지션을 1로 받아왔다면

													   for 문에서 pPreNode = 2번 노드가 된다
													   (1) 새 노드의 이전 노드는 2번 노드
													   (2) 새 노드의 다음 노드는 3번 노드 (2번노드의 다음)
													   (3) 이전 노드(2번)의 다음 노드는 새 노드(newNode)
													   (4) 새노드의 다음노드 (3)의 이전노드 (원래는 3의 이전노드는 2 였지만) = 새노드
															
													   */
				
			}
			else
			{
				printf("Error, pNewNode allocation is failed !! - addDLElement() \n");
			}
		}
		else
		{
			printf("position is out of range ! -- addDLElement() \n");
		}
	}
	else
	{
		printf("Error, pList is Empty!! == addDLElement() \n");
	}

	return ret;
}

int removeDLElement(DoublyList *pList, int position)
{
	int ret = FALSE;
	int i = 0;
	DoublyListNode *pPreNode = NULL, *pRemoveNode = NULL;


	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pPreNode = &(pList->headerNode);

			for (i = 0; i < position; i++)
			{
				pPreNode = pPreNode->pRLink;
			}
			pRemoveNode = pPreNode->pRLink;
			pPreNode->pRLink = pRemoveNode->pRLink;
			pRemoveNode->pRLink->pLLink = pPreNode;


			SAFE_RELEASE(&pRemoveNode);

			// 삭제 하는 과정
			// 1. 삭제할 노드의 이전노드 pPreNode 를 설정 한다.
			// 2. 삭제할 노드를 설정한다 pRemoveNode = pPreNode -> pRLink;
			// 3. 이전 노드의 다음노드를 pRemoveNode -> pRLink;
			// 4. pRemoveNode -> pRLink -> pLink = pPreNode;

			pList->currentElementCount--;
			ret = TRUE;

		}
		else
		{
			printf("position is out of range ! -- removeDLElement() \n");
		}
	}
	else
	{
		printf("Error, pList is Empty! - removeDLElement() \n");
	}


	return ret;
}


void deleteDoublyList(DoublyList *pList)
{
	if (pList != NULL)
	{
		clearDoublyList(pList);
		printf("delete - pList : %x \n", pList);
		SAFE_RELEASE(&pList);
		printf("delete - pList : %x \n", pList);

	}
	else
	{
		printf("Error, pList is Empty !! - deleteDoublyList() \n");
	}
}
void clearDoublyList(DoublyList *pList)
{
	if (pList != NULL)
	{
		while (pList->currentElementCount > 0)
		{
			removeDLElement(pList, 0);
		}
	}
	else
	{
		printf("pList is Empty !! - clearDoublyList() \n");
	}
}
