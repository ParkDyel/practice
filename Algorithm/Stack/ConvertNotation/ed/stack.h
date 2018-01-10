#ifndef _STACK_H_
#define _STACK_H_

typedef enum PrecedenceType {
	lparen	= 0,	// (
	rparen,			// )
	times,			// *
	plus,			// +
	minus,			// - 
	divide,			// /
	operand			// int
} Precedence;

typedef struct ExprTokenType {
	float value;
	Precedence type;
	struct ExprToken *pLinks;
} ExprToken;

typedef struct ExprTokenStackType {
	ExprToken *pTopToken;
	int ctr;
} ExprTokenStack;

ExprTokenStack *createStack(void);
void deleteStack(ExprTokenStack *pStack);
// ExprToken *createToken(void);
// void deleteToken(ExprToken *pToken);
int push(ExprTokenStack *pStack, ExprToken Token);
ExprToken pop(ExprTokenStack *pStack);
void printToken(ExprToken *pToken);
void printStack(ExprTokenStack *pStack);
int counter(ExprTokenStack *pStack);

#endif