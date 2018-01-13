/*
* simdef.h
* declare constance and struct
*/
//#pragma once

#ifndef _SIM_DEF
#define _SIM_DEF

typedef enum SimStatusType { arrival, start, end} Simstatus;

typedef struct SimCustomerType {
	Simstatus status;
	int arrivalTime;			// ���� ���� �ð�
	int serviceTime;			// �ʿ��� ���� �ð�
	int startTime;				// ó�� ���� �ð�
	int endTime;				// ó�� �Ϸ� �ð� = ó�� ���� �ð� + �ʿ��� ���� �ð�
} SimCustomer;

#endif