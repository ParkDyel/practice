#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable : 4996)

#define Counter 5

typedef struct
{
  int nNumber;
} Student, *StudentPtr;

void PrintArray(StudentPtr pStudent);

int main(int argc, char *argv[])
{
  int nCtr = Counter;
  Student arrStudent[Counter + 1];
  for (int i = 0; i < Counter; i++)
  {
    (arrStudent + i)->nNumber = Counter + 5 - i;
  }
  arrStudent[nCtr + 1].nNumber = 0;

  printf("Address:%x\n", arrStudent);
  printf("\n\n[non-sorting List]\n");
  PrintArray(arrStudent);

  void SortStudent(StudentPtr pStudents);
  SortStudent(arrStudent);
  printf("[Sorting by Student ID]\n");
  PrintArray(arrStudent);

  return 0;
}

void SortStudent(StudentPtr pStudents)
{
  StudentPtr FindMinimum(StudentPtr pStudents);
  void Swap(StudentPtr pStudent1, StudentPtr pStudent2);
  for (int i = 0; (pStudents + i)->nNumber > 0; i++)
  {
    // printf("%d:%d\n", i, (pStudents+i)->nNumber);
    // printf("%d call: \n", i);
    Swap(pStudents + i, FindMinimum(pStudents + i + 1));
    // printf("%d\n", (pStudents + i)->nNumber);
    PrintArray(pStudents);
  }
}

StudentPtr FindMinimum(StudentPtr pStudents)
{
  int idx = -1;
  int minNumber = pStudents->nNumber;
  printf("before-min:%d\n", minNumber);
  for (int i = 1; (pStudents + i)->nNumber > 0; i++)
  {
    if ((pStudents + i)->nNumber < minNumber)
    {
      minNumber = (pStudents + i)->nNumber;
      idx = i;
    }
  }
  printf("after-min:%d\n", minNumber);
  // printf("minAddress:%x\n", pStudents + idx);
  return pStudents + idx;
}

void Swap(StudentPtr pStudent1, StudentPtr pStudent2)
{
  // if (pStudent1->nNumber != pStudent2->nNumber)
  // {
  Student tmp = *pStudent1;
  *pStudent1 = *pStudent2;
  *pStudent2 = tmp;
  // }
}

void PrintArray(StudentPtr pStudents)
{
  void PrintStudent(StudentPtr pStudent, int nNdx);
  for (int i = 0; pStudents[i].nNumber != 0; i++)
    PrintStudent(pStudents, i);
  putchar('\n');
}

void PrintStudent(StudentPtr pStudent, int nNdx)
{
  printf("(%02d) %d\n", nNdx, pStudent[nNdx].nNumber);
}