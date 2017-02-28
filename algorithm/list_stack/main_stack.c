// http://milvus.tistory.com/20

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
	stack* mystack=(stack*)malloc(sizeof(stack));
	init(mystack);

	push(mystack,2);
	push(mystack,3);
	push(mystack,4);
	push(mystack,5);
	push(mystack,6);
	push(mystack,7);

	printf("Get Top: %d\n",getTop(mystack));
	printf("Count: %d\n",getCount(mystack));

	printf("Pop: %d\n",pop(mystack));
	printf("Pop: %d\n",pop(mystack));

	printf("Get Top: %d\n",getTop(mystack));
	printf("Count: %d\n",getCount(mystack));

	free_stack(mystack);

	return 0;
}
