#ifndef _CIRCULAR_LIST_
#define _CIRCULAR_LIST_


typedef struct circularListNodeType {
	int element;
	struct circularListNodeType *pLink;
} circularListNode;

typedef struct circularListNode{
	int currentListCount;
circularListNode *pLink;
} circularList;

circularList *createCircularList();
int addCLElement(circularList *pList, int position, circularListNode element);
int removeCLElement(circularList *pListm, int position);
void clearCircularList(circularList *pList);
void deleteCircularList(circularList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_
enum { FALSE = 0, TRUE = 1 };
#endif