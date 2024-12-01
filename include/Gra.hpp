# pragma once
#include <iostream>
#include "Firma.hpp"

class Gra{
public:
Gra () : stan{1}, stanf(1) {
 
   
}

enum wiado{
  blad_,
  lp_,
  zinz_,
  zmag_,
  zmkt_,
  zrob_,
  kred_,
  kt_,


};
wiado hashit(std::string const& inputs){
  if(inputs == "lp")  return lp_;
  if(inputs == "zinz") return zinz_;
  if(inputs == "zmag") return zmag_;
  if(inputs == "zmkt") return zmkt_;
  if(inputs == "zrob") return zrob_;
  if(inputs == "kred") return kred_;
  if(inputs == "kt") return kt_;

  return blad_;
}
void akcja_gracza(){
   
   stan = 1;
   std::cout<< "Ruch" << std::endl;
   std::string input;
   std::cin>> input;
   
   switch(hashit(input)){
    case lp_:
      firma.drukuj_pracownikow();
      break;
    case zinz_:{ 
       std::cout<< "Zatrudniłeś Inżyniera"<<std::endl; 
       std::cout<< "Podaj wydział" <<std::endl;
       std::string wydz;
       std::cin>> wydz;
       firma.zatrudnij(Inz(wydz));
      break;
    }
    case zmag_:{
       std::cout<< "Zatrudniłeś/aś Magazyniera"<<std::endl; 
       std::cout<< "Podaj czy obsługuje wózej widłowy" <<std::endl;
       bool obsl;
       std::cin>> obsl; 
       firma.zatrudnij(Mag(obsl));
        break;
    }
    case zmkt_:{
      std::cout<< "Zatrudniłeś/aś Marketera"<<std::endl; 
      std::cout<< "Podaj ilość follows" <<std::endl;
      int fol;
      std::cin>> fol; 
      firma.zatrudnij(Mkt(fol));
      break;
    }
    case zrob_:{
       std::cout<< "Zatrudniłeś/aś Robotnika"<<std::endl; 
       std::cout<< "Podaj rozmiar buta" <<std::endl;
       double bu;
       std::cin>> bu; 
       firma.zatrudnij(Rob(bu));
       break;
    }
    case kred_:
        double kw;
        int t;
        std::cout<< "Podaj czas spłaty" <<std::endl;
        std::cin >> t;
        std::cout<< "Podaj kwote" <<std::endl;
        std::cin >> kw;
        firma.wez_kredyt(kw,t);
      break;
    case kt_:
     firma.otrzymaj_przychod();
     firma.splac_raty();     
     firma.zaplac_wynagrodzenie();
     stan = 0;
     std::cout<<"Stan firmy"<<std::endl;
     std::cout<<"Wartość firmy: " << firma.wartosc_firmy() << std::endl;
     std::cout<<"Dług: " << firma.count_dlug() << std::endl;
     std::cout<<"Stan konta: "<< firma.get_stan_konta()<<std::endl;
     if((firma.wartosc_firmy() - firma.count_dlug()) > 50000 ){
       stanf = 2;
     }
     if(firma.get_stan_konta()<0){
      stanf = 0;
     }
     break;
    case blad_:{
      std::cout<< "Zły ruch" <<std::endl;
    }

   }
   
}
bool get_stan(){
  return stan;
}
int get_stanf(){
  return stanf;
}

void tick(){
  firma.tura++;
}

private:
bool stan;
int stanf;
Firma firma;

};