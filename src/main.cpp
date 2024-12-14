#include "main.h"

int main()
{
    //inizializzazioni varie 
    int tempo = 0;
    int campionamento = 5; // ogni quanti minuti viene effettuata la misurazione e l'eventuale iniezione da parte della pompoa di insulina 
    starting();
    
    while (tempo < HORIZON)
    {
        calc_ODE();
        //operazioni di routine, che prescindono da tutto

        //salviamo delle informazioni ottenute dall'ambiente 
                //aggiornamento dei valori del paziente 

        if(tempo % campionamento == 0){
            //ottieni info da paziente 
            //operazioni di routine della pompa
                //se necessario iniezione di insulina 
            
        }
        //Fase finale delle operazioni di routine se ci sono 

        tempo++;//Scorriamo il tempo di un passo 

    }

}