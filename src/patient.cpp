#include "main.h"

double glucose_level = 0;
double Gp = 0.0;
double Gt = 0.0;
double Cpb = 200;
double Gth = 50;
double Gpb;
double ke1;
double ke2;
double gtb;
double Vm0;
int Fsnc;
double Ipb;
double m2;
double m30;
double Ilb;
double Ievb;
/*Stato 0*/
double Qsto = 0;
double Qsto1 = 0;
double Qsto2 = 0;
double Qgut = 0;
double XL = Ib;
double Iprimo = Ib;
double kp1 = 0;
double X = 0;
double Cp1 = Cpb;
double Cp2 = (k21/k12)*Cpb;
/*Valori fondamentali delle equazioni*/
double G; // Glucosio totale 
double I; // Insulina totale 
double Rameal;// rate apparizione glucosio pasto
double ISRs = 0;
/*Variabili calcolate una volta */

double alpha  = 5 / (2*Dose*(1-b));
double Beta = 5 / (2*Dose*d);
//Starting manca di una parte finale.
void starting()
{
    Gpb = Gb * Vg;
    ke1 = 0.0005;
    ke2 = 339;
    double gtb;
    double Vm0;
    int Fsnc = 1;
    double Ipb = Ib*Vi;
    Heb = (SRb -m4 *Ipb) / (SRb+m2*Ipb);
    double m2 = 0.268;
    double m30 = (Heb * m1)/(1-Heb);
    double Ilb = (Ipb*m2+SRb)/(m1+m30);
    double Ievb=Ipb*m5/m6;
    if (Gpb <= ke2){
        gtb =(Fsnc - EGPb + (k1*Gpb))/k2;
        Vm0 =(EGPb - Fsnc) * (km0 +gtb)/gtb;
    }else{
        gtb = ((Fsnc-EGPb+ke1*(Gpb -ke2))/Vg+k1*Gpb)/k2;
        Vm0 =(EGPb-Fsnc-ke1*(Gpb-ke2))*(km0+gtb)/gtb;
    }
    kp1 = EGPb+kp2*Gpb+kp3*Ib+kp4* Ilb;
    //Funzioni di Di Van cauter per la valutazione dei BMI e delle relative funzioni 
}

void eating(bool is_eating)
{
    /*Se sta mangiando non deve essere espressa la versione che calcola RaMeal ? probabilmente no */
    if (is_eating){
        glucose_level += Dose;
        //total_glucose_assumption += Dose/1000;
    }
}



//Funzioni principali che calcolano a tutti gli effetti i valori necessari per il processamento delle DTS 


/*Glucose kinetics si occupa di valutare la cinetica del glucosio nel sistema, si avvale*/
void glucose_kinetics(int t)
{
    double dGp = (EGP(t)) + Rameal - U_ii(t) - E(t) - k1 * Gp + k2 * Gt;
    double dGt = -U_id(t) + k1 * Gp -k2 * Gt;
    Gp += dGp; 
    Gt += dGt;
    G = Gp / Vg;
}

void insuline_kinetics(int t)
{
    double I_lp = -(m1 + m3(t))*Ilb + m2*Ipb + ISR(t)/peso;
    double I_p = -(m2 + m4 + m5)*Ipb + m1*Ilb + m6*Ievb;
    double Iev_p = -m6*Ievb + m5*Ipb;
    Ilb +=I_lp;
    Ipb += I_p;
    Ievb += Iev_p;
    I = I_p / Vi;
}

void Glucose_appearance(int t, int is_eating)
{
    double Qsto1p = -(kmax* Qsto1) + (Dose)* is_eating;
    double Qsto2p = -Kempt(Qsto)* Qsto2 + kmax*Qsto1;
    double Qgutp = -kabs*Qgut + Kempt(Qsto)*Qsto2;
    Rameal = 0.9*kabs*Qgutp;
    Qsto1 += Qsto1p;
    Qsto2 += Qsto2p;
    Qgut += Qgutp;
    Qsto += Qsto1 + Qsto2;
}

void C_peptide_kinetics(int t)
{
    double CP1p = -(k01 + k21)*Cpb + k12*Cp2 + ISR(t);
    double CP2p = -k12*Cp2 + k21*Cp1;

    Cp1 = CP1p;
    Cp2 = CP2p;
}

//Funzioni intermedie 




double Kempt(double Qsto)
{
  return  kmin + ((kmax - kmin)/2) * (tanh(alpha*(Qsto -(Beta * Dose))) -tanh(Beta * (Qsto - d * Dose))+2);
}

double ISR(int t)//Controllare il senso delle variabili presenti nel blocco 
{
    double ISRsp = -alpha * (ISRs -Vc + PHIs*(G - h));
    double ISRd = (G >= 0 ? Vc * PHId * G : 0);
    double ISRb = Cpb *k01*Vc;
    
    return ISRs + ISRd + ISRb;
}

double m3(int t)
{ 
    return (He(t)*m1) / 1 - He(t);
}

double He(int t)
{
   return -aG * G + ag0();
}

double ag0()
{
    return Heb + aG *Gb;
}

double EGP(int t)//Controllare il senso delle variabili presenti nel blocco 
{
    double XLp = -ki * (XL - Iprimo);
    double Iprimop = -ki * (Iprimo - I);
    
    XL = XLp;
    Iprimo = Iprimop;
    
    return kp1 - kp2*Gp - kp3*XL - kp4*Ilb;
}

double U_ii(int t)
{
    return Fsnc;
}

double U_id(int t)
{
   return  (Vm0 + Vmx * X_(t) * (1 + r1 * risk()) * Gt)/km0+Gt;
}

double E(int t)
{
    double E_t = 0;
    if(Gp>ke2)
    {
        E_t = ke1 * Gp - ke2;
    }else{
        E_t = 0;
    }
    return E_t;
}

double X_(int t)
{
    double Xp = -p2U * X + p2U*(I - Ib);
    X = Xp;
    return X;
}

double risk()
{
    double rischio;
    if(G >= Gb)
    {
        rischio = 0;
    }else if (Gth<= G && G <= G)
    {
        rischio = 10 * pow(func(G), 2);
    }else if (G<=Gth)
    {
        rischio = 10 * pow(func(Gt), 2);
    }
    return rischio;
}

double func(double G)
{
    return pow(log(G), r2) - pow(log(Gb), r2);
}

void calc_ODE()
{


}




