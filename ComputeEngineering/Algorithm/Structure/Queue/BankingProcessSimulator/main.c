/* EUC-KR
* 제목 : 은행 업무 시스템 시뮬레이터
* 작성 : ParkDyel
* 설명 : 열혈강의 자료구조에 있는 예제를 기반으로
*        작성된 코드로, 도착 시간과 처리 시간에 따라
*        전체 대기 시간을 구하는 프로그램입니다.
*/

#include <stdio.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"

int main(int argc, char* argv[]) {
	int currentTime = 0;				// 현재 시스템 시각
	int endTime = 20;					// 시스템 종료 시각
	int serviceUserCount = 0;			// 고객의 수
	int totalWaitTime = 0;				// 모든 대기시간의 합

	LinkedQueue *pArrivalQueue = NULL, *pWaitQueue = NULL;
	QueueNode *pServiceNode1 = NULL, *pServiceNode2 = NULL;

	pArrivalQueue = createLinkedQueue();
	pWaitQueue = createLinkedQueue();
	if (pArrivalQueue == NULL && pWaitQueue == NULL) {
		printf("Error, createLinkedQueue()\n");
		return FALSE;
	}

	insertCustomer(0, 3, pArrivalQueue);
	insertCustomer(2, 2, pArrivalQueue);
	insertCustomer(4, 1, pArrivalQueue);
	//insertCustomer(5, 1, pArrivalQueue);
	insertCustomer(6, 1, pArrivalQueue);
	insertCustomer(8, 3, pArrivalQueue);

	for (currentTime = 0; currentTime < endTime; currentTime++) {
		processArrival(currentTime, pArrivalQueue, pWaitQueue);
		/*
		*          ** 업무처리 예상흐름 **
		*  틱    0  1  2  3  4  5  6  7  8  9  10
		* 1사수  1  1  1  0  1  0  1  0  1  1  1
		* 2사수  0  0  1  1  0  0  0  0  0  0  0
		* 문제말생 : Node2의 고객을 카운트하지 못하고 있음.
		* 문제해결 : 복붙의 폐해.  
		*/
		if(pServiceNode1 != NULL && pServiceNode2 != NULL) {
			printf("\t\t사수와 부사수 모두 열심히 일하고 있습니다\n");
			pServiceNode1 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
			pServiceNode2 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
		} else if (pServiceNode1 != NULL && pServiceNode2 == NULL) {
			printf("\t\t사수가 일하는데 부사수가 노네?\n");
			pServiceNode1 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
			pServiceNode2 = processServiceNodeStart(currentTime, pWaitQueue);
		} else if (pServiceNode1 == NULL && pServiceNode2 != NULL) {
			printf("\t\t사수는 놀고 있습니다. 부사수가 열심히 굴려지고 있네요\n");
			pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
			pServiceNode2 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
		}
		else {
			printf("\t\t개점휴업. 이러다가 문 닫나 모르겠네\n");
			pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
		}
		
		printWaitQueueStatus(currentTime, pWaitQueue);
	}

	printReport(pWaitQueue, serviceUserCount, totalWaitTime);

	if (pServiceNode1 != NULL) {
		free(pServiceNode1);
	}
	deleteLinkedQueue(pArrivalQueue);
	deleteLinkedQueue(pWaitQueue);

	return 0;
}