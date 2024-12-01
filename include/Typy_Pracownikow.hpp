#pragma once
#include <iostream>
#include "RandomNameGenerator.hpp"
#include "PrinterPracownikow.hpp"
#include "Gra.hpp"



class Pracownik{
public:
Pracownik(): name{getRandomName()}{

}
virtual ~Pracownik() = default;


virtual void print(){

}
std::string name;
private:

};


class Inz: public Pracownik{
public:
Inz(){

}
Inz(std::string wydziall): wydzial{wydziall}, Pracownik(){

}
void print() const {
  std::cout<<"Inżynier/ka: "<< name << "\t" << wydzial <<std::endl;
  
}
static const unsigned int CI = 14;

private:
std::string wydzial;
};

class Mkt: public Pracownik{
public:
Mkt(){

}
Mkt(int followss): follows{followss}, Pracownik(){

}
void print() const{
   std::cout<<"Marketer/ka: "<< name << "\t" << follows <<std::endl;
}
static const unsigned int CMkt =12;
private:
int follows;
};

class Mag: public Pracownik{
public:
Mag(){

}
Mag(bool obsl_widll): obsl_widl{obsl_widll}, Pracownik(){

}
void print() const {
   std::cout<<"Magazynier/ka: "<< name << "\t" << obsl_widl <<std::endl;
}
static const unsigned int CMag=20;
private:
bool obsl_widl;
};

class Rob: public Pracownik{
public:
Rob(){

}
Rob (double buut): but{buut}, Pracownik(){
    
}
void print() const{
  std::cout<<"Robotnik/czka: "<< name << "\t" << but <<std::endl;
}
static const unsigned int CR=15;
private:
double but;
};