
#include <iostream>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <locale>
#include <memory>
#include <stdexcept>
#include <variant>
#include "PrinterPracownikow.hpp"
#include "Typy_Pracownikow.hpp"
#include "Kredyt.hpp"



class Firma {
public:
Firma () : n_prac{0}, n_kredytow{0}, stan_konta{100000}, tura{0} {

   zatrudnij(Mkt(100));
   zatrudnij(Mag(1));
   zatrudnij(Inz("meil"));
   zatrudnij(Rob(42.5));

   std::cout<< "Stan konta \t" << get_stan_konta() << std::endl; 
   drukuj_pracownikow();
}


void drukuj_pracownikow() const{
   for (size_t i = 0; i < n_prac; ++i) {
        std::visit(PrinterPracownikow(), prac[i]);
   }
}
void wez_kredyt(double kwota, int czas_splaty){
   stan_konta = stan_konta + kwota;
   kredyty[n_kredytow] = Kredyt(kwota, czas_splaty) ;
   n_kredytow++;
}
void zatrudnij(const auto& pracownik_t){
   prac[n_prac] = pracownik_t;
   n_prac++;
}
void zaplac_wynagrodzenie(){
   int n_inz=0,n_mag=0,n_mkt=0,n_rob=0;
   auto count_prac = [&n_inz,&n_mag,&n_mkt,&n_rob](auto&& variant) {
        using T = std::decay_t<decltype(variant)>;
        if (std::is_same_v<T,Inz>) {
            ++n_inz;
        }
        else if (std::is_same_v<T,Mag>) {
            ++n_mag;
        }
        else if (std::is_same_v<T,Mkt>){
           ++n_mkt;
        }
        else if(std::is_same_v<T,Rob>){
          ++n_rob;
        }
        
   };
   for (size_t i = 0; i < n_prac; ++i) {
        std::visit(count_prac, prac[i]);
   }
   double wynagrodz = n_inz*5000 + n_mag*3000 + n_mkt*4000 + n_rob*4500;
   std::cout<<"wynagrodzenie"<< wynagrodz <<std::endl;
   stan_konta = stan_konta - (n_inz*5000 + n_mag*3000 + n_mkt*4000 + n_rob*4500);
   
}
void otrzymaj_przychod(){
  std::cout<< oblicz_przychod() <<std::endl;
  stan_konta = stan_konta + oblicz_przychod();
}
void splac_raty(){
   double raty =0;
   for(int i = 0; i < n_kredytow; i++ ){
      raty= raty + kredyty[i].splac_rate();
   }
   stan_konta = stan_konta - raty;
  
}
double get_stan_konta() const{

    return stan_konta;

}
double wartosc_firmy(){
   if(tura >= 3){
    double c=0;
    for(int i = tura; i>tura-N; i--){
    c = c + historiaprzych[i];
    }
    c = c/N;
    return c;
   }
   else{
    return 0;
   }
}
double oblicz_przychod(){
   
   int n_inz=0,n_mag=0,n_mkt=0,n_rob=0;
   auto count_prac = [&n_inz,&n_mag,&n_mkt,&n_rob](auto&& variant) {
        using T = std::decay_t<decltype(variant)>;
        if (std::is_same_v<T,Inz>) {
            ++n_inz;
        }
        else if (std::is_same_v<T,Mag>) {
            ++n_mag;
        }
        else if (std::is_same_v<T,Mkt>){
           ++n_mkt;
        }
        else if(std::is_same_v<T,Rob>){
          ++n_rob;
        }
        
   };

   for (size_t i = 0; i < n_prac; ++i) {
        std::visit(count_prac, prac[i]);
   }
   
   if(n_rob*Rob::CR < n_mag*Mag::CMag){
      if(n_mkt*Mkt::CMkt < n_rob*Rob::CR ){
       historiaprzych[tura] = ((Inz::CI * n_inz) *(n_mkt*Mkt::CMkt));
       return ((Inz::CI * n_inz) *(n_mkt*Mkt::CMkt));
      }
     else if(n_mkt*Mkt::CMkt > n_rob*Rob::CR){
       historiaprzych[tura] = ((Inz::CI * n_inz) *(n_rob*Rob::CR));
       return ((Inz::CI * n_inz) *(n_rob*Rob::CR));
     }
   }
   else if(n_rob*Rob::CR > n_mag*Mag::CMag){
      if(n_mkt*Mkt::CMkt < n_mag*Mag::CMag ){
       historiaprzych[tura] = ((Inz::CI * n_inz) *(n_mkt*Mkt::CMkt));
       return ((Inz::CI * n_inz) *(n_mkt*Mkt::CMkt));
      }
     else if(n_mkt*Mkt::CMkt > n_mag*Mag::CMag){
       historiaprzych[tura] = ((Inz::CI * n_inz) *(n_mag*Mag::CMag));
       return ((Inz::CI * n_inz) *(n_mag*Mag::CMag));
     }
   } 
   return 0;
}

double count_dlug(){
   double dlug = 0;
   for(int i=0; i < n_kredytow; i++){
       dlug = dlug + kredyty[i].get_dlug();
   }
   
   return dlug; 
}
int tura ;
private:
double stan_konta;
int n_kredytow;
int n_prac;
int N=3;


std::unique_ptr<Kredyt[]> kredyty = std::make_unique<Kredyt[ ]>(100);
//std::vector<Kredyt> kredyty;
std::unique_ptr<std::variant<Inz, Mkt, Mag, Rob>[]> prac = std::make_unique<std::variant<Inz, Mkt, Mag, Rob>[]>(100);
//std::vector<std::variant<Inz, Mkt, Mag, Rob>> prac;
std::unique_ptr<double[]> historiaprzych = std::make_unique<double[]>(100);
};