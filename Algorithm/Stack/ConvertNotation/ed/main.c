/*
  1차 실패. 설계 없이 하여 프로그램이 꼬이기 시작함.
*/

#include <stdio.h>
#include <stdlib.h>

#include "flag.h"
#include "stack.h"

int main(int argc, char *argv) {

	ExprTokenStack *TokenStack = NULL;
	TokenStack = createStack();

	char buffer[] = "14+24*(25+63)";

	ExprToken tokenA;

	tokenA.pLinks = NULL;
	tokenA.type = operand;
	tokenA.value = 13;
	
	push(TokenStack, tokenA);

	ExprToken returnToken = pop(TokenStack);
	if(pop != NULL){
		printToken(&returnToken);
	}
	

	deleteStack(TokenStack);

	return 0;
}