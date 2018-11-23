#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularList.h";

circularList *createCircularList()
{
	circularList *pList = NULL; /* ó�� �ʱ�ȭ�� ���־�� NULL üũ�� ��ȿ�� �� �ִ�. */

	pList = (circularList *)malloc(sizeof(circularList));

	if (pList != NULL)
	{
		memset(pList, 0, sizeof(circularList));

	}
	else
	{
		printf("Error, Dynamic allocation is failed !! - createCircularList() \n");
	}

	printf("createList ������ pList : %x , &pList : %x \n\n", pList, &pList);
	return pList;
}

int addCLElement(circularList *pList, int position, circularListNode element)
{
	int ret = FALSE, i=0;
	circularListNode *pNewNode = NULL, *pPreNode = NULL, *pLastNode = NULL;

	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentListCount)
		{
			pNewNode = (circularListNode *)malloc(sizeof(circularListNode));

			if (pNewNode == NULL)
			{
				printf("pNewNode malloc failed !! - addCLElement() \n");
				return ret;
			}

			*pNewNode = element;
			pNewNode->pLink = NULL;

			if (position == 0)
			{
				if (pList->currentListCount == 0)
				{
					pList->pLink = pNewNode;  /* ��� �����Ͱ� ����Ű�� ù��° ��带 ����*/
					pNewNode->pLink = pNewNode; /* ��������Ʈ�� ��ŭ ù ��尡 ù��带 ����Ų�� */
				}
				else
				{
					pLastNode = pList->pLink;

					/*
					������ ��带 ���ؾ� �Ѵ�
					������ ����� ���� �� (���� ���)�� ���۳�尡
					������ Ȯ�������μ�
					������ ��带 ���� �� �ִ�. */
					while (pLastNode->pLink != pPreNode)
					{
						pLastNode = pLastNode->pLink;
					}
					pNewNode->pLink = pList->pLink;		/* ���� ù��带  ����� �ڷ� ������ */
					pList->pLink = pNewNode;			/* pList -> pLink �� ������ ��ü */
					pLastNode->pLink = pNewNode;		/* ������ ����� ������ (ó����尪)�� �� ���� ��ü*/

				}
			}
			else
			{
				// position�� 0 �� �ƴҶ�
				pPreNode = pList->pLink;
				for (i = 0; i < position - 1; i++)
				{
					pPreNode = pPreNode->pLink;
				}
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
			}
			pList->currentListCount++;
			ret = TRUE;

		}
		else
		{
			printf("Out Of Range - addCLElement() \n");
		}
	}
	else
	{
		printf("pList is Empty ! - addCLElement() \n");
	}

	return ret;
}

int removeCLElement(circularList *pList, int position)
{
	int ret = FALSE;
	int i = 0, arrayCount = 0;
	circularListNode *pRemoveNode = NULL, *pPreRemoveNode = NULL, *pLastNode = NULL;
	if (pList != NULL)
	{
		arrayCount = pList->currentListCount;
		if (position >= 0 && position < arrayCount)	/* position < arratCount ���� : ���� ��尳���� 0���϶��� �۵����� �ʰ� �ϱ� ����*/
		{
			if (position == 0)
			{
				pRemoveNode = pList->pLink;					// ������ ���� ù���

				/* ��尡 1������ ����Ʈ�϶� */
				if (arrayCount == 1)
				{
					pRemoveNode->pLink = NULL;
					pList->pLink = NULL;
				}
				else
				{
					pLastNode = pList->pLink;					// ������ ��带 ã������ ���

					while (pLastNode->pLink != pList->pLink)		// ����������� �������(ù���) �� ù���� ������ ���� ã��
					{
						pLastNode = pLastNode->pLink;
					}
					pLastNode->pLink = pRemoveNode->pLink;		//������ ����� �������(ù���) �� ������ ��� ���� ���� ����
					pList->pLink = pRemoveNode->pLink;			// ù��带 ������ ����� �������� ����
				}
			}
			else
			{
				pPreRemoveNode = pList->pLink;
		
				/* ������ ����� �ٷ� �� ���(��ġ) �� ���� */
				for (i = 0; i < position - 1; i++)
				{
					pPreRemoveNode = pRemoveNode->pLink;
				}
				pRemoveNode = pPreRemoveNode->pLink;			// ������ ��带 ����
				pPreRemoveNode->pLink = pRemoveNode->pLink;	// ������ ��� ���� ����� ������带 ������ ��� ���� ���� ����
			}

			free(pRemoveNode);
			pList->currentListCount--;
			ret = TRUE;
		}
		else
		{
			printf("position is out of range ! - \n");
		}
	}
	else
	{
		printf("Error, pList is Empty !! \n");
	}

	return ret;
}


void clearCircularList(circularList *pList)
{
	if (pList != NULL)
	{
		while (pList->currentListCount > 0)
		{
			removeCLElement(pList, 0);
		}
	}
	else
	{
		printf("Error, pList is Empty ! -- clearCircularList() \n");
	}
}
/*
// ���� �ҽ����� ���ϴ� ��� �ε� .. 
// �̷��� ó���� �ϰԵǸ� ���߿� �����Լ����� �ٸ� ����� ����������
// pList�� NULL �� �νĵ��� �ʰ� �ɷ����� �ʴ´�.
// �ؿ��ִ� ������ �Լ��� ����ϸ� NULL�� �νĵǰ� �ɷ�����.

void deleteCircularList(circularList *pList)
{

	printf("deleteCircularList() pList �ּ� : %x , &pList : %x\n\n", pList, &pList);

	if (pList != NULL)
	{
		clearCircularList(pList);
		pList = NULL;
		//printf("deleteCircularList() pList �ּ� : %x \n", pList);
		free(pList);
	}
	else
	{
		printf("Error, pList is Empyty !! -- deleteCircularList() \n");
	}
}
*/

void deleteCircularList(circularList **ppList)
{

	printf("deleteCircularList() ppList �ּ� : %x , &ppList : %x  , *ppList : %x , &(*ppList) : %x \n\n", ppList, &ppList, *ppList, &(*ppList));

	if (*ppList != NULL)
	{
		clearCircularList(*ppList);
		*ppList = NULL;
		//printf("deleteCircularList() pList �ּ� : %x \n", pList);
		free(*ppList);
	}
	else
	{
		printf("Error, pList is Empyty !! -- deleteCircularList() \n");
	}
}
