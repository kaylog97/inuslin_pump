#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <cassert>
#include <cerrno>

#include "global.h"
#include "patient.h"
#include "init.h"

#define HORIZON 1440 // Minuti in una giornata.

#define myrandom() (((double) rand())/((double) RAND_MAX))
//#define random_in_range()

//Spazio dedicato alla dichiarazioni delle funzioni contenute nel codice intero 


using namespace std;


#endif