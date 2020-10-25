#pragma once
#pragma once

#include "MyVector.h"
const int MAX_MATRIX_SIZE = 10000;



template <class T>
class TMatrix : public Vector<Vector<T>>
{
protected:
  Vector<T>* arr;
public:
  TMatrix(int s = 3);
  TMatrix(int s, T el);
  TMatrix(TMatrix<T>& A);
  ~TMatrix();

  void SetObj(int a, int b, T ab);
  T GetObj(int a, int b);

  TMatrix<T>& operator = (const TMatrix<T>& A);
  TMatrix<T> operator + (const TMatrix<T>& A);
  TMatrix<T> operator - (const TMatrix<T>& A);
  int operator ==(TMatrix<T>& A);


  friend istream& operator>>(istream& in, TMatrix& mt)
  {
    for (int i = 0; i < mt.GetLength(); i++)
      in >> mt.arr[i];
    return in;
  }
  friend ostream& operator<<(ostream& out, TMatrix& mt)
  {
    for (int i = 0; i < mt.GetLength(); i++)
      out << mt.arr[i] << endl;
    return out;
  }
};

template<class T>
inline TMatrix<T>::TMatrix(int s) : Vector<Vector<T>>(s)
{
  if ((s < 0) || (s > MAX_MATRIX_SIZE)) throw logic_error("Incorrect");
  Vector<T> v(s, 0);
  arr = new Vector<T>[s];
  for (int i = 0; i < s; i++)
  {
    arr[i] = v;
  }
}

template<class T>
inline TMatrix<T>::TMatrix(int s, T el) : Vector<Vector<T>>(s)
{
  if ((s < 0) || (s > MAX_MATRIX_SIZE)) throw logic_error("Incorrect");
  Vector<T> v(s, el);
  arr = new Vector<T>[s];
  for (int i = 0; i < s; i++)
  {   
    arr[i] = v;
    for (int j = 0; j < i; j++)
      arr[i].SetElem(j, 0);
  }
}


template<class T>
inline TMatrix<T>::TMatrix(TMatrix<T>& A) : Vector<Vector<T>>(A)
{
  for (int i = 0; i < (*this).GetLength(); i++)
  {
    Vector<T>A(A[i]);
    (*this)[i] = A;
  }
  /*
  Vector<T> v(A.GetLength(), 0);
  arr = new Vector<T>[A.GetLength()];
  for (int i = 0; i < A.GetLength(); i++)
  {
    for (int j = 0; j < A.GetLength(); j++)
      this->SetObj(i,j,A.GetObj(i,j));
  }*/
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
 // delete[]arr;
}

template<class T>
inline void TMatrix<T>::SetObj(int a, int b, T ab)
{
  arr[a].SetElem(b, ab);
}

template<class T>
inline T TMatrix<T>::GetObj(int a, int b)
{
  return arr[a].GetElem(b);
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& A)
{
  if (this != &A)
  {
    Vector<Vector<T>>:: operator= (A);
  }
  return *this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& A)
{
  TMatrix<T> tmp(*this);

  for (int i = 0; i < this->length; i++)
    tmp.x[i] = tmp.x[i] + A.x[i];

  return tmp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& A)
{
  TMatrix<T> tmp(*this);

  for (int i = 0; i < this->length; i++)
    tmp.x[i] = tmp.x[i] - A.x[i];

  return tmp;
}

template<class T>
inline int TMatrix<T>::operator==(TMatrix<T>& A)
{
  if (this->GetLength() != A.GetLength())
    return 0;
  for (int i = 0; i < A.GetLength(); i++)
    if(this->arr[i] != A.arr[i])
        return 0;
  return 1;
}
