#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularList.h";

CircularList* createCCList()
{
	CircularList *pReturnList = NULL;
	
	pReturnList = (CircularList *)malloc(sizeof(CircularList));

	if (pReturnList != NULL)
	{
		/* initialize of pReturnList per in byte*/
		memset(pReturnList, 0, sizeof(CircularList));
	}
	else
	{
		printf("Error, pReturnList dynamic allocation is failled !! -- createCCList() \n");
	}

	return pReturnList;
}

int addCCL_Element(CircularList *pList, int position, CircularListNode element)
{
	int ret = FALSE, i = 0;
	CircularListNode *pNewNode = NULL, *pPreNode = NULL;
	
	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentElementCount)
		{
			pNewNode = (CircularListNode *)malloc(sizeof(CircularListNode));
			if (pNewNode == NULL)
			{
				printf("pNewNode dynamic allocation is failed !! -- addCCL_Element() \n");
				return ret;
			}
			*pNewNode = element;
			pPreNode = &(pList->headerNode);
			for (i = 0; i < position; i++)
			{
				pPreNode = pPreNode->pLink;
			}
			pNewNode->pLink = pPreNode->pLink;
			pPreNode->pLink = pNewNode;
			pList->currentElementCount++;
			ret = TRUE;
		}
		else
		{
			printf("Error, position is out of range !! - addCCL_Element() \n");
		}
		
	}
	else
	{
		printf("Error, pList is Empty List ! -- addCCL_Element() \n");
	}

	return ret;
}

int removeCCL_Element(CircularList *pList, int position)
{
	CircularListNode *pPreNode = NULL, *pDelNode = NULL;
	int ret = FALSE, i = 0, arrayCount = 0;

	if (pList != NULL)
	{
		arrayCount = pList->currentElementCount;
		if (position >= 0 && position <= arrayCount)
		{
			pPreNode = &(pList->headerNode);
			
			for (i = 0; i < position; i++)
			{
				pPreNode = pPreNode->pLink;
			}
			pDelNode = pPreNode->pLink;
			pPreNode->pLink = pDelNode->pLink;

			SAFE_FREE(pDelNode);
			pList->currentElementCount--;

			ret = TRUE;
		}
		else
		{
			printf("Error, position is out of range -- removeCCL_Element() \n");
		}
	}
	else
	{
		printf("Error, pList is Empty !! - removeCCL_Element() \n");
	}
	
	return ret;
}

void deleteCCList(CircularList *pList)
{
	if (pList != NULL)
	{
		if (pList->currentElementCount > 0)
		{
			clearCCList(pList);
		}
		SAFE_FREE(pList);
	}
	else
	{
		printf("Error, pList is Empty List ! - deleteCCList() \n");
	}
}

void clearCCList(CircularList *pList)
{
	if (pList != NULL)
	{
		while (pList->currentElementCount > 0)
		{
			removeCCL_Element(pList, 0);
		}
	}
	else
	{
		printf("Error, pList is Empty !! - clearCCList() \n");
	}
}

void displayCCList(CircularList *pList)
{
	CircularListNode *pNode = NULL;
	int i = 0;


	if (pList != NULL)
	{
		printf("\n--- displayCCList !! --- \n\n");
		pNode = pList->headerNode.pLink;
		for (i = 0; i < pList->currentElementCount; i++)
		{
			printf("[%d] : %d \n", i, pNode->data);
			pNode = pNode->pLink;
		}
	}
	else
	{
		printf("pList is Empty !! - displayCCList() \n");
	}
}