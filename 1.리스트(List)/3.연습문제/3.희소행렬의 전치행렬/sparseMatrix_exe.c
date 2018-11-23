/*
	희소행렬과 희소행렬의 전치연산 


*/

#include <stdio.h>
#include "sparseMatrix.h";


int main()
{
	/* 2차원 배열로 받아오려면 물리적으로 연결되어 있어야하는데
	포인터로 동적할당을 여러번해서 논리적으로 연결된 이차원배열을
	리턴하기 때문에 2차원 배열에 리턴값을 담을 수 없다.
	*/
	//int (*map)[max_s] = NULL; 
	int **map = NULL, **map2 = NULL;
	int i = 0, j = 0, k = 0, count = 0;
	spMatrix *pSpMatrix = NULL, *pSpMatrix_2 = NULL;

	printf("random count :");
	scanf_s("%d", &count);

	map = createSparseArray(count);

	printf("\n\n ---- 희소행렬 출력 ---- \n\n");
	displayArray(map);

	printf("\n\n ---- 희소행렬 구조체의 배열로 생성 ---- \n\n");

	pSpMatrix = createSpMatrix(map, max_s, max_s);
	displaySparseMatrix(pSpMatrix);


	printf("\n\n --- 희소행렬의 전치행렬 출력 --- !! \n");
	map2 = createSparseArray(0);

	if (map2 != NULL)
	{
		tranSparseMatrix(map, map2);
		displayArray(map2);

		pSpMatrix = createSpMatrix(map2, max_s, max_s);
		displaySparseMatrix(pSpMatrix);
	}
	else
	{
		printf("pSpMatrix_2 allocation is failed !! -- main() \n");
	}


	SAFE_FREE(pSpMatrix);
	SAFE_FREE(pSpMatrix_2);


	return 0;
}
