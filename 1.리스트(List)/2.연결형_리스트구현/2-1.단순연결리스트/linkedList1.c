#include <stdio.h>
#include "linkedList1.h";
#include <string.h>
#include <stdlib.h>

#include <stdio.h>
#include "linkedList1.h";
#include <string.h>
#include <stdlib.h>

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
	ListNode *pPreNode = NULL; /* Pre 앞서서 처리하는 Previous 줄인말 (이전의)*/

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

				//printf("pPreNode 주소 :  %x \n", pPreNode);

				for (i = 0; i < position; i++)
				{
					pPreNode = pPreNode->pLink;

				}

				/* Allocate 'pPreNode's pLink(next Node) into 'newNode -> pLink' */
				//printf("pPreNode ->pLink 주소 :  %x \n", pPreNode->pLink);
				pnewNode->pLink = pPreNode->pLink;
				/* Allocate 'pnewNode' into pPreNode->pLink */

				pPreNode->pLink = pnewNode;
				//printf("pPreNode ->pLink 주소 :  %x \n", pPreNode->pLink);
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
	ListNode *preNode = NULL;
	ListNode *removeNode = NULL;
	int i = 0;

	printf("\n -- removeLinkedList execute ! -- \n\n");
	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			preNode = &(pList->headerNode);
			
			for (i = 0; i < position; i++)
			{
				preNode = preNode->pLink;
			}
			/**/
			removeNode = preNode->pLink;
			printf("preNode 값 : %d ,  주소 : %x \n", preNode->data, preNode);
			printf("removeNode 값 : %d ,  주소 : %x \n", removeNode->data, removeNode);
			preNode->pLink = removeNode->pLink;
			free(removeNode);

			pList->currentElementCount--;
			ret = TRUE;
		}

	}
	else
	{
		printf("pList is Empty - removeLinkedElement() \n");
	}

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
void displayList(LinkedList *pList)
{
	int i = 0;
	ListNode * preNode = NULL;

	printf("\n -- displayList execute ! -- \n\n");

	if (pList != NULL)
	{
		ListNode * preNode = &(pList->headerNode);
		printf("현재 원소 개수 : %d \n", pList->currentElementCount);
		for (i = 0; i < pList->currentElementCount; i++)
		{
			preNode = preNode->pLink;
			printf("노드 %d 번째 값 : %d    ----------- 주소 : %x \n", i, preNode->data, preNode);
		}
	}
	else
	{
		printf("리스트가 비었습니다. - addLinekdListElemnet() \n");
	}

}