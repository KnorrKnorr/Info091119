// ConsoleApplication3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "vector.h"

int main()
{
  cvector<size_t> MeinVektor1;

  size_t test = 1000;
  MeinVektor1.pushback(test);
  std::cout << "Intsaziierung :" << ": " << MeinVektor1.getSize() << std::endl;
  
  std::cout << MeinVektor1.getCapacity() << std::endl;
  std::cout << "Wert " << MeinVektor1[0] << std::endl;

  for (size_t i = 0; i < 13; i++)
  {
    MeinVektor1.pushback(i);
    std::cout << "Durchgang " << i << ": " << MeinVektor1.getSize() << std::endl;
    std::cout << MeinVektor1.getCapacity() << std::endl;
    std::cout << "Wert " << MeinVektor1[i] << std::endl;
  }
  

  /*MeinVektor1.resize(100);
  std::cout << "resize(10)" << ": " << MeinVektor1.getSize() << std::endl;
  std::cout << MeinVektor1.getCapacity() << std::endl;

  MeinVektor1.resize(100);
  std::cout << "resize(10)" << ": " << MeinVektor1.getSize() << std::endl;
  std::cout << MeinVektor1.getCapacity() << std::endl;
  */


  /*for (size_t i = 0; i < 10; i++)
  {
    MeinVektor1.popback();
    std::cout << "Durchgang " << i << ": " << MeinVektor1.getSize() << std::endl;
    std::cout << MeinVektor1.getCapacity() << std::endl;
    std::cout << "Wert " << MeinVektor1[i+1] << std::endl;
  }*/
}

