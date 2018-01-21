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
	int arrivalTime;			// 은행 도착 시간
	int serviceTime;			// 필요한 서비스 시간
	int startTime;				// 처리 시작 시간
	int endTime;				// 처리 완료 시간 = 처리 시작 시간 + 필요한 서비스 시간
} SimCustomer;

#endif