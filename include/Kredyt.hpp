#include <iostream>


class Kredyt{
public:
Kredyt():pozostale_raty{0},dlug{0.0}{

};
Kredyt(int czass, double kwotaa): pozostale_raty{czass}, dlug{kwotaa} {
  
}
double splac_rate(){
  if(pozostale_raty != 0){ 
   double rata;
   rata = dlug/pozostale_raty;
   dlug = dlug - rata;
   dlug = dlug + dlug*0.02;
   -- pozostale_raty;
   return  rata;
  }
  return 0;
}
double get_dlug(){
  return dlug;
}


private:
int pozostale_raty;
double dlug;


};

