// ConsoleApplication3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "vector.h"

int main()
{
  cvector<int> MeinVektor1;

  for (size_t i = 0; i < 1000; i++)
  {
    MeinVektor1.pushback(i);
    std::cout << "Durchgang " << i << ": " << MeinVektor1.getSize() << std::endl;
    std::cout << MeinVektor1.getCapacity() << std::endl;
    std::cout << "Wert " << MeinVektor1[i+1] << std::endl;
  }

  for (size_t i = 0; i < 10; i++)
  {
    MeinVektor1.popback();
    std::cout << "Durchgang " << i << ": " << MeinVektor1.getSize() << std::endl;
    std::cout << MeinVektor1.getCapacity() << std::endl;
    std::cout << "Wert " << MeinVektor1[i+1] << std::endl;
  }
}

