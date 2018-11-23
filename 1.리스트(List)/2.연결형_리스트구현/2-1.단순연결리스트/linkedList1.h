#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;	/* ���� ��带 ����Ű�� ������ */
} ListNode;

typedef struct LinkedListType {
	int currentElementCount;	/* ���� ����� ����Ʈ ���� */
	ListNode headerNode;		/* ù �Ӹ� ��� */
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