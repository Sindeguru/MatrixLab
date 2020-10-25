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

}

template<class T>
inline TMatrix<T>::TMatrix(int s, T el) : Vector<Vector<T>>(s)
{

}


template<class T>
inline TMatrix<T>::TMatrix(TMatrix<T>& A) : Vector<Vector<T>>(A)
{

}
 

template<class T>
inline TMatrix<T>::~TMatrix()
{

}

template<class T>
inline void TMatrix<T>::SetObj(int a, int b, T ab)
{

}

template<class T>
inline T TMatrix<T>::GetObj(int a, int b)
{

}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& A)
{

}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& A)
{

}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& A)
{

}

template<class T>
inline int TMatrix<T>::operator==(TMatrix<T>& A)
{

}
