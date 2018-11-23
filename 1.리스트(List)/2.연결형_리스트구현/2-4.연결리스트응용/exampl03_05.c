#include <stdio.h>
#include <stdlib.h>
#include "linkedlist1.h"
#include "linkedlistop.h"

int main(int argc, char *argv[])
{
	LinkedList *pListA = NULL, *pListB = NULL;
	int i = 0, arrayCount = 0;
	ListNode node;

	pListA = createLinkedList();
	pListB = createLinkedList();

	if (pListA != NULL && pListB != NULL)
	{
		node.data = 1;
		addLinkedListElement(pListA, 0, node);

		node.data = 2;
		addLinkedListElement(pListA, 1, node);

		node.data = 3;
		addLinkedListElement(pListA, 2, node);

		node.data = 4;
		addLinkedListElement(pListB, 0, node);

		node.data = 5;
		addLinkedListElement(pListB, 1, node);


		iterateLinkedList(pListA);
		iterateLinkedList(pListB);

		printf("\n----- concatLinkedList ! ---- \n\n");

		concatLinkedList(pListA, pListB);

		iterateLinkedList(pListA);


		printf("\n---- reverseLinkedList ! --- \n\n");

		reverseLinkedList(pListA);

		printf("\n --- after reverseLinkedList !! -- \n\n");

		iterateLinkedList(pListA);

		printf("Before Memory Free - pListA : %x, pListB : %x \n", pListA, pListB);

		printf("pList ¿« ¡÷º“ : %x \n\n", pListA);

		SAFE_DELETE_LIST(pListA);
		SAFE_DELETE_LIST(pListB);

		printf("After Memory Free - pListA : %x  pListB : %x \n", pListA, pListB);

	}
	else
	{
		printf("pListA or pListB is Empty !! - main() \n");
	}
	return 0;
}