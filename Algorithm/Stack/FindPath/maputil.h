#ifndef _MAP_UTIL_
#define _MAP_UTIL_

void findPath(int mazeArray[HEIGHT][WIDTH],													// fn(맵 정보, 시작 위치, 종료 위치, 저장공간)
			  MapPosition startPos,
			  MapPosition endPos,
			  LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);				// 위치 정보를 저장소에 저장 : fn(저장소, 위치 데이터)
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);		// 경로 출력 : fn(저장소, 맵 데이터)
void printMaze(int mazeArray[HEIGHT][WIDTH]);												// 맵 출력 : fn(맵 데이터)

#endif