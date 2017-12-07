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
        {
            // printf("initial Struct Student :%d\n", i);
            InitialStudent(arrStudent, i);
        };
        arrStudent[nCtr].nNumber = 0;

        // void PrintArray(StudentPtr pStudent);
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
    for (int i = 0; (pStudents + i)->nNumber > 0; i++)
    {
        Swap(pStudents + i, FindMinimum((pStudents + i), nByWhat));
    }
}

StudentPtr FindMinimum(StudentPtr pStudents, int nByWhat)
{
    int idx = 0;
    if (nByWhat == 1)
    {
        int minNumber = pStudents->nNumber;
        for (int i = 1; (pStudents + i)->nNumber > 0; i++)
        {
            if ((pStudents + i)->nNumber < minNumber)
            {
                // printf("%d:before minNumber:%d\t", i, minNumber);
                minNumber = (pStudents + i)->nNumber;
                // printf("after minNumber:%d\n", minNumber);
                idx = i;
            }
        }
    }
    else if (nByWhat == 2)
    {
        char minName[10];
        int isMin = 0;
        strcpy(minName, (pStudents)->strName);
        for (int i = 1; (pStudents + i)->nNumber > 0; i++)
        {
            for (int charCoursor = 0; minName[charCoursor] == '\0' || (pStudents)->strName[charCoursor] == '\0'; charCoursor++)
            {
                if (minName[charCoursor] > (pStudents)->strName[charCoursor])
                {
                    isMin = 1;
                    break;
                }
            }
            if (isMin)
            {
                strcpy(minName, (pStudents + i)->strName);
                idx = i;
            }

            // if (strcmp((pStudents + i)->strName, minName))
            // {
            //     strcpy(minName, (pStudents + i)->strName);
            //     idx = i;
            // }
        }
    }
    else if (nByWhat == 3)
    {
        double minGrade = (pStudents)->dGrade;
        for (int i = 1; (pStudents + i)->nNumber > 0; i++)
        {
            if ((pStudents + i)->dGrade < minGrade)
            {
                minGrade = (pStudents + i)->dGrade;
                idx = i;
            }
        }
    }
    return pStudents + idx;
}

void StudentCmp(StudentPtr pStudent1, StudentPtr pStudent2, int nByWhat)
{
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
        {
            if (nNumber == pStudent[i].nNumber)
            {
                break;
            }
        }
    } while (i < nNdx);

    pStudent[nNdx].nNumber = nNumber;
    // printf("%d\'s nNumber is %d\n", nNdx, pStudent[nNdx].nNumber);

    int nLength = rand() % 5 + 5;
    for (int i = 0; i < nLength; i++)
    {
        char j = rand() % 25 + 97;
        pStudent[nNdx].strName[i] = j;
    }
    pStudent[nNdx].strName[0] -= 32;
    pStudent[nNdx].strName[nLength] = '\0';

    pStudent[nNdx].dGrade = (double)(rand() % 26 + 20) / 10;
}

void PrintArray(StudentPtr pStudents)
{
    for (int i = 0; pStudents[i].nNumber > 0; i++)
        PrintStudent(pStudents, i);
    putchar('\n');
}

void PrintStudent(StudentPtr pStudent, int nNdx)
{
    printf("\t(%02d) %d %-9s %.1f\n", nNdx, pStudent[nNdx].nNumber, pStudent[nNdx].strName, pStudent[nNdx].dGrade);
}