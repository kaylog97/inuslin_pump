#ifndef global_h
#define global_h


//Parametri 
extern double Vg;
extern double k1;
extern double k2;
extern double Vi;
extern double m1; 
extern double m2;
extern double m4;
extern double m5;
extern double m6;
extern double Heb;
extern double ag;
extern double a0g;
extern double kabs;
extern double kmax;
extern double kmin;
extern double b;
extern double d;
extern double f;
extern double kp1;
extern double kp2;
extern double kp3;
extern double kp4;
extern double ki;
extern double Fcns;
extern double Vmx;
extern double km0;
extern double P2u;
extern double r1;
extern double r2;
extern double ke1;
extern double ke2;
extern double Vc;
extern double k01;
extern double k12;
extern double k21;
extern double PHIs;
extern double PHId;
extern double h;
extern double Gb;
extern double Ib;
extern int SRb;
extern double EGPb;
extern double aG; 
extern double p2U;

//parametri fisiologici

extern bool Sex; //0=F / 1=M
extern int età;
extern int altezza;
extern int peso;
extern double BMI;
extern double BSA;

//Parametri derivabili
extern int MaxGlucose;
extern int n_pasti;
extern bool Sex;
extern int Dose;
extern int tempo_digiuno;



void genera_paziente(); // funzione che assegna al paziente tutti i valori di riferimento

#endif 