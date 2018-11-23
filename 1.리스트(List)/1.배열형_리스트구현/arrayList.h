#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data;
}ArrayListNode;

typedef struct ArrayListType
{
	int maxArray_Count;
	int currentArray_Count;
	ArrayListNode * pElement;
}ArrayList;

ArrayList * createList(int maxArray_Count);
int addElement(ArrayList *parrayList, int position, ArrayListNode element);
int removeElement(ArrayList *parrayList, int position);
int isArrayListFull(ArrayList * parrayList);
int deleteArrayList(ArrayList *parrayList);
void displayArrayList(ArrayList *parrayList);
void clearArrayList(ArrayList *parrayList);

#endif


#ifndef _COMMON_LIST_DEF
#define _COMMON_LIST_DEF

#define TRUE 1
#define FALSE 0

#endif