#include "environment.h"

bool square(int Lunch_time, int Fasting_duration, int t)
{
    bool is_eating = false;
    if( 0<(t %(Lunch_time + Fasting_duration))< Lunch_time){
        is_eating = true;
    }else{
        is_eating = false;
    }
    return false;
}