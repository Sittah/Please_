/*
	�����İ� �������� ��ġ���� 


*/

#include <stdio.h>
#include "sparseMatrix.h";


int main()
{
	/* 2���� �迭�� �޾ƿ����� ���������� ����Ǿ� �־���ϴµ�
	�����ͷ� �����Ҵ��� �������ؼ� �������� ����� �������迭��
	�����ϱ� ������ 2���� �迭�� ���ϰ��� ���� �� ����.
	*/
	//int (*map)[max_s] = NULL; 
	int **map = NULL, **map2 = NULL;
	int i = 0, j = 0, k = 0, count = 0;
	spMatrix *pSpMatrix = NULL, *pSpMatrix_2 = NULL;

	printf("random count :");
	scanf_s("%d", &count);

	map = createSparseArray(count);

	printf("\n\n ---- ������ ��� ---- \n\n");
	displayArray(map);

	printf("\n\n ---- ������ ����ü�� �迭�� ���� ---- \n\n");

	pSpMatrix = createSpMatrix(map, max_s, max_s);
	displaySparseMatrix(pSpMatrix);


	printf("\n\n --- �������� ��ġ��� ��� --- !! \n");
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
