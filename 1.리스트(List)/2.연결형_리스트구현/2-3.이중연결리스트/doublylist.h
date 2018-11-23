#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

typedef struct DoublyListNodeType {
	int data;
	struct DoublyListNodeType *pLLink;
	struct DoublyListNodeType *pRLink;
} DoublyListNode;

typedef struct DublyListType {
	int currentElementCount;
	DoublyListNode headerNode;
} DoublyList;

DoublyList* createDoublyList();
int addDLElement(DoublyList *pList, int position, DoublyListNode element);
int removeDLElement(DoublyList *pList, int position);
void deleteDoublyList(DoublyList *pList);
void clearDoublyList(DoublyList *pList);

#endif


#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define SAFE_RELEASE(ppRemoveObject) if(ppRemoveObject != NULL) { *ppRemoveObject = NULL; free(*ppRemoveObject); }

enum { FALSE = 0, TRUE = 1 };
#endif