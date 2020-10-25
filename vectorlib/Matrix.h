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
  //TMatrix(int s, T el);
  TMatrix(TMatrix<T>& A); //coopirate
  ~TMatrix();

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
  if (s > MAX_MATRIX_SIZE) throw logic_error("");
  for (int i = 0; i < this->length - this->si; i++)
  {
    Vector<T>res(s - i, i);
    this->vec[i] = res;
  }
}

/*
template<class T>
inline TMatrix<T>::TMatrix(int s, T el) : Vector<Vector<T>>(s)
{
  if ((s < 0) || (s > MAX_MATRIX_SIZE)) throw logic_error("Incorrect");
  arr = new Vector<T>[s];
  for (int i = 0; i < s; i++)
  {   
    Vector<T> v(s - i, i);
    arr[i] = v;
    for (int j = 0; j < i; j++)
      arr[i].SetElem(j, 0);
  }
}
*/

template<class T>
inline TMatrix<T>::TMatrix(TMatrix<T>& A) : Vector<Vector<T>>(A)
{
  for (int i = this->si; i < this->length; i++)
  {
    Vector<T>res(A[i]);
    (*this)[i] = res;
  }

  length = A.length;

  arr = new Vector<T>[length];
  for (int i = 0; i < length; i++)
  {
    arr[i] = A.arr[i];
  }
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
 // delete[]arr;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& A)
{
  if (&A == this)
  {
    return (*this);
  }
  if (this->GetLength() == A.GetLength())
  {
    for (int i = 0; i < this->length - this->si; i++)
    {
      (*this).vec[i] = A.vec[i];
    }
    return(*this);
  }
  delete[]vec;
  vec = new Vector<T>[A.GetLength() - A.GetSI()];

  (*this).si = A.si;
  (*this).si = A.si;
  for (int i = (*this).GetSI(); i < (*this).GetLength(); i++)
  {
    (*this)[i] = A[i];
  }
  return (*this);
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& A)
{
  TMatrix<T> tmp(*this);

  for (int i = 0; i < this->length-si; i++)
    tmp.x[i] = tmp.x[i] + A.x[i];

  return tmp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& A)
{
  TMatrix<T> tmp(*this);

  for (int i = 0; i < this->length-si; i++)
    tmp.x[i] = tmp.x[i] - A.x[i];

  return tmp;
}

template<class T>
inline int TMatrix<T>::operator==(TMatrix<T>& A)
{
  if (this == &A) return 1;
  if (((*this).GetSI() == A.GetSI()) && ((*this).GetLength() == A.GetLength()))
  {
    for (int i = A.GetSI(); i < A.GetLength(); i++)
    {
      if ((*this)[i] != A[i])
      {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}
