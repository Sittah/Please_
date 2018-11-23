#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sparseMatrix.h";

int** createSparseArray(int count)
{
	int ** returnArray = NULL;
	int i = 0, j = 0, k = 0;
	int r_r = 0, r_c = 0;

	srand((int)time(NULL));

	/* */
	returnArray = (int **)malloc(sizeof(int *) * max_s);
	if(DEBUG) printf("returnArray  : %x \n", returnArray);

	if(DEBUG)
	{
		for (i = 0; i < max_s; i++)
		{
			printf("1차 동적할당 returnArray[%d] : %x -- 주소 :%x \n", i, returnArray[i], &(returnArray[i]));
		}
		printf("\n\n --- 2차 시작 --- \n\n");
	}


	for (i = 0; i < max_s; i++)
	{
		returnArray[i] = (int *)malloc(sizeof(int) * max_s);
		memset(returnArray[i], 0, sizeof(int) * max_s);
		if(DEBUG) printf("2차 동적할당 returnArray[%d] : %x -- 주소 :%x \n", i, returnArray[i], &(returnArray[i]));
	}

	for (i = 0; i < count; i++)
	{
		r_r = rand() % max_s;
		r_c = rand() % max_s;

		if (returnArray[r_r][r_c] != 0)
		{
			i--;
			continue;
		}

		returnArray[r_r][r_c] = rand() % (max_s * max_s);
	}

	return returnArray;
}


spMatrix * createSpMatrix(int **map, int row, int col)
{
	spMatrix * pNewSpMatrix = NULL;
	int i = 0, j = 0, k = 0;
	int cnt = 0, index = 0;
	for (i = 0; i < max_s; i++)
	{
		for (j = 0; j < max_s; j++)
		{
			if (map[i][j])
			{
				cnt++;
			}
		}
	}

	// 희소행렬의 표현에서 첫줄(First Line)에는 행렬의 정보 (행개수) (열개수) (데이터개수) 있음
	pNewSpMatrix = (spMatrix *)malloc(sizeof(spMatrix) * (cnt + 1));

	if (pNewSpMatrix == NULL)
	{
		printf(" pNewSpMatrix allocation is failed!! -- createSpMatrix() \n");
		return NULL;
	}

	pNewSpMatrix[0].row = row;
	pNewSpMatrix[0].col = col;
	pNewSpMatrix[0].value = cnt;

	index = 1;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (map[i][j])
			{
				pNewSpMatrix[index].row = i;
				pNewSpMatrix[index].col = j;
				pNewSpMatrix[index++].value = map[i][j];
			}
		}
	}
	return pNewSpMatrix;
}

void displayArray(int **sp)
{
	int i = 0, j = 0;

	if (sp)
	{
		for (i = 0; i < max_s; i++)
		{
			for (j = 0; j < max_s; j++)
			{
				printf(" %2d", sp[i][j]);
			}
			printf("\n");
		}
	}
}


void displaySparseMatrix(spMatrix *sp)
{
	int i = 0, j = 0;

	if (sp)
	{
		for (i = 0; i <= sp[0].value; i++)
		{
			printf("%2d %2d %2d\n", sp[i].row, sp[i].col, sp[i].value);
		}
	}
}

void tranSparseMatrix(int **termA, int **termB)
{
	/*
	1 2 3			1 4 7
	4 5 6   == >		2 5 8
	7 8 9			3 6 9

	(0,1) => (1,0)
	(0,2) => (2,0)

	*/
	int tempCol = 0, tempRow = 0;
	int i = 0, j = 0;

	if (termA != NULL && termB != NULL)
	{
		for (i = 0; i < max_s; i++)
		{
			for (j = 0; j < max_s; j++)
			{
				termB[j][i] = termA[i][j];
			}
		}
	}
}
