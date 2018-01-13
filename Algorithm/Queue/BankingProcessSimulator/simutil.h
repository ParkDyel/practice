// #pragma once
#ifndef _SIM_UTIL_
#define _SIM_UTIL_

void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue);													// 고객 도착 큐 추가
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);									// 고객 도착 처리
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);												// 서비스 시작 처리
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);	// 서비스 종료 처리
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif // !
