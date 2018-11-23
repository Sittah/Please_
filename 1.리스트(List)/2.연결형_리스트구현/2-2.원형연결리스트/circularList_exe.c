/*
�������� ����Ʈ�� ����

�������Ḯ��Ʈ : �ܹ������� ���� �Ǿ� �ִ� ������ �� ���Ḯ��Ʈ ������ ����������� ���� ���� ù ����̴� !

�� - �� - �� - ��   --> �� ���� �̵�
^			   |
|______________v

*/

#include <stdio.h>
#include "circularList.h";


void printElements(circularList *pList)
{
	circularListNode *pStartNode = NULL, *pLastNode = NULL;
	int i = 0;
	if (pList != NULL)
	{
		pStartNode = pList->pLink;
		printf("���� ����� ���� : %d \n", pList->currentListCount);
		printf("�׽�Ʈ : %x \n", pList->pLink);
		for (i = 0; i < pList->currentListCount; i++)
		{
			printf("%d ��° ��� �� : %d \n", i, pStartNode->element);
			pStartNode = pStartNode->pLink;
		}
	}
	else
	{
		printf("Error, pList is Empty ! - printElement() \n");
	}
}
int main()
{
	circularList *pList = NULL;
	circularListNode node;

	pList = createCircularList();
	printf("���� �� ù pList �ּ� : %x , &pList(������ ��ü�� �ּ�) : %x \n\n", pList, &pList);

	node.element = 1;
	addCLElement(pList, 0, node);
	node.element = 3;
	addCLElement(pList, 1, node);
	node.element = 5;
	addCLElement(pList, 2, node);


	//printf("%d ,, %x \n", pList->pLink->element, &(pList->pLink->element));
	//printf("%d ,, %x \n", pList->pLink->pLink->element, &(pList->pLink->pLink->element));
	printElements(pList);

	clearCircularList(pList);
	printElements(pList);

	//removeCLElement(pList, 0);

	deleteCircularList(&pList);
	printElements(pList);

	printf("������ pList : %x , &pList : %x \n", pList, &pList);

	//printf("%d ,, %x \n", pList->pLink->element, &(pList->pLink->element));
	//printf("%d ,, %x \n", pList->pLink->pLink->element, &(pList->pLink->pLink->element));
	return 0;
}


