# 과제
이번 과제는 구조체를 학습하는 수업 시간에 사용했던 학생에 대한 구조체 Student와 StudentPtr를 typedef 정의한 후, nCtr개의 학생을 생성하여 배열에 저장하고, 학번으로 정렬하고, 이름으로 정렬하고, 학점으로 정렬하는 프로그램을 작성한다. 정렬하는 알고리즘은 앞서 두 번에 걸쳐 과제를 했으니 다시 언급하지 않겠습니다. 다만 원소가 정수가 아니고 구조체인 것만 다르다. 배열의 끝은 학번을 0으로 표시한다.
다음은 실제로 실행되는 예이다.

## 프로그램 동작 예시
```
원소의 갯수 ? 30

[정렬할 자료]
(01) 201723016 Ibgbjdwwm 3.3
(02) 201711033 Ikjrj     2.2
(03) 201723076 Qurihe    4.2
(04) 201718038 Aeuzjkjy  4.2
(05) 201711082 Fplhe     2.3
     -----------------------
(26) 201718003 Pqaaxc    2.2
(27) 201788089 Apnzjifwq 4.3
(28) 201723083 Wvmjh     4.1
(29) 201778038 Ontmdem   2.2
(30) 201718072 Ownmf     2.9

[학번에 의한 정렬]
(01) 201711033 Ikjrj     2.2
(02) 201711054 Duphjdjfn 3.1
(03) 201711075 Qagwkprgp 3.7
(04) 201711080 Pznao     3.9
(05) 201711082 Fplhe     2.3
     -----------------------
(26) 201778046 Mbsnqj    4.2
(27) 201788002 Wdsmkhrhf 2.0
(28) 201788022 Zqrvagpd  4.5
(29) 201788080 Svaxrw    4.4
(30) 201788089 Apnzjifwq 4.3

[이름에 의한 정렬]
(01) 201718038 Aeuzjkjy  4.2
(02) 201788089 Apnzjifwq 4.3
(03) 201718081 Dhzigyw   2.4
(04) 201711054 Duphjdjfn 3.1
(05) 201723012 Ebqspq    3.8
     -----------------------
(26) 201723083 Wvmjh     4.1
(27) 201723004 Xlxptmoi  3.7
(28) 201723053 Xppwpxks  2.4
(29) 201778043 Yhmlxf    3.5
(30) 201788022 Zqrvagpd  4.5

[학점에 의한 정렬]
(01) 201788002 Wdsmkhrhf 2.0
(02) 201718016 Fsmsda    2.2
(03) 201711033 Ikjrj     2.2
(04) 201778038 Ontmdem   2.2
(05) 201718003 Pqaaxc    2.2
     -----------------------
(26) 201723076 Qurihe    4.2
(27) 201778046 Mbsnqj    4.2
(28) 201788089 Apnzjifwq 4.3
(29) 201788080 Svaxrw    4.4
(30) 201788022 Zqrvagpd  4.5

원소의 갯수 ? 0
Bye, ...
```
## 프로그램 원시 코드
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable: 4996)

#define N	100
#define ByNUMBER	1
#define ByNAME		2
#define ByGRADE		3

typedef struct {
	int nNumber;
	char strName[10];
	double dGrade;
}	Student, *StudentPtr;		// 학생 자료형 Student와 포인터 StudentPtr를 정의한다.

void main()
{
	int nCtr;
	Student arrStudent[N];				// 끝을 표시할 공간을 고려할 것
	srand((unsigned)time(NULL));
	while (1) {
		printf("원소의 갯수 ? ");
		scanf("%d", &nCtr);
		if (nCtr <= 0 || nCtr >= N)
			break;
		void InitialStudent(StudentPtr pStudent, int nNdx);
		for (int i = 0; i < nCtr; i++)
			InitialStudent(arrStudent, i);	// 학생 arrStudent[i]를 초기화
		arrStudent[nCtr].nNumber = 0;		// 학생들의 끝을 표시

		void PrintArray(StudentPtr pStudent);
		printf("[정렬할 자료]\n");
		PrintArray(arrStudent);

		void SortStudent(StudentPtr pStudents, int nByWhat = ByNUMBER);
		SortStudent(arrStudent);			// 학번으로 정렬
		printf("[학번에 의한 정렬]\n");
		PrintArray(arrStudent);

		SortStudent(arrStudent, ByNAME);	// 이름으로 정렬
		printf("[이름에 의한 정렬]\n");
		PrintArray(arrStudent);

		SortStudent(arrStudent, ByGRADE);	// 학점으로 정렬
		printf("[학점에 의한 정렬]\n");
		PrintArray(arrStudent);
	}
	printf("Bye, ...\n\n");
}

