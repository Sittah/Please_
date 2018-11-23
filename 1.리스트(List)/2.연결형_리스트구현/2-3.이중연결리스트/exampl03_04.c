#include <stdio.h>
#include "doublylist.h";

void displayDoublyList(DoublyList *pList)
{
	int arrayCount = 0, i = 0;
	DoublyListNode *pNode = NULL;
	if (pList != NULL)
	{
		pNode = &(pList->headerNode);
		arrayCount = pList->currentElementCount;

		for (i = 0; i < arrayCount; i++)
		{
			pNode = pNode->pRLink;
			printf("%d 번째 노드의 값 : %d  \n", i, pNode->data);
		}
	}
	else
	{
		printf("Error, pList is Empty !! - displayDoublyList() \n");
	}
}
int main()
{
	DoublyList *pList = NULL;
	DoublyListNode node = { 0, };

	pList = createDoublyList();

	if (pList != NULL)
	{
		node.data = 1;
		addDLElement(pList, 0, node);

		node.data = 3;
		addDLElement(pList, 1, node);

		node.data = 5;
		addDLElement(pList, 2, node);

		displayDoublyList(pList);

		removeDLElement(pList, 0);

		displayDoublyList(pList);

		printf("pList : %x \n", pList);

		deleteDoublyList(pList);

		SAFE_RELEASE(&pList);

		displayDoublyList(pList);

		printf("pList : %x \n", pList);
	}


	return 0;
}