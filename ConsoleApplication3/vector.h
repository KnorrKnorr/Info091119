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

  void resizelocal(size_t newCap)
  {
    //mk temp array with size newsize
    //if newCap is bigger than used space
    //-copy all elements of old array to new array, size stays same, cap gets bigger
    //-else if newCap is equal or smaller than used space
    //-fullfill the new array with old data, size gets smaller, cap get smaller
    //delete old array
    //m_data points to new array
    //temp array pointer to nullptr
    //m_capnow = newCap
    T* newDataTemp;
    newDataTemp = new T[newCap];

    if (newCap > m_sizenow)
    {
      std::copy(m_data, m_data + m_sizenow, newDataTemp);
      m_capnow = newCap;
    }
    else
    {
      std::copy(m_data, m_data + newCap, newDataTemp);
      m_sizenow = newCap;
      m_capnow = newCap;
    }
    delete[] m_data;
    m_data = newDataTemp;
    newDataTemp = nullptr;    
  }



public:
  cvector()
  {
    //even standard constructor immediately allocates one element 
    m_data = new T[1];
    m_sizenow = 0;
    m_capnow = 1;
  }

  cvector(size_t capacity)
  {
    //mk array with m_capnow capacity
    if (capacity == 0)
    {
      return;
    }
    m_data = new T[capacity];
    m_capnow = capacity;
    m_sizenow = 0;
  }

  cvector(const cvector& v)
  {
    //copy-constructor from cvector v

    m_capnow = v.m_capnow;
    m_sizenow = v.m_sizenow;

    m_data = new T[m_capnow];

    if (m_sizenow > 0)
    {
      std::copy(v.m_data, v.m_data + m_sizenow, m_data);
    }
    else
    {
      m_data = nullptr;
    }
  }

  ~cvector()
  {
    if (m_data != nullptr)
    {
      delete m_data;
      m_data = nullptr;
    }
    m_sizenow = 0;
    m_capnow = 0;
  }

  void pushback(const T& data)
  {
    //if actual used space of array reaches allocated capacity  
    //-resize array with double size 
    //write Data data in first free place of array
    //increment actual used space
    if (m_sizenow >= m_capnow)
    {
      resizelocal(2*m_capnow);
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
      resizelocal(0.5* m_capnow);
    }
  }

  void resize(size_t value)
  {
    //call resizelocal
    resizelocal(value);
  }

  size_t size() const
  {
    return m_sizenow;
  }

  size_t capacity() const
  {
    return m_capnow;
  }

  T& operator[](size_t elemNum)
  {
    //if m_data exists and element m_data[elemNum] exists, return m_data[elemNum]
    if (elemNum >= m_sizenow || m_data == nullptr)
    {
      //return 0;
      throw std::invalid_argument("");
    }
    return m_data[elemNum];
  }

  T& operator[](size_t elemNum) const
  {
    //if m_data exists and element m_data[elemNum] exists, return m_data[elemNum]
    if (elemNum >= m_sizenow || m_data == nullptr)
    {
      //return 0;
      throw std::invalid_argument("");
    }
    return m_data[elemNum];
  }

  T& at(size_t elemNum)
  {
    //if m_data exists and element m_data[elemNum] exists, return m_data[elemNum]
    if (elemNum >= m_sizenow || m_data == nullptr)
    {
      //return = 0;
      throw std::invalid_argument("");
    }
    return m_data[elemNum];
  }

  cvector& operator=(const cvector& v)
  {
    if (m_data != nullptr)
    {
      delete[] m_data;
    }
    m_capnow = v.m_capnow;
    m_sizenow = v.m_sizenow;
    std::copy(v.m_data, v.m_data + m_sizenow, m_data);

    return cvector;
  }
};
