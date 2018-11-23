#ifndef _SPARSE_MATRIX_DEF_
#define _SPARSE_MATRIX_DEF_
#define max_s 10
#define SAFE_FREE(obj) if(obj) { free(obj); obj = NULL; }

typedef struct sparseMatrixType {
	int row;
	int col;
	int value;
} spMatrix;

spMatrix * createSpMatrix(int **map, int row, int col);
int** createSparseArray(int count);
void displayArray(int **sp);
void displaySparseMatrix(spMatrix *sp);
void tranSparseMatrix(int **termA, int **termB);


#endif

#ifndef _COMMON_DEF_
#define _COMMON_DEF_
enum {FALSE = 0, TRUE = 1};
#define DEBUG FALSE
#endif
