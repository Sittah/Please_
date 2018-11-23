/*
�������� ����Ʈ�� ���� ( ��� ��带 �̿� )

�������Ḯ��Ʈ : �ܹ������� ���� �Ǿ� �ִ� ������ �� ���Ḯ��Ʈ ������ ����������� ���� ���� ù ����̴� !

�� - �� - �� - ��   --> �� ���� �̵�
^			   |
|______________v

*/

#include <stdio.h>
#include "circularList.h";

int main(int argc, char* argv[])
{
	CircularList *pList = NULL;
	CircularListNode node = { 0, };

	pList = createCCList();

	if (pList != NULL)
	{
		node.data = 1;
		addCCL_Element(pList, 0, node);
		node.data = 2;
		addCCL_Element(pList, 1, node);
		node.data = 3;
		addCCL_Element(pList, 2, node);

		displayCCList(pList);

		printf("\n remove !! \n");

		removeCCL_Element(pList, 2);

		displayCCList(pList);


		printf("\n clear !! \n");
		clearCCList(pList);

		displayCCList(pList);

		printf("\n delete !! \n");

		SAFE_DEL_LIST(pList);

		displayCCList(pList);
	}
	else
	{
		printf("Error, pList is Empty !! - main() \n");
	}
	pList = NULL;

	return 0;
}