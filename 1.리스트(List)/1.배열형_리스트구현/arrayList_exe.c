#include <stdio.h>
#include "arrayList.h";
/*
	�迭�� ����Ʈ�� ���� 

	�迭�� ����Ʈ�� Ư¡�� 

	1. �迭�������� �����Ҵ��� �ϱ� ������ �޸𸮻󿡼��� ������ �پ� �ִ� ������ ���.

*/

int main()
{
	ArrayList * arrayList1 = createList(6);

	ArrayListNode  arrayListNode1;
	arrayListNode1.data = 1;
	addElement(arrayList1, 0, arrayListNode1);
	arrayListNode1.data = 2;
	addElement(arrayList1, 1, arrayListNode1);
	arrayListNode1.data = 3;
	addElement(arrayList1, 2, arrayListNode1);
	arrayListNode1.data = 4;
	addElement(arrayList1, 1, arrayListNode1);
	displayArrayList(arrayList1);

	printf("\n ���� ���� \n");

	removeElement(arrayList1, 0);

	displayArrayList(arrayList1);

	printf("\n �迭 Clear \n");

	clearArrayList(arrayList1);

	displayArrayList(arrayList1);

	return 0;
}