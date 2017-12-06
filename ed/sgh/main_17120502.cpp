#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable : 4996)

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
    void InitialStudent(StudentPtr pStudent, int nNdx);
    for (int i = 0; i < nCtr; i++)
    {
      printf("initial Struct Student :%d\n", i);
      InitialStudent(arrStudent, i);
    };
    arrStudent[nCtr].nNumber = 0;

    // void PrintArray(StudentPtr pStudent);
    printf("\n\n[non-sorting List]\n");
    PrintArray(arrStudent);

    void SortStudent(StudentPtr pStudents, int nByWhat = ByNUMBER);
    SortStudent(arrStudent);
    printf("[Sorting by Student ID]\n");
    PrintArray(arrStudent);

    // SortStudent(arrStudent, ByNAME);
    // printf("[Sorting by Name]\n");
    // PrintArray(arrStudent);

    // SortStudent(arrStudent, ByGRADE);
    // printf("[Sorting by Grade]\n");
    // PrintArray(arrStudent);
  }
  printf("Bye, ...\n\n");

  return 0;
}

// void SortStudent(StudentPtr pStudents, int nByWhat)
// {
//   StudentPtr FindMinimum(StudentPtr pStudents, int nByWhat);
//   void Swap(StudentPtr pStudent1, StudentPtr pStudent2);
//   for (StudentPtr cursor = pStudents; cursor->nNumber > 0; cursor++)
//   {
//     Swap(cursor, FindMinimum(cursor, nByWhat));
//     // PrintArray(cursor);
//   }
// }

void SortStudent(StudentPtr pStudents, int nByWhat)
{
  StudentPtr FindMinimum(StudentPtr pStudents, int nByWhat);
  void Swap(StudentPtr pStudent1, StudentPtr pStudent2);
  for (StudentPtr cursor=pStudents; cursor->nNumber > 0; cursor++)
  {
    Swap(cursor, FindMinimum(cursor, nByWhat));
    PrintArray(pStudents);
  }
}

StudentPtr FindMinimum(StudentPtr pStudents, int nByWhat)
{
  StudentPtr minStudents;
  if (nByWhat == 1)
  {
    int minNumber = pStudents->nNumber;
    for (StudentPtr cursor = pStudents; cursor->nNumber != 0; cursor++)
    {
      if (cursor->nNumber < minNumber)
      {
        // printf("%d:before minNumber:%d\t", i, minNumber);
        minNumber = cursor->nNumber;
        // printf("after minNumber:%d\n", minNumber);
        minStudents = cursor;
      }
    }
  }
  else if (nByWhat == 2)
  {
    char minName[10];
    strcpy(minName, (pStudents)->strName);
    for (StudentPtr cursor = pStudents; cursor->nNumber > 0; cursor++)
    {
      if (strcmp(cursor->strName, minName))
      {
        strcpy(minName, cursor->strName);
        minStudents = cursor;
      }
    }
  }
  else if (nByWhat == 3)
  {
    double minGrade = (pStudents)->dGrade;
    for (StudentPtr cursor = pStudents; cursor->nNumber > 0; cursor++)
    {
      if (cursor->dGrade < minGrade)
      {
        minGrade = cursor->dGrade;
        minStudents = cursor;
      }
    }
  }
  return minStudents;
}

void StudentCmp(StudentPtr pStudent1, StudentPtr pStudent2, int nByWhat)
{
}

void Swap(StudentPtr pStudent1, StudentPtr pStudent2)
{
  Student tmp = *pStudent1;
  *pStudent1 = *pStudent2;
  *pStudent2 = tmp;
  // Student tmp;
  // tmp.nNumber = pStudent1->nNumber;
  // tmp.dGrade = pStudent1->dGrade;
  // strcpy(tmp.strName, pStudent1->strName);

  // pStudent1->nNumber = pStudent2->nNumber;
  // pStudent1->dGrade = pStudent2->dGrade;
  // strcpy(pStudent1->strName, pStudent2->strName);

  // pStudent2->nNumber = tmp.nNumber;
  // pStudent2->dGrade - tmp.dGrade;
  // strcpy(pStudent2->strName, tmp.strName);
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
      if (nNumber == (pStudent + i)->nNumber)
      {
        break;
      }
    }
  } while (i < nNdx);

  (pStudent + nNdx)->nNumber = nNumber;
  // printf("%d\'s nNumber is %d\n", nNdx, (pStudent+nNdx)->nNumber);

  int nLength = rand() % 5 + 5;
  for (int i = 0; i < nLength; i++)
  {
    char j = rand() % 25 + 97;
    (pStudent + nNdx)->strName[i] = j;
  }
  pStudent[nNdx].strName[nLength] = '\0';

  (pStudent + nNdx)->dGrade = (double)(rand() % 26 + 20) / 10;
}

void PrintArray(StudentPtr pStudents)
{
  void PrintStudent(StudentPtr pStudent, int nNdx);
  for (int i = 0; (pStudents + i)->nNumber > 0; i++)
    PrintStudent(pStudents, i);
  putchar('\n');
}

void PrintStudent(StudentPtr pStudent, int nNdx)
{
  printf("\t(%02d) %d %-9s %.1f\n", nNdx, (pStudent + nNdx)->nNumber, (pStudent + nNdx)->strName, (pStudent + nNdx)->dGrade);
}