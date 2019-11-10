// ConsoleApplication3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "vector.h"

int main()
{
  //HIER IST ALLES NUR TEST
  cvector<size_t> MeinVektor1;

  size_t test = 1000;
  MeinVektor1.pushback(test);
  std::cout << "Intsaziierung :" << ": " << MeinVektor1.size() << std::endl;
  
  std::cout << MeinVektor1.capacity() << std::endl;
  std::cout << "Wert " << MeinVektor1[0] << std::endl;

  for (size_t i = 0; i < 13; i++)
  {
    MeinVektor1.pushback(i);
    std::cout << "Durchgang " << i << ": " << MeinVektor1.size() << std::endl;
    std::cout << MeinVektor1.capacity() << std::endl;
    std::cout << "Wert " << MeinVektor1.at(i+1) << std::endl;
  }
  

  MeinVektor1.resize(100);
  std::cout << "resize(100)" << ": " << MeinVektor1.size() << std::endl;
  std::cout << MeinVektor1.capacity() << std::endl;

  MeinVektor1.resize(3);
  std::cout << "resize(3)" << ": " << MeinVektor1.size() << std::endl;
  std::cout << MeinVektor1.capacity() << std::endl;

  MeinVektor1.resize(100);
  std::cout << "resize(100)" << ": " << MeinVektor1.size() << std::endl;
  std::cout << MeinVektor1.capacity() << std::endl;
  
  std::cout << "END" << MeinVektor1.at(2) << std::endl;


  /*for (size_t i = 0; i < 10; i++)
  {
    MeinVektor1.popback();
    std::cout << "Durchgang " << i << ": " << MeinVektor1.size() << std::endl;
    std::cout << MeinVektor1.capacity() << std::endl;
    std::cout << "Wert " << MeinVektor1[i+1] << std::endl;
  }*/
}

