#include <iostream>

using namespace std;
int main()
{
  int i, x;
  x = 10;

  // for loop
  for (i = 0; i < 5; i++)
  { 
    cout << " x=" << x << endl;
    x = x + 3;
  }
  cout << " x=" << x << " i=" << i << endl;


  // while loop
  i = 0;
  x = 10;
  while (i < 5)
  {
    cout << " x=" << x << endl;
    x = x + 3;
    i++;
  }
  cout << " x=" << x << " i=" << i << endl;

  return 0;
}