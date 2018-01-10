#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "flag.h"
#include "stack.h"

ExprTokenStack *createStack(void)
{
	ExprTokenStack *pReturn = NULL;
	pReturn = (ExprTokenStack *)malloc(sizeof(ExprTokenStack));

	if (pReturn != NULL)
	{
		memset(pReturn, 0, sizeof(ExprTokenStack));
	}
	else
	{
		printf("Fail to memory allocate, createStack()\n"); // 메모리 할당 에러 메세지 출력
		return NULL;
	}
	pReturn->ctr = 0;

	printf("Stack is Allocated : \t\t %x\n", (unsigned int)pReturn);
	return pReturn;
}
void deleteStack(ExprTokenStack *pStack)
{
	while (pStack->ctr != 0)
	{
		// ExprToken *delNode = stack->pExprToken;
		// stack->pExprToken = stack->pExprToken->pLinks;

		// free(delNode);

		// stack->ctr--;
		pop(pStack);
	}
	free(pStack);

	printf("Stack is free : \t\t %x\n", (unsigned int)pStack);
}
/*
ExprToken *createToken(void) {
	ExprToken *pReturn = NULL;
	pReturn = (ExprToken *)malloc(sizeof(ExprToken));

	if (pReturn != NULL)
	{
		memset(pReturn, 0, sizeof(ExprToken));
	}
	else
	{
		printf("Fail to memory allocate, createToken()\n"); // 메모리 할당 에러 메세지 출력
		return NULL;
	}

	printf("Token is Allocated : \t\t %x\n", (unsigned int)pReturn);
	return pReturn;
}
void deleteToken(ExprToken *pToken) {
	if (pToken != NULL) free(pToken);

	return;
}
*/
int push(ExprTokenStack *pStack, ExprToken Token)
{
	int ret = FALSE;
	ExprToken *pNode = NULL;
	if (pStack != NULL) {
		pNode = (ExprToken *)malloc(sizeof(ExprToken));
		if (pNode != NULL)
		{
			memset(pNode, 0, sizeof(ExprToken));
			*pNode = pToken;
			pNode->pLinks = pStack->pTopToken;
			pStack->pTopToken = pNode;

			pStack->ctr++;
			ret = TRUE;
		}
		else
		{
			printf("Fail to memory allocate, push()\n"); // 메모리 할당 에러 메세지 출력
		}
	}
	return ret;
}
ExprToken pop(ExprTokenStack *pStack)
{
	if (pStack != NULL)
	{
		if (pStack->pTopToken != NULL) {
			ExprToken pNode = *(pStack->pTopToken);
			pStack->pTopToken = pStack->pTopToken->pLinks;

			pStack->ctr--;

			return pNode;
		}
		printf("Someting have Problem, can't Pop\n");
		return;
	}
	else
	{
		printf("Fail to pop()\n");
		return;
	}
}
void printToken(ExprToken *pToken) {
	printf("Token\'s Address : \t\t %x\nToken\'s Value : \t\t %f\nToken\'s Type : \t\t\t %d\nToken\'s Linked : \t\t %x\n", (unsigned int)pToken, pToken->value, pToken->type, (unsigned int)pToken->pLinks);
	return;
}
void printStack(ExprTokenStack *pStack) {
	return;
}
int counter(ExprTokenStack *pStack)
{
	return pStack->ctr;
}