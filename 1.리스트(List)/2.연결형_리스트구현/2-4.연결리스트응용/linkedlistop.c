#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList1.h";
#include "linkedlistop.h";


/*
	iterateLinkedList 

		��   ������ ���� position ���� �̵� �ϰ��� ��� �ϴ°� �ƴ�
			��������͹��ó�� *pNode �� ù ���۳�带 ��� �ű⼭ ���� �����͸� ����Ѵ�
			*/
void iterateLinkedList(LinkedList *pList)
{
	ListNode *pNode = NULL;
	int count = 0;
	if (pList != NULL)
	{
		pNode = pList->headerNode.pLink; // ���� &(pList->headerNode) �� �ٸ� �κ��̴�

		while (pNode != NULL)
		{
			printf("[%d] , %d \n", count, pNode->data);
			count++;
			pNode = pNode->pLink;
		}
		printf("��� ���� : %d \n", count);
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
			pPreNode = pCurrentNode;		//������� ���� 
			pCurrentNode = pNode;			//������ ����
			pNode = pNode->pLink;			//��ȸ��� ��������
			pCurrentNode->pLink = pPreNode;	//�������� �������� �������� ����
			/*
				1 - 2 - 3 - 4

				(1) ������带 �������  
				(2) �����带 ��ȯ����
				(3) ��ȯ��带 ��������
				(4) �������� ������带 ��������
				pPreNode = pCurrentNode;		//������� ���� 
				pCurrentNode = pNode;			//������ ����
				pCurrentNode->pLink = pPreNode;	//�������� �������� �������� ����
				pNode = pNode->pLink;			//��ȸ��� ��������

				�̷��� ������ �ٲٸ� �ȵǴ� ����

				& 2��° �ٿ��� pCurrentNode = pNode; �� ��Ȳ����
				pCurrentNode->pLink = pPreNode == pNode->pLink = pPreNode;
				�� ���� ��Ȳ�� �Ǿ� ������.
				�׷��� pNode->pLink = NULL�� �����Ŀ� pNode = pNode -> pLink �� �ϸ�
				pNode = NULL; �� �Ǿ�����鼭 ������ �ٷ� ���ܹ�����.

				������

				
			*/
			
		}
		// pNode �� NULL�� ����Ű�� ���� pPreNode �� NULL�� �ٷ������� // �� ������ ��带 ����Ŵ
		pList->headerNode.pLink = pCurrentNode;

		printf("pList ��尳�� : %d \n", pList->currentElementCount);
	}
	else
	{
		printf("Error, pList is Empty ! -- reverseLinkedList() \n");
	}
}