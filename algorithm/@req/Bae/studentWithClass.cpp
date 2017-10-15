/*
* 학생관리프로그램
* 2017.10.15
* Dyel
*/

// About Class : http://ra2kstar.tistory.com/146
// Class Array : https://stackoverflow.com/questions/1387101/c-class-instance-array-initialization
// Vector : https://stackoverflow.com/questions/755835/how-to-add-element-to-c-array

#include <iostream>

using namespace std;

class Stduent
{
private:
  int number;
  int hangle;
  int english;
  int math;

public:
  int set_Score_Hangle(int score)
  {
    this.hangle = score;
  };
  int set_Score_Engish(int score)
  {
    this.english = score;
  };
  int set_Score_math(int score)
  {
    this.math = score;
  };

  int get_Score_Hangle(void)
  {
    return this.hangle;
  };
  int get_Score_Engish(void)
  {
    return this.english;
  };
  int get_Score_math(void)
  {
    return this.math;
  }

  int get_Average_Score(void)
  {
    return (this.hangle + this.english + this.math) / 3;
  }

  Stduent(int number)
  {
    this.number = number;
    cout << "학생(" << this.number << ")------------" << endl;
    cout << "국어=";
    cin >> this.hangle;
    cout << "영어=";
    cin >> this.english;
    cout << "수학=";
    cin >> this.math;
  };
  ~Student()
  {
    //nothing.
  };
}

class SchoolClass
{
private:
  Student[] classStudent;
public:

  int get_minumum_value(){

  };
  int get_maximum_value(){
    
  };
  int get_Average_Score(){

  };

  SchoolClass(Student[] students){};
  ~SchoolClass(){};
}

int
main()
{
  return 0;
}
