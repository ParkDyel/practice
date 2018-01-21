#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mapdef.h"
#include "maplinkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack *pReturn = NULL;																// Stack 포인터 생성
	int i = 0;
	pReturn = (LinkedStack *)malloc(sizeof(LinkedStack));				// LinkedStack의 크기만큼 Stack 메모리 할당
	if (pReturn != NULL) {																			// Stack에 메모리가 할당되었는 지 확인
		memset(pReturn, 0, sizeof(LinkedStack));									// Stack의 메모리 초기화
	}
	else {
		printf("Fail to memory allocate, createLinkedStack()\n");	// 메모리 할당 에러 메세지 출력
		return NULL;
	}

	return pReturn;
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	int ret = FALSE;																						// return 변수 생성
	StackNode *pNode = NULL;

	if (pStack != NULL) {																				// stack 포인터 정상 여부 판단
		pNode = (StackNode *)malloc(sizeof(StackNode));						// 새로운 Node 메모리 할당
		if (pNode != NULL) {																			// node 포인터 정상 여부 판단
			memset(pNode, 0, sizeof(StackNode));										// node 메모리 초기화
			*pNode = element;
			pNode->pLink = pStack->pTopElement;											// pStack의 Top 요소를 pNode의 다음 Node로 연결한다.
			pStack->pTopElement = pNode;														// pStack의 Top 요소를 pNode로 설정
			  
			pStack->currentElementCount++;													// pStack의 카운터 증가
			ret = TRUE;
		}
		else {
			printf("Fail to Push Lists in stack, pushLS()\n");
		}
	}

	return ret;
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode* pReturn = NULL;																	// Node 포인터 초기화
	if (pStack != NULL)	{																				// stack 포인터 정상 여부 판단
		if (isLinkedStackEmpty(pStack) == FALSE) {								// stack의 node 포함 여부 확인
			pReturn = pStack->pTopElement;													// pStack의 Top 요소의 주소를 반환 Node에 저장
			pStack->pTopElement = pReturn->pLink;										// pStack의 Top 요소의 주소를 이전의 Top이었던 반환 Node의 링크로 저장
			pReturn->pLink = NULL;																	// 반환 Node의 다음 노드의 주소 정보를 제거

			pStack->currentElementCount--;													// pStack의 카운터 감소
		}
	}

	return pReturn;
}

StackNode* peekLS(LinkedStack* pStack)
{
	StackNode* pReturn = NULL;																	// Node 포인터 초기화
	if (pStack != NULL) {																				// stack 포인터 정상 여부 판단
		if (isLinkedStackEmpty(pStack) == FALSE) {								// stack의 node 포함 여부 확인
			pReturn = pStack->pTopElement;													// Stack의 Top 요소의 주소를 반환 Node에 저장
		}
	}

	return pReturn;
}

void deleteLinkedStack(LinkedStack* pStack)
{																															// 2개의 포인터를 이용해서 마지막 스태까지 
	StackNode *pNode = NULL;																		// Node 포인터 초기화
	StackNode *pDelNode = NULL;																	// DelNode 포인터 초기화

	if (pStack != NULL) {
		pNode = pStack->pTopElement;															// Stack의 TopNode를 가져옵니다.
		while(pNode != NULL) {																		// Stack의 TopNode가 더 이상 없을 때까지 반복합니다.
			pDelNode = pNode;																				// 지울 DelNode는 pNode 입니다.
			pNode = pNode->pLink;																		// pNode를 Node에 연결된 다음 노드를 가르킵니다.
			free(pDelNode);																					// DelNode 메모리를 해제합니다.
		}
		free(pStack);																							// Stack 메모리를 해제합니다.
	}	
}

int isLinkedStackFull(LinkedStack* pStack)
{
	int ret = FALSE;
	return ret;
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	int ret = FALSE;

	if (pStack != NULL) {																				// 주어진 pStack이 NULL 값이 아니라면
		if (pStack->currentElementCount == 0) {										// Stack의 카운터를 확인하고
			ret = TRUE;																							// 0이면 비어있음을 반환합니다.
		}
	}

	return ret;
}