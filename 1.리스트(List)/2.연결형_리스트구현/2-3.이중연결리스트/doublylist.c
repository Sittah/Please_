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

				pNewNode->pLLink = pPreNode;			// ������� �� ��带 ����
				pNewNode->pRLink = pPreNode->pRLink;// ������� ���� ��带 ������� �������� ����
				pPreNode->pRLink = pNewNode;			// �� ����� ���� ��带 ������ ����
				pNewNode->pRLink->pLLink = pNewNode;	// ������� ���� ����� ��������� �� ���

				pList->currentElementCount++;
				ret = TRUE;

														/* ��, ��� - 2 - (�����) - 3 - 4 ��尡 �ְ�
														 �������� 1�� �޾ƿԴٸ�

													   for ������ pPreNode = 2�� ��尡 �ȴ�
													   (1) �� ����� ���� ���� 2�� ���
													   (2) �� ����� ���� ���� 3�� ��� (2������� ����)
													   (3) ���� ���(2��)�� ���� ���� �� ���(newNode)
													   (4) ������� ������� (3)�� ������� (������ 3�� �������� 2 ������) = �����
															
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

			// ���� �ϴ� ����
			// 1. ������ ����� ������� pPreNode �� ���� �Ѵ�.
			// 2. ������ ��带 �����Ѵ� pRemoveNode = pPreNode -> pRLink;
			// 3. ���� ����� ������带 pRemoveNode -> pRLink;
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
