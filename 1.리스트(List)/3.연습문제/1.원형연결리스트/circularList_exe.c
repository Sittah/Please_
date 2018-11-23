/*
원형연결 리스트의 구현 ( 헤더 노드를 이용 )

원형연결리스트 : 단방향으로 연결 되어 있는 형식을 띈 연결리스트 이지만 마지막노드의 다음 노드는 첫 노드이다 !

ㅁ - ㅁ - ㅁ - ㅁ   --> 단 방향 이동
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