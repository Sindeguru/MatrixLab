#include <iostream>
#include "MyVector.h"
#include "Matrix.h"

using namespace std;
int main()
{
  Vector<int> a(3, 3);
  cout << a << endl;
  TMatrix<int> B(5,7);
  TMatrix<int> A(5,7);
  cout << B << endl;
  cout << A << endl;
  //B.SetObj(2, 3, -1);
  //cout << B << endl;
  cout << (A == B) << endl;
  return 0;
}
