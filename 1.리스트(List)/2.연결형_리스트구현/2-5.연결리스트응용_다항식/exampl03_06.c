#include <stdio.h>
#include <stdlib.h>
#include "linkedList1.h";
#include "polylist.h";


int main(int argc, char* argv[])
{
	LinkedList *pListA = NULL, *pListB = NULL, *pListC = NULL;

	pListA = createLinkedList();
	pListB = createLinkedList();

	if (pListA != NULL && pListB != NULL)
	{
		//pListA : 6x^6 + 4x^5 + 2x^2
		//pListB : 1x^5 + 2x^4 + 3x^2 + 4x^0
		addPolyNodeLast(pListA, 6, 6);
		addPolyNodeLast(pListA, 4, 5);
		addPolyNodeLast(pListA, 2, 2);

		printf("\npListA display !! \n\n");
		displayPoly(pListA);

		addPolyNodeLast(pListB, 1, 5);
		addPolyNodeLast(pListB, 2, 4);
		addPolyNodeLast(pListB, 3, 2);
		addPolyNodeLast(pListB, 4, 0);

		printf("\npListB display !! \n\n");
		displayPoly(pListB);

		printf("\npoly Add !! pListA And pListB \n\n");
		pListC = polyAdd(pListA, pListB);
		if (pListC != NULL)
		{
			displayPoly(pListC);
			SAFE_DELETE_LIST(pListC);

		}
		else
		{
			printf("pListC dynamic allocation is failed!! -- main() \n");
		}
	}
	else
	{
		printf("pListA or pListB is Empty !! - main() \n");
	}

	SAFE_DELETE_LIST(pListA);
	SAFE_DELETE_LIST(pListB);

	return 0;
}