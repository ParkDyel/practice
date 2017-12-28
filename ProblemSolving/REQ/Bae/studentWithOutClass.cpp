/*
* 학생관리프로그램
* 2017.10.15
* Dyel
*/

// 무한반복이라는게 무슨 뜻인지 알지 못한다. 이 프로그램 자체를 무한 반복하길 바라는 것이라면 main 코드를 wrap해서 while 돌리면 될듯.

#include <iostream>

using namespace std;

// 학생 점수 구조체
typedef struct _student_score
{
  int hangle;
  int english;
  int math;
  int avg;
} student_score;

// functions

int get_min_max_sum(student_score *className, int numOfStudent, student_score *calculate); // 첫 번재 인자 구조체 포인터의 각 과목별 최대값, 최소값, 평균값을 계산하여 세번째 인자 구조체에 대입한다.


int main()
{
  // get number of Student want to management.
  int numOfStudent = 0;
  cout << "numOfStudent=";
  cin >> numOfStudent;

  // for loop index
  int index = 0;

  // malloc:
  student_score *dong_buk_1_13 = new student_score[numOfStudent];

  { // all_avg scope
    int all_avg = 0;
    // get student score hangle, english, math and calcualte average score.
    // for loop : numOfStudent
    for (index = 0; index < numOfStudent; index++)
    {
      int avg;
      cout << "Student (" << index << ")------------" <<endl;
      cout << "hangle=";
      cin >> dong_buk_1_13[index].hangle;
      cout << "english=";
      cin >> dong_buk_1_13[index].english;
      cout << "math=";
      cin >> dong_buk_1_13[index].math;

      avg = (dong_buk_1_13[index].hangle + dong_buk_1_13[index].english + dong_buk_1_13[index].math) / 3;
      all_avg += avg;
      cout << "Average = " << avg << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Average = " << all_avg << endl;
  }


  // malloc : struct student_score for assign class minimum, maximum value and average value
  student_score *dong_buk_1_13_calculate = new student_score[3];

  // call get_min_max_sum
  get_min_max_sum(dong_buk_1_13, numOfStudent, dong_buk_1_13_calculate);

  // printf calculate.
  cout << "\t국어\t영어\t수학" << endl;
  cout << "----------------------------------" << endl;
  cout << "최고\t" << dong_buk_1_13_calculate[0].hangle << "\t" << dong_buk_1_13_calculate[0].english << "\t" << dong_buk_1_13_calculate[0].math << endl;
  cout << "최저\t" << dong_buk_1_13_calculate[1].hangle << "\t" << dong_buk_1_13_calculate[1].english << "\t" << dong_buk_1_13_calculate[1].math << endl;
  cout << "-------------------" << endl;
  cout << "평균\t" << dong_buk_1_13_calculate[2].hangle << "\t" << dong_buk_1_13_calculate[2].english << "\t" << dong_buk_1_13_calculate[2].math << endl;

  // free malloc
  delete[] dong_buk_1_13_calculate;
  delete[] dong_buk_1_13;

  return 0;
}

int get_min_max_sum(student_score *className, int numOfStudent, student_score *calculate)
{
  int index;
  int maximum_hangle = -1;
  int minimum_hangle = 101;
  int sum_hangle = 0;
  int maximum_english = -1;
  int minimum_english = 101;
  int sum_english = 0;
  int maximum_math = -1;
  int minimum_math = 101;
  int sum_math = 0;

  for (index = 0; index < numOfStudent; index++)
  {
    // for sum value.
    sum_hangle += className[index].hangle;
    sum_english += className[index].english;
    sum_math += className[index].math;

    // calculate minimum, and maximum value.
    if (className[index].hangle < minimum_hangle)
      minimum_hangle = className[index].hangle;
    else if (className[index].hangle > maximum_hangle)
      maximum_hangle = className[index].hangle;

    if (className[index].english < minimum_english)
      minimum_english = className[index].english;
    else if (className[index].english > maximum_english)
      maximum_english = className[index].english;

    if (className[index].math < minimum_math)
      minimum_math = className[index].math;
    else if (className[index].math > maximum_math)
      maximum_math = className[index].math;
  }

  //assign minimum, maximum, average value.
  calculate[0].hangle = maximum_hangle;
  calculate[0].english = maximum_english;
  calculate[0].math = maximum_math;

  calculate[1].hangle = minimum_hangle;
  calculate[1].english = minimum_english;
  calculate[1].math = minimum_math;

  calculate[2].hangle = sum_hangle / numOfStudent;
  calculate[2].english = sum_english / numOfStudent;
  calculate[2].math = sum_math / numOfStudent;

  return 0;
}