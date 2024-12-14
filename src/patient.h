#ifndef patient_h
#define patient_h

int max_glucose;
void starting();
void calc_ODE();
/* ??????? In teoria dovrebbero modellare il paziente e i suoi valori  in particolare
tutti i valori presenti e calcolati qui, al variare del tempo presentano una nuova configurazione 
*/
void glucose_kinetics(int t);
void insuline_kinetics(int t);
void Glucose_appearance(int t, int is_eating);
void C_peptide_kinetics(int t);
double Kempt(double Qsto);
double ISR(int t);
double m3(int t);
void eating(bool is_eating);
double He(int t);
double ag0();
double EGP(int t);
double U_ii(int t);
double U_id(int t);
double E(int t);
double X_(int t);
double risk();
double func(double G);
#endif