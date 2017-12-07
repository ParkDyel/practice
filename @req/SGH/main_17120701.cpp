#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define ByNUMBER 1
#define ByNAME 2
#define ByGRADE 3

typedef struct
{
    int nNumber;
    char strName[10];
    double dGrade;
} Student, *StudentPtr;

void PrintArray(StudentPtr pStudent);
void InitialStudent(StudentPtr pStudent, int nNdx);
void SortStudent(StudentPtr pStudents, int nByWhat = ByNUMBER);
int StudentCmp(StudentPtr pStudent1, StudentPtr pStudent2, int nByWhat);
void Swap(StudentPtr pStudent1, StudentPtr pStudent2);
StudentPtr FindMinimum(StudentPtr pStudents, int nByWhat);
void PrintStudent(StudentPtr pStudent, int nNdx);

int main(int argc, char *argv[])
{
    int nCtr;
    Student arrStudent[N + 1];

    srand((unsigned)time(NULL));

    while (1)
    {
        printf("number of students ? ");
        scanf("%d", &nCtr);
        if (nCtr <= 0 || nCtr >= N)
            break;

        for (int i = 0; i < nCtr; i++)
            InitialStudent(arrStudent, i);

        arrStudent[nCtr].nNumber = 0;

        printf("\n\n[non-sorting List]\n");
        PrintArray(arrStudent);

        SortStudent(arrStudent);
        printf("[Sorting by Student ID]\n");
        PrintArray(arrStudent);

        SortStudent(arrStudent, ByNAME);
        printf("[Sorting by Name]\n");
        PrintArray(arrStudent);

        SortStudent(arrStudent, ByGRADE);
        printf("[Sorting by Grade]\n");
        PrintArray(arrStudent);
    }
    printf("Bye, ...\n\n");

    return 0;
}

void SortStudent(StudentPtr pStudents, int nByWhat)
{
    for (StudentPtr cursor = pStudents; cursor->nNumber > 0; cursor++)
        Swap(cursor, FindMinimum(cursor, nByWhat));
}

StudentPtr FindMinimum(StudentPtr pStudents, int nByWhat)
{
    StudentPtr minPtr = pStudents;
    switch (nByWhat)
    {
    case 1:
        for (StudentPtr cursor = pStudents + 1; cursor->nNumber > 0; cursor++)
            if (StudentCmp(cursor, minPtr, nByWhat) > 0)
                minPtr = cursor;
        break;
    case 2:
        for (StudentPtr cursor = pStudents + 1; cursor->nNumber > 0; cursor++)
            if (StudentCmp(cursor, minPtr, nByWhat) > 0)
                minPtr = cursor;
        break;
    case 3:
        for (StudentPtr cursor = pStudents + 1; cursor->nNumber > 0; cursor++)
            if (StudentCmp(cursor, minPtr, nByWhat) > 0)
                minPtr = cursor;
        break;
    default:
        printf("Error: nByWhat %d", nByWhat);
        break;
    }
    return minPtr;
}

int StudentCmp(StudentPtr pStudent1, StudentPtr pStudent2, int nByWhat)
{
    int flagCmp = 0;
    switch (nByWhat)
    {
    case 1:
        if (pStudent1->nNumber < pStudent2->nNumber)
            flagCmp = 1;
        else
            flagCmp = -1;
        break;
    case 2:
        if (strcmp(pStudent1->strName, pStudent2->strName) < 0)
            flagCmp = 1;
        else
            flagCmp = -1;
        break;
    case 3:
        if (pStudent1->dGrade < pStudent2->dGrade)
            flagCmp = 1;
        else
            flagCmp = -1;
        break;
    default:
        printf("Error: nByWhat %d", nByWhat);
        flagCmp = 0;
        break;
    }

    return flagCmp;
}

void Swap(StudentPtr pStudent1, StudentPtr pStudent2)
{
    if (pStudent1 != pStudent2)
    {
        Student tmp = *pStudent1;
        *pStudent1 = *pStudent2;
        *pStudent2 = tmp;
    }
}

void InitialStudent(StudentPtr pStudent, int nNdx)
{
    static int nDepartment[] = {11, 18, 23, 78, 88};
    int nSize = sizeof(nDepartment) / sizeof(nDepartment[0]);
    int i, nNumber;

    do
    {
        int n = rand() % nSize;
        int c = rand() % 999 + 1;
        nNumber = 201700000 + (nDepartment[n] * 1000) + c;
        // printf("%d\'s nNumber is %d\n", nNdx, nNumber);
        for (i = 0; i < nNdx; i++)
            if (nNumber == (pStudent + i)->nNumber)
                break;
    } while (i < nNdx);

    (pStudent + nNdx)->nNumber = nNumber;
    // printf("%d\'s nNumber is %d\n", nNdx, pStudent[nNdx].nNumber);

    int nLength = rand() % 5 + 5;
    for (int i = 0; i < nLength; i++)
    {
        char j = rand() % 25 + 97;
        (pStudent + nNdx)->strName[i] = j;
    }
    (pStudent + nNdx)->strName[0] -= 32;
    (pStudent + nNdx)->strName[nLength] = '\0';

    (pStudent + nNdx)->dGrade = (double)(rand() % 26 + 20) / 10;
}

void PrintArray(StudentPtr pStudents)
{
    for (int i = 0; (pStudents + i)->nNumber > 0; i++)
        PrintStudent(pStudents, i);
    putchar('\n');
}

void PrintStudent(StudentPtr pStudent, int nNdx)
{
    printf("\t(%02d) %d %-9s %.1f\n", nNdx, (pStudent + nNdx)->nNumber, (pStudent + nNdx)->strName, (pStudent + nNdx)->dGrade);
}