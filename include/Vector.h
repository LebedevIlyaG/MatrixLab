#pragma once

#include <iostream>

template <class T>
class TVector
{
protected:
  int size;
  T* data;
public:
  TVector(int _size = 0);
  TVector(const TVector<T>& p);
  TVector(TVector<T>&& p);
  ~TVector();

  TVector<T>& operator = (const TVector<T>& p);
  TVector<T>& operator = (TVector<T>&& p);

  TVector<T> operator + (const TVector<T>& p);
  TVector<T> operator - (const TVector<T>& p);
  TVector<T> operator * (const TVector<T>& p);

  TVector<T> operator + (double p);
  TVector<T> operator - (double p);
  TVector<T> operator * (double p);

  T& operator [] (int i);

  int GetSize();

  void Random();

};

template <class T>
std::ostream& operator << (std::ostream& o, TVector<T>& p)
{
  for (int i = 0; i < p.GetSize(); i++)
  {
    o << p[i] << "\t";
  }
}

template<class T>
inline TVector<T>::TVector(int _size)
{
  if (_size < 0) throw "error _size";
  else if(_size == 0)
  {
    data = nullptr;
    size = 0;
  }
  else
  {
    size = _size;
    data = new T[size];
  }
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
  if (p.data == nullptr)
  {
    data = nullptr;
    size = 0;
  }
  else
  {
    size = p.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
      data[i] = p.data[i];
  }
}

template<class T>
inline TVector<T>::TVector(TVector<T>&& p)
{
  data = p.data;
  size = p.size;

  p.data = nullptr;
  p.size = 0;
}

template<class T>
inline TVector<T>::~TVector()
{
  if (data != nullptr)
    delete[] data;
  data = nullptr;
  size = 0;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
  if (this == &p)
    return *this;

  if (data != nullptr)
    delete[] data;

  TVector<T>::TVector(p);
  return *this;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(TVector<T>&& p)
{
  data = p.data;
  size = p.size;

  p.data = nullptr;
  p.size = 0;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
  if (size != p.size)
    throw "error";

  TVector<T> res(*this);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] + p.data[i];

  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
  if (size != p.size)
    throw "error";

  TVector<T> res(*this);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] - p.data[i];

  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
  if (size != p.size)
    throw "error";

  TVector<T> res(*this);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] * p.data[i];

  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator+(double p)
{
  TVector<T> res(*this);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] + p;

  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator-(double p)
{
  TVector<T> res(*this);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] - p;

  return res;
}

template<class T>
inline TVector<T> TVector<T>::operator*(double p)
{
  TVector<T> res(*this);

  for (int i = 0; i < size; i++)
    res.data[i] = data[i] * p;

  return res;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
  if (i >= 0 && i < size)
    return data[i];
  else
    throw "error";
}

template<class T>
inline int TVector<T>::GetSize()
{
  return size;
}

template<class T>
inline void TVector<T>::Random()
{
  for (int i = 0; i < size; i++)
    data[i] = rand();
}
