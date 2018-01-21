/* EUC-KR
* ���� : ���� ���� �ý��� �ùķ�����
* �ۼ� : ParkDyel
* ���� : �������� �ڷᱸ���� �ִ� ������ �������
*        �ۼ��� �ڵ��, ���� �ð��� ó�� �ð��� ����
*        ��ü ��� �ð��� ���ϴ� ���α׷��Դϴ�.
*/

#include <stdio.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"

int main(int argc, char* argv[]) {
	int currentTime = 0;				// ���� �ý��� �ð�
	int endTime = 20;					// �ý��� ���� �ð�
	int serviceUserCount = 0;			// ���� ��
	int totalWaitTime = 0;				// ��� ���ð��� ��

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
		*          ** ����ó�� �����帧 **
		*  ƽ    0  1  2  3  4  5  6  7  8  9  10
		* 1���  1  1  1  0  1  0  1  0  1  1  1
		* 2���  0  0  1  1  0  0  0  0  0  0  0
		* �������� : Node2�� ���� ī��Ʈ���� ���ϰ� ����.
		* �����ذ� : ������ ����.  
		*/
		if(pServiceNode1 != NULL && pServiceNode2 != NULL) {
			printf("\t\t����� �λ�� ��� ������ ���ϰ� �ֽ��ϴ�\n");
			pServiceNode1 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
			pServiceNode2 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
		} else if (pServiceNode1 != NULL && pServiceNode2 == NULL) {
			printf("\t\t����� ���ϴµ� �λ���� ���?\n");
			pServiceNode1 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
			pServiceNode2 = processServiceNodeStart(currentTime, pWaitQueue);
		} else if (pServiceNode1 == NULL && pServiceNode2 != NULL) {
			printf("\t\t����� ��� �ֽ��ϴ�. �λ���� ������ �������� �ֳ׿�\n");
			pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
			pServiceNode2 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
		}
		else {
			printf("\t\t�����޾�. �̷��ٰ� �� �ݳ� �𸣰ڳ�\n");
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