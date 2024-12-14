#include "main.h"
/*Il file conterrà le funzioni di inizializzazione delle variabili necessarie
allo svolgimento del processo*/

double random_in_range(double min, double MAX)
{
    return min + (rand()/(double)RAND_MAX)*(MAX - min);
}




void genera_paziente()
{
    //Glucose kinetics parameter :
    Gb = random_in_range(111.7, 161);
    Ib = random_in_range(30.8, 72.7);
    Vg = random_in_range(0.73, 1.33);
    k1 = random_in_range(0.053, 0.073);
    k2 = random_in_range(0.020,0.072);
    //Insuline Kinetics :
    Vi = random_in_range(0.039,0.062);
    m1 = random_in_range(0.245, 1.812);
    m2 = 0.268;
    m4 = random_in_range(0.299, 0.617);
    m5 =random_in_range(0.057, 0.420);
    m6 = random_in_range(0.011, 0.021);
    Heb;
    ag = random_in_range(0.003,0.008);
    a0g;
    //Rate of Glucose Appearance
    kabs = random_in_range(0.0293, 0.1);
    kmax = random_in_range(0.0318, 0.00869);
    kmin = random_in_range(0.0066,0.01);
    b = random_in_range(0.58, 0.83);
    d = random_in_range(0.06,0.14);
    f = 0.9;
    r1 = 0.7419;
    r2 = 0.0807;
    //Produzione endogena del Glucosio
    kp1;
    kp2 = random_in_range(0.0007, 0.0036);
    kp3 = random_in_range(0.0046, 0.0085);
    kp4 = random_in_range(0.333, 0.0656);
    ki = random_in_range(0.0056, 0.0101);
    //Glucose Utilization
    Fcns = 1;
    Vmx = random_in_range(0.020, 0.055);
    km0 = random_in_range(362.5, 511.1);
    P2u = random_in_range(0.025, 0.097);
    r1;
    r2;
    //Renal Excretion
    ke1 = 0.0005;
    ke2 = 339;
    //C-Peptide Kinetics 
    Vc;
    k01;
    k12;
    k21;
    //Cpeptide Secretion
    PHIs = random_in_range(12.51,28.03);
    PHId = random_in_range(148.6, 404.6);
    h = random_in_range(75.6, 133.2);
    //valori misti 
    SRb = (rand()%991)+540;
    EGPb = random_in_range(1.34, 1.96);
    //Valori Fisiologici base 
    età = (rand()%61) + 50;
    altezza = (rand()%175) + 163;
    peso  = (rand()%104)+83;
    BMI;
    BSA;
    Sex = (bool)rand() % 2;
    tempo_digiuno = digiuno(n_pasti);
    MaxGlucose = Max_glucose(Sex);
    n_pasti = (rand()%9)+2;
    tempo_digiuno = digiuno(n_pasti);
    Dose = (rand() %201) + 70; // restituisce un valore tra 70 e 200
    a0g = Heb * aG *Gb;
    p2U = random_in_range(0.025, 0.097);
}


int Max_glucose(bool Sex)
{
    int max_glucose = 0;
    if(Sex){
        max_glucose = 36;
    }else{
        max_glucose = 24;
    }
    
    return max_glucose;
}

int digiuno(int n_pasti)
{
    // il valore 7 per il numero di pasti rende tempo digiuno un douquindi potrebbe generare un proa di calcolo, in quanto ci si aspetta un int 
    int tempo_digiuno = (n_pasti == 7 ? 146 : (HORIZON - (n_pasti*60))/n_pasti);
    return tempo_digiuno;
}