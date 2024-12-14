#include "pump.h"

double insulina_totale = 0;
double Zucchero;
double calcola_insulina(double glucosio)
{
    Zucchero = glucosio;
    
    if(glucosio < 100 )
    {
        return insulina  = 1.0;
        if (glucosio <75)
        {
           return insulina = 2.0;
        }
    }else{
        return 0.0;
    }
}

double inietta_insulina(double glucosio)
{
    double insulina_da_iniettare = calcola_insulina(glucosio);
    insulina_totale += insulina_da_iniettare;
    return insulina_da_iniettare;
}
