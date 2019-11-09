#pragma once

#include <iostream>



template<class T>
class cvector
{
private:
  T* m_data;

  //actual used space of array
  size_t m_sizenow;
  //actual capacity
  size_t m_capnow;

  void resize(size_t newCap)
  {
    //mk temp array with size newsize
    //cp all Elements to m_sizenow to temporary array
    //delete old array
    //m_data points to new array
    //temp array pointer to nullptr
    //m_capnow = newCap
    T* newDataTemp;
    newDataTemp = new T[newCap];

    for (size_t i = 0; i < m_sizenow; i++)
    {
      newDataTemp[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newDataTemp;
    newDataTemp = nullptr;

    m_capnow = newCap;
  }



public:
  cvector()
  {
    m_data = new T[1];
    m_sizenow = 0;
    m_capnow = 1;
  }

  cvector(size_t size, T data)
  {
    //make array with Size size
    //write Data data to first place of the array
    if (size == 0)
    {
      return;
    }
    m_data = new T[size];
    m_capnow = size;
    m_data[0] = data;
    m_sizenow = 1;
  }

  ~cvector()
  {
    delete m_data;
    m_data = nullptr;
    m_sizenow = 0;
    m_capnow = 0;
  }

  void pushback(T data)
  {
    //if actual used space of array reaches allocated capacity  
    //-resize array with double size
    //write Data data in first free place of array
    //increment actual used space
    if (m_sizenow >= m_capnow)
    {
      resize(2*m_capnow);
    }
    m_data[m_sizenow] = data;
    m_sizenow++;
  }

  void popback()
  {
    //delete Data of last used space of array
    //decrement actual used space
    //if actual used space is smaller than 1/4 of allocated capacity
    //-resize array to 1/2 of actual capacity
    m_data[m_sizenow] = 0;
    m_sizenow--;
    if (m_sizenow < (0.25*m_capnow))
    {
      resize(0.5* m_capnow);
    }
  }

  size_t getSize()
  {
    return m_sizenow;
  }

  size_t getCapacity()
  {
    return m_capnow;
  }

  T operator[](size_t elemNum)
  {
    if (elemNum >= m_sizenow)
    {
      return 0;
    }
    return m_data[elemNum];
  }



};
