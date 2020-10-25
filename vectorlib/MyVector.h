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
  Vector(int s = 10, int si_ = 0);          // Присваивания и по умолчанию
  Vector(const Vector& v);                // конструктор копирования
  ~Vector();

  T GetElem(int s);
  int GetLength();
  void SetElem(int n, T s);
  int GetSI();
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
template<class T>
inline Vector<T>::Vector(int s, int si_)
{
  length = s;
  x = new T[length];
  si = si_;
  for (int i = 0; i = length - si; i++)
    x[i] = 0;
}

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
  length = v.length;
  x = new T[length];
  for (int i = 0; i < length; i++)
    x[i] = v.x[i];
  si = v.si;
}



template <class T>
Vector<T>::~Vector()
{
  length = 0;
  si = 0;
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
  if(n-si > this->GetLength()) throw logic_error("Invalid index");
  x[n-si] = s;
}

template<class T>
inline int Vector<T>::GetLength()
{
  return this->length;
}

template<class T>
inline int Vector<T>::GetSI()
{
  return this->si;
}

//OPERATORS

template <class T>
Vector<T> Vector<T>::operator +(Vector<T>& _v)
{
  Vector<T> res;
  res.length = MIN(length, _v.length);
  res.x = new T[res.length];
  for (int i = 0; i < res.length - res.GetSI(); i++)
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
  for (int i = 0; i < res.length-res.GetSI(); i++)
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
  for (int i = 0; i < res.length-res.GetSI(); i++)
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
  for (int i = 0; i < res.length-res.GetSI(); i++)
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
  for (int i = 0; i < length-si; i++)
    x[i] = _v.x[i];
  return *this;
}
template<class T>
inline int Vector<T>::operator==(Vector<T>& _v)
{
  if(GetLength() != _v.GetLength())
    return 0;
  for (int i = 0; i < _v.GetLength() - _v.GetSI(); i++)
    if (this->x[i] != _v[i])
      return 0;
  return 1;
}
template<class T>
inline int Vector<T>::operator!=(Vector<T>& _v)
{
  if (GetLength() != _v.GetLength())
    return 1;
  for (int i = 0; i < _v.GetLength()- _v.GetSI(); i++)
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
  for (int i = 0; i < length-si; i++)
    x[i]++;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator --()
{
  for (int i = 0; i < length-si; i++)
    x[i]--;
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator +=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length-si; i++)
  {
    x[i] += _v.x[i];
  }
  return *this;
}
template <class T>
Vector<T>& Vector<T>::operator -=(Vector<T>& _v)
{
  length = MIN(length, _v.length);
  for (int i = 0; i < length-si; i++)
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
  for (int i = 0; i < A.length-A.GetSI(); i++) {
    ostr << A.x[i] << ' ';
  }
  ostr << endl;
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, Vector<T1>& A) {
  for (int i = 0; i < A.length-A.GetSI(); i++) {
    istr >> A.x[i];
  }
  return istr;
}

#endif