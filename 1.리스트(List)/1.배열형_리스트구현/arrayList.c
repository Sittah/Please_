#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayList.h";

ArrayList * createList(int maxArray_Count)
{
	ArrayList *pnewArrayList = NULL;
	
	if (maxArray_Count > 0)
	{
		pnewArrayList = (ArrayList *)malloc(sizeof(ArrayList));
		if (pnewArrayList != NULL)
		{
			pnewArrayList->maxArray_Count = maxArray_Count;
			pnewArrayList->currentArray_Count = 0;
			pnewArrayList->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxArray_Count);

			if (pnewArrayList->pElement == NULL)
			{
				printf("Error, second memory allocation failed! createArrayList() \n");
				free(pnewArrayList);
			}
			memset(pnewArrayList->pElement, 0, sizeof(ArrayListNode) * maxArray_Count);
		}
		else
		{
			printf("Error, Memory Allocation Failed ! createArrayList() \n");
			return NULL;
		}
	}
	else
	{
		printf("Error, max count of array is bigger than zero ! \n");
		return NULL;
	}
	return pnewArrayList;
}

int addElement(ArrayList *parrayList, int position, ArrayListNode element)
{
	int ret = FALSE;
	int i = 0;

	if (parrayList != NULL)
	{
		if (isArrayListFull(parrayList) == FALSE)
		{
			if (position >= 0 && position <= parrayList->currentArray_Count)
			{
				/* �����ʿ��� ���� ��ĭ�� ���������� �ű�鼭 position �ڸ����� �ݺ��Ѵ�. */
				for (i = parrayList->currentArray_Count - 1; i >= position; i--)
				{
					parrayList->pElement[i + 1] = parrayList->pElement[i];
				}

				parrayList->pElement[position] = element;
				parrayList->currentArray_Count++;
				ret = TRUE;
			}
			else
			{
				printf("Error, range of position index is exceeded! addAlement() \n ");
			}

		}
		else
		{
			printf("Error, ArrayList is Full addElement() \n");
		}
	}
	else
	{
		printf("Error , arrayList is EMPTY (NULL) addElement() \n");
	}

	return ret;
}

int isArrayListFull(ArrayList * parrayList)
{
	int ret = FALSE;
	if (parrayList != NULL)
	{

	}
	else
	{
		printf("Error, arrayList is Empty - isArrayListFull() \n");
		return FALSE;
	}

	return ret;
}

int removeElement(ArrayList *parrayList, int position)
{
	int ret = FALSE;
	int i = 0;
	if (parrayList != NULL)
	{
		if (position >= 0 && position < parrayList->currentArray_Count)
		{
			for (i = position; i <= parrayList->currentArray_Count-1; i++)
			{
				parrayList->pElement[i] = parrayList->pElement[i + 1];
			}
			parrayList->currentArray_Count--;
			ret = TRUE;
		}
		else
		{
			printf("Error, range of postion index is exceeded! removeElement() \n");
		}

	}
	else
	{
		printf("arrayList is Empty ! removeElement() \n");
	}
	return ret;

}

int deleteArrayList(ArrayList *parrayList)
{
	int ret = FALSE;
	int i;
	if (parrayList != NULL)
	{

		free(parrayList->pElement);
		free(parrayList);
	}
	else
	{
		printf("Error, parrayList is Empty !! - deleteArray() \n");
	}

	return ret;
}

void clearArrayList(ArrayList *parrayList)
{
	int i;
	int currentArray_Count = parrayList->currentArray_Count;

	for (i = 0; i < currentArray_Count; i++)
	{
		parrayList->pElement[i].data = NULL;
		parrayList->currentArray_Count--;
	}

}

void displayArrayList(ArrayList *parrayList)
{
	int i;

	if (parrayList != NULL)
	{
		printf("\n�ִ���� ���� : %d \n", parrayList->maxArray_Count);
		printf("���� ���Ұ��� : %d \n", parrayList->currentArray_Count);

		for (i = 0; i < parrayList->currentArray_Count; i++)
		{
			printf("ArrayList[%d] = %d \n", i, parrayList->pElement[i].data);
			/* �̷��Ե� ǥ�� ����  : arrayList�� ����Ű�� arrayListNode[i]���� ���� �ϰ�
				�� Node �� ���� �ִ� data�� ���
			//printf("ArrayList[%d] = %d \n", i, (&(parrayList->pElement[i]))->data);
			*/
		}

		for (i = parrayList->currentArray_Count; i < parrayList->maxArray_Count; i++)
		{
			printf("ArrayList[%d] = Empty \n", i);
		}
	}
	else
	{
		printf("Error, ArrayList is Empty - displayArrayList() \n");
	}
}