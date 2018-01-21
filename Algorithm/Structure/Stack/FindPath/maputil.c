#include <stdio.h>
#include <stdlib.h>
#include "mapdef.h"
#include "maplinkedstack.h"
#include "maputil.h"

int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
{
	StackNode node = {0,};																				// 지역변수로 벗어나면 주금
	node.data = data;																							// StackNode에 data 저장
	return pushLS(pStack, node);																	// 삽입 후 종료
}

void findPath(int mazeArray[HEIGHT][WIDTH],
			  MapPosition startPos,
			  MapPosition endPos,
			  LinkedStack *pStack)
{
	StackNode *pNode = NULL;
	int isEmpty = FALSE, isFound = FALSE, i = 0;
	int markArray[HEIGHT][WIDTH] = {0,};

	if (pStack != NULL)	{
		MapPosition newPosition = startPos;
		newPosition.direction = 0;
		pushLSMapPosition(pStack, newPosition);
		while(isEmpty == FALSE && isFound == FALSE) {
			pNode = popLS(pStack);
			if (pNode != NULL) {
				int x = pNode->data.x;
				int y = pNode->data.y;
				int direction = pNode->data.direction;

				while(isFound == FALSE && direction < NUM_DIRECTIONS) {
					int newX = x + DIRECTION_OFFSETS[direction][0];
					int newY = y + DIRECTION_OFFSETS[direction][1];

					if (newX >= 0 && newX < WIDTH
							&& newY >= 0 && newY < HEIGHT
							&& mazeArray[newY][newX] == NOT_VISIT
							&& markArray[newY][newX] == NOT_VISIT) {										
						MapPosition newPosition;
						newPosition.x = x;
						newPosition.y = y;
						newPosition.direction = direction + 1;
						pushLSMapPosition(pStack, newPosition);
						markArray[y][x] = VISIT;

						x = newX;
						y = newY;
						direction = 0;

						if (newX == endPos.x && newY == endPos.y) {
							isFound = TRUE;
							newPosition.x = newX;
							newPosition.y = newY;
							newPosition.direction = 0;
							pushLSMapPosition(pStack, newPosition);
							markArray[newY][newX] = VISIT;
						}
					}								
					else {
						direction++;
					}
				}//end-of-while
				free(pNode);
			}//end-of-if
			isEmpty = isLinkedStackEmpty(pStack);
		}//end-of-while
	}
}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode *pNode = NULL;
	int resultArray[HEIGHT][WIDTH] = {0,};
	int isEmpty = FALSE;

	int i, j;
	for(i = 0; i < HEIGHT; i++) {
		for(j = 0; j < WIDTH; j++) {
			resultArray[i][j] = mazeArray[i][j];
		}
	}

	if (pStack != NULL) {
		i = 0;
		while(isEmpty == FALSE) {
			pNode = popLS(pStack);
			if (pNode != NULL) {
				int x = pNode->data.x;
				int y = pNode->data.y;
				resultArray[y][x] = VISIT;

				if (i > 0) {
					printf("<-");
				}
				printf("(%d,%d) ", x, y);

				i++;
				free(pNode);
			}
			isEmpty = isLinkedStackEmpty(pStack);
		}
		printf("\n");
		printMaze(resultArray);
	}
}

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int i, j;
	for(i = 0; i < HEIGHT; i++) {
		for(j = 0; j < WIDTH; j++) {
			if (mazeArray[i][j] == WALL) {
				printf("*");
			}
			else if (mazeArray[i][j] == VISIT) {
				printf(".");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}