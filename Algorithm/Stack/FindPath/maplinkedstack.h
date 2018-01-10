#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef struct StackNodeType
{
	MapPosition data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 이동 횟수를 나타내는 변수
	StackNode* pTopElement;		// Stack의 TOP Node를 나타내는 포인터 변수
} LinkedStack;

LinkedStack* createLinkedStack();											// 생성자
int pushLS(LinkedStack* pStack, StackNode element);		// List로 구현된 Stack에 새로운 요소를 push한다.
StackNode* popLS(LinkedStack* pStack);								// List로 구현된 Stack의 TOP에서 요소를 pop한다.
StackNode* peekLS(LinkedStack* pStack);								// List로 구현된 Stack의 TOP에서 요소를 peek한다.
void deleteLinkedStack(LinkedStack* pStack);					// 소멸자
int isLinkedStackFull(LinkedStack* pStack);						// List로 구현된 Stack에 여유 공간이 있는지 확인한다.
int isLinkedStackEmpty(LinkedStack* pStack);					// List로 구현된 Stack에 요소가 하나 이상 있는지 확인한다.

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif