#include <stdio.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"

void insertCustomer(int arrivalTime, int serviceTime, LinkedQueue *pQueue) {
	int i = 0;
	if (pQueue != NULL) {
		QueueNode node = { 0, };
		node.data.status = arrival;
		node.data.arrivalTime = arrivalTime;
		node.data.serviceTime = serviceTime;
		node.data.startTime = 0;
		node.data.endTime = 0;
		enqueueLQ(pQueue, node);
	}
}


void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue) {
	QueueNode* pArrivalNode = NULL;
	int isEmpty = 0;
	isEmpty = isLinkedQueueEmpty(pArrivalQueue);
	while (isEmpty == FALSE) {
		pArrivalNode = peekLQ(pArrivalQueue);
		if (pArrivalNode->data.arrivalTime == currentTime) {
			enqueueLQ(pWaitQueue, *pArrivalNode);
			printSimCustomer(currentTime, pArrivalNode->data);
			free(dequeueLQ(pArrivalQueue));
		}
		else {
			break;
		}
		isEmpty = isLinkedQueueEmpty(pArrivalQueue);
	}
}
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode* pReturn = NULL;
	QueueNode* pServiceNode = NULL;
	int isEmpty = 0;

	if (pWaitQueue == NULL) {
		return NULL;
	}

	isEmpty = isLinkedQueueEmpty(pWaitQueue);
	if (isEmpty == FALSE) {
		pServiceNode = dequeueLQ(pWaitQueue);
		if (pServiceNode != NULL) {
			pServiceNode->data.status = start;
			pServiceNode->data.startTime = currentTime;
			printSimCustomer(currentTime, pServiceNode->data);

			pReturn = pServiceNode;
		}
	}

	return pReturn;
}
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime) {
	int endTime = 0;
	int waitTime = 0;
	QueueNode *pReturn = NULL;

	if (pServiceNode == NULL || pServiceUserCount == NULL || pTotalWaitTime == NULL) {
		return NULL;
	}

	endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
	if (endTime <= currentTime) {

		waitTime = pServiceNode->data.startTime - pServiceNode->data.arrivalTime;

		(*pServiceUserCount)++;
		(*pTotalWaitTime) += waitTime;

		pServiceNode->data.status = end;
		pServiceNode->data.endTime = currentTime;
		printSimCustomer(currentTime, pServiceNode->data);

		free(pServiceNode);
		pReturn = NULL;
	}
	else {
		pReturn = pServiceNode;
	}

	return pReturn;
}
void printSimCustomer(int currentTime, SimCustomer customer) {
	printf("[%d],", currentTime);

	switch(customer.status)  {
		case arrival:
			printf("고객 도착\n");
			break;
		case start:
			printf("서비스 시작");
			printf(",도착-%d,대기 시간-%d\n", customer.arrivalTime, 
				(customer.startTime - customer.arrivalTime));
			break;
		case end:
			printf("서비스 종료");
			printf(",도착-%d,시작-%d,대기 시간-%d,서비스 시간-%d\n", 
				customer.arrivalTime, customer.startTime,
				customer.startTime - customer.arrivalTime,
				customer.endTime - customer.startTime);
			break;
	}
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	printf("[%d],현재 대기 고객 수: %d\n", 
		currentTime,
		pWaitQueue->currentElementCount);
}

void printReport(LinkedQueue *pWaitQueue,
				 int serviceUserCount,
				 int totalWaitTime)
{
	printf("REPORT\n");
	printf("서비스 고객 수: %d\n", serviceUserCount);
	if (serviceUserCount > 0) {
		printf("평균 대기 시간: %f\n", 
			((float)totalWaitTime / (float)serviceUserCount));
	}
	printf("현재 대기 열의 고객 수: %d\n",
		pWaitQueue->currentElementCount);

}
