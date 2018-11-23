#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;	/* 다음 노드를 가르키는 포인터 */
} ListNode;

typedef struct LinkedListType {
	int currentElementCount;	/* 현재 연결된 리스트 개수 */
	ListNode headerNode;		/* 첫 머리 노드 */
} LinkedList;

LinkedList* createLinkedList();
int addLinkedListElement(LinkedList *pList, int position, ListNode element);
ListNode* getLLElement(LinkedList* pList, int position);
int removeLinkedListElement(LinkedList *pList, int position);

void deleteLinkedList(LinkedList *pList);
void clearList(LinkedList *pList);
void displayList(LinkedList *pList);

#endif

#ifndef _COMMON_LIST_DEF
#define _COMMON_LIST_DEF
enum  {TRUE = 1, FALSE = 0}; 
#endif