void SortStudent(StudentPtr pStudents, int nByWhat)
{
	// pStudents부터 여러 학생들은 nByWhat으로 정렬한다.
	// 학생들의 끝은 학번이 0으로 설정되어 있다.
	// nByWhat은 ByNUMBER, ByNAME, ByGRADE 값을 가지는데 각각 학번, 이름, 학점으로 정렬
}

StudentPtr FindMinimum(StudentPtr pStudents, int nByWhat)
{
	// pStudents부터 여러 학생들은 nByWhat으로 최소값을 가지는 학생의 포인터를 반환한다.
	// 학생들의 끝은 학번이 0으로 설정되어 있다.
}

int StudentCmp(StudentPtr pStudent1, StudentPtr pStudent2, int nByWhat)
{
	// pStudent1와 pStudent2가 가리키는 두 학생을 nByWhat으로 비교한다.
	// 비교한 값이 전자가 후자 보자 작으면 음수, 같으면 0, 크면 양수를 반환한다.
}

void Swap(StudentPtr pStudent1, StudentPtr pStudent2)
{
	// pStudent1와 pStudent2가 가리키는 두 학생을 서로 바꾼다.
}

void InitialStudent(StudentPtr pStudent, int nNdx)
{
	// 학생 pStudent[nNdx]를 아래와 초기화 한다.
	// 1. 학번:
	//    학번은 입학년도 4자리, 학과 2자리, 학과 내 일련번호 3자리로 구성된다.
	//    학번은 입학년도 4자리는 2017로 고정한다.
	//    학과는 11, 18, 23, 78, 88 중에 랜덤하게 선택한다.
	//    일련번호는 1에서 999까지 랜덤하게 선택한다.
	// 2. 이름:
	//    이름은 5에서 9자리까지 랜덤하게 결정한다.
	//    이름은 첫 글자는 대문자, 나머지는 소문자로 랜덤하게 결정한다.
	// 학번은 생성한다.
	static int nDepartment[] = { 11, 18, 23, 78, 88 };
	int nSize = sizeof(nDepartment) / sizeof(nDepartment[0]);
	int i, nNumber;
	do {
		학번을 생성한다.
		for (???)				// 같은 학번이 있는지 체크한다.
			?????
	} while (i < nNdx);		// 같은 학번이 있으면 다시 생성한다.
	학번 pStudent[nNdx].nNumber에 생성된 학번을 저장한다.
	
	// 이름을 생성한다.
	이름의 길이 nLength를 5~9까지 랜덤하게 정한다.
	for (??)
		이름의 글자 pStudent[nNdx].strName[i]를 랜덤하게 정한다.
	이름 문자열 pStudent[nNdx].strName 끝을 표시한다.

	// 학점을 생성한다.
	학점 pStudent[nNdx].dGrade를 2.0에서 4.5까지 랜덤하게 결정한다.
}

void PrintArray(StudentPtr pStudents)
{
	// pStudents부터 여러 학생들을 출력한다.
	// 학생들의 끝은 학번이 0으로 설정되어 있다.
	putchar('\n');
}

void PrintStudent(StudentPtr pStudent, int nNdx)
{
	// 학생들을 "(%02d) %d %-9s %.1f\n" 형식으로 번호, 학번, 이름, 학점을 출력한다.
}
```

## 프로젝트 파일 관리
module_*.cpp : 프로그램 작성을 위한 Grammer Coding
main_*.cpp : 프로그래밍 중간 코드
main.cpp : 제출 코드