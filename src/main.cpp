#include "PrintHello.hpp"
#include "Gra.hpp"

int main()
{
    Gra G1; 

    while(1){
        
        while(1){
         G1.akcja_gracza();
         if(G1.get_stan() == 0){
            std::cout<< "Koniec tury" << std::endl;
            break;
         }
        }
        std::cout<< "Sprawdzam stan firmy" << std::endl;
        if(G1.get_stanf() == 2){
            std::cout<< "Gratulacje , wygrałeś" <<std::endl;
            break;
        }
        else if (G1.get_stanf() == 0){
            std::cout<< "Gratulacje, przegrałeś" << std::endl;
            break;
        }
        else if(G1.get_stanf() == 1){
            G1.tick();
        }
     
    }

    return 0;
}
