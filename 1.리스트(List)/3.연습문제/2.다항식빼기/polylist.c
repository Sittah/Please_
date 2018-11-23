#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList1.h";
#include "polylist.h";

/* poly = polynomial (다항식) */
int addPolyNodeLast(LinkedList *pList, float coef, int degree)
{
	int ret = FALSE, i = 0;

	ListNode node = { 0, };
	node.coef = coef;
	node.degree = degree;

	if (pList != NULL)
	{
		int length = pList->currentElementCount;
		ret = addLinkedListElement(pList, length, node);
	}

	return ret;
}

LinkedList* polyAdd(LinkedList *pListA, LinkedList *pListB)
{
	LinkedList *pReturnList = NULL;
	ListNode *pNodeA = NULL, *pNodeB = NULL;
	float coefSum = 0;
	int degreeA = 0, degreeB = 0;

	if (pListA != NULL && pListB != NULL)
	{
		pReturnList = createLinkedList();

		if (pReturnList == NULL)
		{
			printf("error, pReturnList is Empty !! -- polyAdd() \n");
			return NULL;
		}
		
		pNodeA = pListA->headerNode.pLink;
		pNodeB = pListB->headerNode.pLink;
		while (pNodeA != NULL & pNodeB != NULL)
		{
			degreeA = pNodeA->degree;
			degreeB = pNodeB->degree;

			if (degreeA > degreeB)
			{
				coefSum = pNodeA->coef;
				addPolyNodeLast(pReturnList, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
			}
			else if (degreeA == degreeB)
			{
				coefSum = pNodeA->coef + pNodeB->coef;
				addPolyNodeLast(pReturnList, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
				pNodeB = pNodeB->pLink;
			}
			else
			{
				coefSum = pNodeB->coef;
				addPolyNodeLast(pReturnList, coefSum, degreeB);
				pNodeB = pNodeB->pLink;
			}
		}

		// 나머지 남은 차수(노드) 추가
		while (pNodeA != NULL)
		{
			addPolyNodeLast(pReturnList, pNodeA->coef, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}

		while (pNodeB != NULL)
		{
			addPolyNodeLast(pReturnList, pNodeB->coef, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}

	}
	else
	{
		printf("Error, pListA or pListB is Empty !! - polayAdd() \n");
	}

	return pReturnList;
}

LinkedList *polySub(LinkedList *pListA, LinkedList *pListB)
{
	LinkedList *pReturnList = NULL;
	ListNode *pNodeA = NULL, *pNodeB = NULL;
	int degreeA = 0, degreeB = 0, coefSub = 0;

	if (pListA != NULL && pListB != NULL)
	{
		pReturnList = createLinkedList();
		if (pReturnList == NULL)
		{
			printf("Error, pReturnList dynamic allocation is failled!! -- polySub() \n");
			return NULL;
		}
		pNodeA = pListA->headerNode.pLink;
		pNodeB = pListB->headerNode.pLink;
		while (pNodeA != NULL && pNodeB != NULL)
		{
			degreeA = pNodeA->degree;
			degreeB = pNodeB->degree;

			if (degreeA > degreeB)
			{
				coefSub = pNodeA->coef;
				addPolyNodeLast(pReturnList, coefSub, degreeA);
				pNodeA = pNodeA->pLink;
			}
			else if (degreeA == degreeB)
			{
				coefSub = pNodeA->coef - pNodeB->coef;
				addPolyNodeLast(pReturnList, coefSub, degreeA);
				pNodeA = pNodeA->pLink;
				pNodeB = pNodeB->pLink;
			}
			else
			{
				coefSub = pNodeB->coef;
				addPolyNodeLast(pReturnList, coefSub, degreeB);
				pNodeB = pNodeB->pLink;
			}
		}

		// A 와 B 둘중하나는 노드를 모두 소진했고,, 혹시나 남아있을 노드를 체크해서 계산해준다.

		while (pNodeA != NULL)
		{
			addPolyNodeLast(pReturnList, pNodeA->coef, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}

		while (pNodeB != NULL)
		{
			addPolyNodeLast(pReturnList, pNodeB->coef, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}

	}
	else
	{
		printf("Error, pListA or pListB is Empty !! --polySub() \n");
	}

	return pReturnList;
}
void displayPoly(LinkedList *pList)
{
	ListNode *pNode = NULL;
	int count = 0;
	if (pList != NULL)
	{
		pNode = pList->headerNode.pLink;
		while (pNode != NULL)
		{
			printf("%4.1fx^%d", pNode->coef, pNode->degree);
			pNode = pNode->pLink;

			if (count == pList->currentElementCount - 1)
			{
				printf(" \n ");
			}
			else
			{
				printf(" + ");
			}
			count++;
		}
	}
	else
	{
		printf("Error, pList is Empty !! - displayPoly() \n");
	}
}