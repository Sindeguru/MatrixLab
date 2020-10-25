#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;

template <class T>
class Vector
{
protected:
  int length;
  int si;
  T* x;
public:
  Vector<T>* vec;
  //Конструкторы
  Vector();
  //Vector(T _v);
  Vector(int _v, int _si);
  Vector(int rowsCount, T* _v);
  //Vector(int rowsCount, T _v);
  Vector(Vector<T>& _v);
  ~Vector();

  T GetElem(int s);
  int GetLength();
  void SetElem(int n, T s);
  //Операторы стандартные
  Vector<T> operator +(Vector<T>& _v);
  Vector<T> operator -(Vector<T>& _v);
  Vector<T> operator *(Vector<T>& _v);
  Vector<T> operator /(Vector<T>& _v);
  Vector<T>& operator =(Vector<T>& _v);
  int operator==(Vector<T>& _v);
  int operator!=(Vector<T>& _v);
  T& operator[] (const int index);
  //Операторы, упрощающие жизнь
  Vector<T>& operator ++();
  Vector<T>& operator --();
  Vector<T>& operator +=(Vector<T>& _v);
  Vector<T>& operator -=(Vector<T>& _v);
  //Ввод-ввывод
  template <class T1>
  friend ostream& operator<< (ostream& ostr, const Vector<T1>& A);
  template <class T1>
  friend istream& operator >> (istream& istr, Vector<T1>& A);

  int Length();
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)

template <class T>
Vector<T>::Vector()
{
  length = 0;
  x = 0;
  si = 0;
}

template <class T>
Vector<T>::Vector(int _v, int _si)
{
  length = _v;
  x = new T[length];
  si = _si;
  //x[0] = _v;
}
template <class T>
Vector<T>::Vector(int rowsCount, T* _v)
{
  length = rowsCount;

  x = new T[length];
  for (int i = 0; i < length; i++)
    x[i] = _v[i];
  si = 0;
}
/*template <class T>

Vector<T>::Vector(int rowsCount, T _v)
{
  length = rowsCount;
  x = new T[length];
  for (int i = 0; i < length; i++)
    x[i] = _v;
  si = 0;
}
*/
template <class T>
Vector<T>::Vector(Vector<T>& _v)
{
  length = _v.length;
  x = new T[length];
  for (int i = 0; i < length; i++)
    x[i] = _v.x[i];
  si = _v.si;
}
template <class T>
Vector<T>::~Vector()
{
  length = 0;
  if (x != 0)
    delete[] x;
  x = 0;
}
template<class T>
inline T Vector<T>::GetElem(int s)
{
  return x[s];
}

template<class T>
void Vector<T>::SetElem(int n, T s)
{
  if(n > this->GetLength()) throw logic_error("Invalid index");
  x[n] = s;
}

template<class T>
inline int Vector<T>::GetLength()
{
  return this->length;
}

//OPERATORS

template <class T>
Vector<T> Vector<T>::operator +(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T[res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] + _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator -(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T[res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] - _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator *(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T[res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] * _v.x[i];
  }
  return res;
}
template <class T>
Vector<T> Vector<T>::operator /(Vector<T>& _v)

{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T[res.length];
  for (int i = 0; i < res.length; i++)
  {
    res.x[i] = x[i] / _v.x[i];
  }
  return res;
}
template <class T>
Vector<T>& Vector<T>::operator =(Vector<T>& _v)
{
   if (this == &_v)
    return *this;

  length = _v.length;
  x = new T[length];
  for (int i = 0; i < length; i++)
    x[i] = _v.x[i];
  return *this;
}
template<class T>
inline int Vector<T>::operator==(Vector<T>& _v)
{
  if(GetLength() != _v.GetLength())
    return 0;
  for (int i = 0; i < _v.GetLength(); i++)
    if (this->x[i] != _v[i])
      return 0;
  return 1;
}
template<class T>
inline int Vector<T>::operator!=(Vector<T>& _v)
{
  if (GetLength() != _v.GetLength())
    return 1;
  for (int i = 0; i < _v.GetLength(); i++)
    if (this->x[i] != _v[i])
      return 1;
  return 0;
}
template <class T>
T& Vector<T>::operator[] (const int index)
{
  if ((index-si >= 0) && (index-si < length))
    return x[index-si];
  throw logic_error("Out of Range");
}

template <class T>
Vector<T>& Vector<T>::operator ++()
{
  for (int i = 0; i < length; i++)
    x[i]++;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator --()
{
  for (int i = 0; i < length; i++)
    x[i]--;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator +=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] += _v.x[i];
  }
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator -=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length; i++)
  {
    x[i] -= _v.x[i];
  }
  return *this;
}
template <class T>
int Vector<T>::Length()
{
  return length;
}
template <class T1>
ostream& operator<< (ostream& ostr, const Vector<T1>& A) {
  for (int i = 0; i < A.length; i++) {
    ostr << A.x[i] << ' ';
  }
  ostr << endl;
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, Vector<T1>& A) {
  for (int i = 0; i < A.length; i++) {
    istr >> A.x[i];
  }
  return istr;
}

#endif