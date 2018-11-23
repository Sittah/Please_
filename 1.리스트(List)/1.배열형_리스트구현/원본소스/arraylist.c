#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount) {
	ArrayList *pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = (ArrayList *)malloc(sizeof(ArrayList));

		// 구조체 ArrayList 값 초기화 
		if (pReturn != NULL) {
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("오류, 메모리할당 createArrayList()\n");
			return NULL;
		}
	}
	else {
		printf("오류, 최대 원소 개수는 0이상이어야 합니다\n");
		return NULL;
	}

	pReturn->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (pReturn->pElement == NULL) {
		printf("오류, 2번째 메모리할당 createArrayList()\n");
		free(pReturn); return NULL;
	}
	// 동적할당한 pReturn의 값들을 초기화
	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

	return pReturn;
}

int addALElement(ArrayList* pList, int position, ArrayListNode element) {
	int ret = FALSE;
	int i=0;

	if (pList != NULL) {
		if (isArrayListFull(pList) != TRUE) { /* 최대원소 만큼 가득차지는 않았는지 확인 */
			/* position(인덱스 위치) 는 >= 0 여야 하고 현재 들어있는 배열의 최대 인덱스
				ex) 3개의 배열이 들어있다면 0 1 2  3을 넘어서는 안된다 
					4가 들어가면 0 1 2 공백 4 형식으로 이어지지 않는 값의 배열이 되기 때문 */
			if (position >= 0
				&& position <= pList->currentElementCount)
			{
				/* 배열의 개수가 3개라고 가정 할때 실제 배열 마지막값은 배열[2] 이다 
					따라서 , pList->currentElemnetCount - 1을 해주고 i 값을 -- 한다.
					한칸씩 오른쪽으로 옮기는 작업 <
				*/
				for(i = pList->currentElementCount-1; i >= position; i--) {
					pList->pElement[i+1] = pList->pElement[i];
				}
				/*	넣고싶은 위치(position)에 이르면 (포지션값이 i보다 크거나 같아지면)
					포지션 위치에 받아온 값을 넣는다
				*/
				pList->pElement[position] = element;
				pList->currentElementCount++;	/* 현재 값 개수 추가  */
				
				ret = TRUE;
			}
			else {
				printf("오류, 위치 인덱스-[%d] 범위 초과, addALElement()\n",
						position);
			}
		}
		else {
			printf("오류, 리스트 용량 초과-[%d]/[%d]\n", 
					position, pList->maxElementCount);
		}
	}

	return ret;
}

int removeALElement(ArrayList* pList, int position) {
	int ret = FALSE;
	int i=0;

	if (pList != NULL) {
		if (position >= 0 
				&& position < pList->currentElementCount) {
			for(i = position; i < pList->currentElementCount-1; i++) {
				pList->pElement[i] = pList->pElement[i+1];
			}
			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("오류, 위치 인덱스-[%d] 범위 초과, removeALElement()\n",
					position);
		}
	}

	return ret;
}

ArrayListNode* getALElement(ArrayList* pList, int position) {
	ArrayListNode* pReturn = NULL;
	if (pList != NULL) {
		if (position >=0 && position < getArrayListLength(pList)) {
			pReturn = &(pList->pElement[position]);
		}
		else {
			printf("오류, 위치 인덱스-[%d] 범위 초과, getALElement()\n", position);
		}
	}

	return pReturn;
}

void displayArrayList(ArrayList* pList) {
	int i = 0;
	if (pList != NULL) {
		printf("최대 원소 개수: %d\n", pList->maxElementCount);
		printf("현재 원소 개수: %d\n", pList->currentElementCount);

		for(i = 0; i < pList->currentElementCount; i++) {
			printf("[%d],%d\n", i, getALElement(pList, i)->data);
		}
		
		i = pList->currentElementCount;
		for(; i < pList->maxElementCount; i++) {
			printf("[%d],Empty\n", i);
		}
	}
	else {
		printf("ArryList is NULL");
	}
}

int isArrayListFull(ArrayList* pList) {
	int ret = FALSE;

	if (pList != NULL) {
		if (pList->currentElementCount == pList->maxElementCount) {
			ret = TRUE;
		}
	}

	return ret;
}

int getArrayListLength(ArrayList* pList) {
	int ret = 0;

	if (pList != NULL) {
		ret = pList->currentElementCount;
	}

	return ret;
}

void deleteArrayList(ArrayList* pList)
{
	int i = 0;
	if (pList != NULL) {
		free(pList->pElement);
		free(pList);
	}
}
