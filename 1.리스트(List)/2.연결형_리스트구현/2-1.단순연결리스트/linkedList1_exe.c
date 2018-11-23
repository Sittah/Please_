/*
�ܼ� ���� ����Ʈ�� ����

�ܼ����Ḯ��Ʈ : �ܹ������� ���� �Ǿ� �ִ� ������ �� ���Ḯ��Ʈ �̴�.

�� - �� - �� - ��   --> �� ���� �̵�

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

