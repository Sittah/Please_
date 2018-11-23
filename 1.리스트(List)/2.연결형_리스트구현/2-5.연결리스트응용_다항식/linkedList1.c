#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList1.h";

LinkedList* createLinkedList()
{
	LinkedList *pLinkedList = (LinkedList *)malloc(sizeof(LinkedList));

	if (pLinkedList != NULL)
	{
		memset(pLinkedList, 0, sizeof(LinkedList));
	}
	else
	{
		printf("Error, Dynamic Allocation is Failed !! - createLinkedList() \n");
	}

	return pLinkedList;

}

int addLinkedListElement(LinkedList *pList, int position, ListNode element)
{
	int ret = FALSE;
	int i = 0;
	ListNode *pnewNode = NULL;
	ListNode *pPreNode = NULL; /* Pre �ռ��� ó���ϴ� Previous ���θ� (������)*/

	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pnewNode = (ListNode *)malloc(sizeof(ListNode));
			if (pnewNode != NULL)
			{
				*pnewNode = element;
				pnewNode->pLink = NULL;

				pPreNode = &(pList->headerNode);

				//printf("pPreNode �ּ� :  %x \n", pPreNode);

				for (i = 0; i < position; i++)
				{
					pPreNode = pPreNode->pLink;

				}

				/* Allocate 'pPreNode's pLink(next Node) into 'newNode -> pLink' */
				//printf("pPreNode ->pLink �ּ� :  %x \n", pPreNode->pLink);
				pnewNode->pLink = pPreNode->pLink;
				/* Allocate 'pnewNode' into pPreNode->pLink */

				pPreNode->pLink = pnewNode;
				//printf("pPreNode ->pLink �ּ� :  %x \n", pPreNode->pLink);
				pList->currentElementCount++;
				ret = TRUE;
			}
			else
			{
				printf("Dynamic allocate of pnewNode is failed ! - addLinkedListElement()\n ");
			}
		}
		else
		{
			printf("Range of position index is exceeded !! - addLinkedListElement() \n");
		}
	}
	else
	{
		printf("Linked List is Empty ! - addLinkedListElement() \n");
	}
	return ret;
}

int removeLinkedListElement(LinkedList *pList, int position)
{
	int ret = FALSE;

	return ret;
}

void deleteLinkedList(LinkedList *pList)
{
	if (pList != NULL)
	{		
		if (pList->currentElementCount > 0)
		{
			clearList(pList);
		}
		pList = NULL;
		free(pList);
	}
	else
	{
		printf("pList is Empty !! - deleteLinkedList() \n");
	}
}
void clearList(LinkedList *pList)
{
	int i = 0, count = pList->currentElementCount;
	ListNode *checkNode = NULL;
	printf("\n--- clearList execute !! ---\n\n");

	if (pList != NULL)
	{
		for(i=0; i < count; i++)
			removeLinkedListElement(pList, 0);	
	}
	else
	{
		printf("pList is Empty !! - clearList() \n");
	}
	
}