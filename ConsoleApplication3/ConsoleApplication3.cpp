// ConsoleApplication3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "vector.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("First Test")
{
  //Instancing the vector Test1
  cvector<int> Test1;
  //Testing the standard constructor
  REQUIRE(Test1.capacity() == 1);
  REQUIRE(Test1.size() == 0);

  //calling push_back on Test1 ten times
  for (int i = 0; i < 10; i++)
  {
    Test1.push_back(i);
  }
  //Testing the result of push_back
  REQUIRE(Test1.size() == 10);
  REQUIRE(Test1.capacity() == 16);

  //Calling pop_back seven times
  for (int i = 0; i < 7; i++)
  {
    Test1.pop_back();
  }
  //Testing the result of pop_back
  REQUIRE(Test1.size() == 3);
  REQUIRE(Test1.capacity() == 8);

  //Testing at function and bracket operator
  REQUIRE(Test1.at(2) == 2);
  REQUIRE(Test1[2] == 2);

  //Instancing the Vector Test2 with default capacity 28
  cvector<int> Test2(28);
  REQUIRE(Test2.capacity() == 28);
  REQUIRE(Test2.size() == 0);

  //Testing the assignment operator
  Test2 = Test1;
  REQUIRE(Test2.capacity() == Test1.capacity());
  REQUIRE(Test2.size() == Test1.size());
  REQUIRE(Test2.at(1) == Test1.at(1));

  //Testing resize method with value bigger than actual size
  Test1.resize(100);
  REQUIRE(Test1.capacity() == 100);
  REQUIRE(Test1.size() == 3);

  //Testing resize method with value smaller than actual size
  Test1.resize(2);
  REQUIRE(Test1.capacity() == 2);
  REQUIRE(Test1.size() == 2);

  //Testing resize method with value = 0
  Test1.resize(0);
  REQUIRE(Test1.capacity() == 0);
  REQUIRE(Test1.size() == 0);

  //testing copy constructor
  cvector<int> Test3(Test2);
  REQUIRE(Test2.capacity() == Test3.capacity());
  REQUIRE(Test2.size() == Test3.size());
  REQUIRE(Test2.at(1) == Test3.at(1));

}




