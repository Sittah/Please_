#ifndef _CIRCULAR_LIST_
#define _CIRCULAR_LIST_

typedef struct CircularListNodeType {
	int data;
	struct CircularListNodeType *pLink;
} CircularListNode;

typedef struct CircularListType {
	int currentElementCount;
	CircularListNode headerNode;
} CircularList;

CircularList* createCCList();
int addCCL_Element(CircularList *pList, int position, CircularListNode element);
int removeCCL_Element(CircularList *pList, int position);
void deleteCCList(CircularList *pList);
void clearCCList(CircularList *pList);
void displayCCList(CircularList *pList);

#endif

#ifndef _COMMON_DEF_
#define _COMMON_DEF_

#define SAFE_DEL_LIST(obj) if(obj) { deleteCCList(obj); obj = NULL; }
#define SAFE_FREE(obj) if(obj) { free(obj); obj = NULL; }

enum { FALSE = 0, TRUE = 1 };

#endif