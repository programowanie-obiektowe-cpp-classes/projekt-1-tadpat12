#pragma once
#include <iostream>
#include "Typy_Pracownikow.hpp"

class PrinterPracownikow{
public:
  template<typename T>
  void  operator() (const T& t){
     t.print();
   };
};