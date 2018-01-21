// #pragma once
#ifndef _SIM_UTIL_
#define _SIM_UTIL_

void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue);													// �� ���� ť �߰�
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);									// �� ���� ó��
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);												// ���� ���� ó��
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);	// ���� ���� ó��
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif // !
