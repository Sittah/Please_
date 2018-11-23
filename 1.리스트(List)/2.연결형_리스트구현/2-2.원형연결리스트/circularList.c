#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularList.h";

circularList *createCircularList()
{
	circularList *pList = NULL; /* 처음 초기화를 해주어야 NULL 체크가 유효할 수 있다. */

	pList = (circularList *)malloc(sizeof(circularList));

	if (pList != NULL)
	{
		memset(pList, 0, sizeof(circularList));

	}
	else
	{
		printf("Error, Dynamic allocation is failed !! - createCircularList() \n");
	}

	printf("createList 에서의 pList : %x , &pList : %x \n\n", pList, &pList);
	return pList;
}

int addCLElement(circularList *pList, int position, circularListNode element)
{
	int ret = FALSE, i=0;
	circularListNode *pNewNode = NULL, *pPreNode = NULL, *pLastNode = NULL;

	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->currentListCount)
		{
			pNewNode = (circularListNode *)malloc(sizeof(circularListNode));

			if (pNewNode == NULL)
			{
				printf("pNewNode malloc failed !! - addCLElement() \n");
				return ret;
			}

			*pNewNode = element;
			pNewNode->pLink = NULL;

			if (position == 0)
			{
				if (pList->currentListCount == 0)
				{
					pList->pLink = pNewNode;  /* 헤드 포인터가 가르키는 첫번째 노드를 설정*/
					pNewNode->pLink = pNewNode; /* 원형리스트인 만큼 첫 노드가 첫노드를 가르킨다 */
				}
				else
				{
					pLastNode = pList->pLink;

					/*
					마지막 노드를 구해야 한다
					마지막 노드의 다음 값 (시작 노드)와 시작노드가
					같은걸 확인함으로서
					마지막 노드를 구할 수 있다. */
					while (pLastNode->pLink != pPreNode)
					{
						pLastNode = pLastNode->pLink;
					}
					pNewNode->pLink = pList->pLink;		/* 기존 첫노드를  새노드 뒤로 보낸다 */
					pList->pLink = pNewNode;			/* pList -> pLink 를 새노드로 교체 */
					pLastNode->pLink = pNewNode;		/* 마지막 노드의 다음값 (처음노드값)을 새 노드로 교체*/

				}
			}
			else
			{
				// position이 0 이 아닐때
				pPreNode = pList->pLink;
				for (i = 0; i < position - 1; i++)
				{
					pPreNode = pPreNode->pLink;
				}
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
			}
			pList->currentListCount++;
			ret = TRUE;

		}
		else
		{
			printf("Out Of Range - addCLElement() \n");
		}
	}
	else
	{
		printf("pList is Empty ! - addCLElement() \n");
	}

	return ret;
}

int removeCLElement(circularList *pList, int position)
{
	int ret = FALSE;
	int i = 0, arrayCount = 0;
	circularListNode *pRemoveNode = NULL, *pPreRemoveNode = NULL, *pLastNode = NULL;
	if (pList != NULL)
	{
		arrayCount = pList->currentListCount;
		if (position >= 0 && position < arrayCount)	/* position < arratCount 이유 : 현재 노드개수가 0개일때는 작동하지 않게 하기 위함*/
		{
			if (position == 0)
			{
				pRemoveNode = pList->pLink;					// 제거할 노드는 첫노드

				/* 노드가 1개뿐인 리스트일때 */
				if (arrayCount == 1)
				{
					pRemoveNode->pLink = NULL;
					pList->pLink = NULL;
				}
				else
				{
					pLastNode = pList->pLink;					// 마지막 노드를 찾기위한 노드

					while (pLastNode->pLink != pList->pLink)		// 마지막노드의 다음노드(첫노드) 가 첫노드랑 같을때 까지 찾기
					{
						pLastNode = pLastNode->pLink;
					}
					pLastNode->pLink = pRemoveNode->pLink;		//마지막 노드의 다음노드(첫노드) 를 제거할 노드 다음 노드로 설정
					pList->pLink = pRemoveNode->pLink;			// 첫노드를 제거할 노드의 다음노드로 설정
				}
			}
			else
			{
				pPreRemoveNode = pList->pLink;
		
				/* 제거할 노드의 바로 전 노드(위치) 로 가기 */
				for (i = 0; i < position - 1; i++)
				{
					pPreRemoveNode = pRemoveNode->pLink;
				}
				pRemoveNode = pPreRemoveNode->pLink;			// 삭제할 노드를 설정
				pPreRemoveNode->pLink = pRemoveNode->pLink;	// 삭제할 노드 이전 노드의 다음노드를 삭제할 노드 다음 노드로 변경
			}

			free(pRemoveNode);
			pList->currentListCount--;
			ret = TRUE;
		}
		else
		{
			printf("position is out of range ! - \n");
		}
	}
	else
	{
		printf("Error, pList is Empty !! \n");
	}

	return ret;
}


void clearCircularList(circularList *pList)
{
	if (pList != NULL)
	{
		while (pList->currentListCount > 0)
		{
			removeCLElement(pList, 0);
		}
	}
	else
	{
		printf("Error, pList is Empty ! -- clearCircularList() \n");
	}
}
/*
// 원본 소스에서 취하는 방식 인데 .. 
// 이렇게 처리를 하게되면 나중에 메인함수에서 다른 기능을 동작했을때
// pList가 NULL 로 인식되지 않고 걸러지지 않는다.
// 밑에있는 형식의 함수를 사용하면 NULL로 인식되고 걸러진다.

void deleteCircularList(circularList *pList)
{

	printf("deleteCircularList() pList 주소 : %x , &pList : %x\n\n", pList, &pList);

	if (pList != NULL)
	{
		clearCircularList(pList);
		pList = NULL;
		//printf("deleteCircularList() pList 주소 : %x \n", pList);
		free(pList);
	}
	else
	{
		printf("Error, pList is Empyty !! -- deleteCircularList() \n");
	}
}
*/

void deleteCircularList(circularList **ppList)
{

	printf("deleteCircularList() ppList 주소 : %x , &ppList : %x  , *ppList : %x , &(*ppList) : %x \n\n", ppList, &ppList, *ppList, &(*ppList));

	if (*ppList != NULL)
	{
		clearCircularList(*ppList);
		*ppList = NULL;
		//printf("deleteCircularList() pList 주소 : %x \n", pList);
		free(*ppList);
	}
	else
	{
		printf("Error, pList is Empyty !! -- deleteCircularList() \n");
	}
}
