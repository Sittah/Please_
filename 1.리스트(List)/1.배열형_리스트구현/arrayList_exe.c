#include <stdio.h>
#include "arrayList.h";
/*
	배열형 리스트의 구현 

	배열형 리스트의 특징은 

	1. 배열형식으로 동적할당을 하기 때문에 메모리상에서도 실제로 붙어 있는 형식을 띈다.

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

	printf("\n 삭제 진행 \n");

	removeElement(arrayList1, 0);

	displayArrayList(arrayList1);

	printf("\n 배열 Clear \n");

	clearArrayList(arrayList1);

	displayArrayList(arrayList1);

	return 0;
}