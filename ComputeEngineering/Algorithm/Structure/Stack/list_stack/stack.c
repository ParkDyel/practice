
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(stack* sptr){
	sptr->count=0;
	sptr->top=NULL;
}

void push(stack* sptr,int value){
	nptr new_nptr=(nptr)malloc(sizeof(node));
	new_nptr->value=value;
	new_nptr->next=sptr->top;
	sptr->top=new_nptr;
	sptr->count++;
}

int pop(stack* sptr){
	if(sptr->count>0){
		nptr tmp=sptr->top;
		sptr->top=tmp->next;
		int pop_value=tmp->value;
		free(tmp);
		sptr->count--;
		return pop_value;
	}
	else{
		printf("No item exists in this stack.\n");
		return -1;
	}
}

int getTop(stack* sptr){
	if(sptr->count>0) return sptr->top->value;
	else{
		printf("No item exists in this stack.\n");
		return -1;
	}
}

int getCount(stack* sptr){
	return sptr->count;
}

void free_stack(stack* sptr){
	while(sptr->top!=NULL){
		pop(sptr);
	}
	free(sptr);
}
