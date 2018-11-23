/*
원형연결 리스트의 구현

원형연결리스트 : 단방향으로 연결 되어 있는 형식을 띈 연결리스트 이지만 마지막노드의 다음 노드는 첫 노드이다 !

ㅁ - ㅁ - ㅁ - ㅁ   --> 단 방향 이동
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
		printf("현재 노드의 개수 : %d \n", pList->currentListCount);
		printf("테스트 : %x \n", pList->pLink);
		for (i = 0; i < pList->currentListCount; i++)
		{
			printf("%d 번째 노드 값 : %d \n", i, pStartNode->element);
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
	printf("생성 후 첫 pList 주소 : %x , &pList(포인터 자체의 주소) : %x \n\n", pList, &pList);

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

	printf("마지막 pList : %x , &pList : %x \n", pList, &pList);

	//printf("%d ,, %x \n", pList->pLink->element, &(pList->pLink->element));
	//printf("%d ,, %x \n", pList->pLink->pLink->element, &(pList->pLink->pLink->element));
	return 0;
}


