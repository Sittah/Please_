/*
단순 연결 리스트의 구현

단순연결리스트 : 단방향으로 연결 되어 있는 형식을 띈 연결리스트 이다.

ㅁ - ㅁ - ㅁ - ㅁ   --> 단 방향 이동

*/

#include <stdio.h>
#include "linkedList1.h";

int main()
{
	LinkedList * pList = NULL;
	ListNode* pNode = NULL;
	ListNode node;
	
	pList = createLinkedList();

	if (pList != NULL)
	{
		node.data = 1;
		addLinkedListElement(pList, 0, node);
		node.data = 3;
		addLinkedListElement(pList, 1, node);
		node.data = 5;
		addLinkedListElement(pList, 2, node);	//node.data = 3;
		node.data = 7;
		addLinkedListElement(pList, 1, node);

		displayList(pList);

		removeLinkedListElement(pList, 0);

		displayList(pList);
	}
	else
	{
		printf("pList is Empty !! - main() \n");
		return 0;
	}
	
	deleteLinkedList(pList);
	displayList(pList);
	return 0;
}

