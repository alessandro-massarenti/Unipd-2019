#include<iostream>
using namespace std;

// PRE : h e' un numero reale corrispondente alle ore
int htos(int h){
    int s = h*3600;
    return s;
}
// POST : la funzione riporta i secondi che servono per formare le ore ricevute in ingresso

// PRE : m e' un numero reale corrispondente ai minuti
int mtos(int m){
    int s = m*60;
    return s;
}
// POST : la funzione riporta i secondi che servono per formare i minuti ricevuti in ingresso

// PRE : h, m, s corrispondono ad un tempo in ore, minuti e secondi. h,m,s sono numeri reali.
// R : Vengono inseriti nel programma separatamente ed in ordine.
int timeInS(){
    int h,m,s;
    cin >> h;
    cin >> m;
    cin >> s;
    return (s + htos(h) + mtos(m));
}
// POST : la funzione riporta in output in secondi il tempo inserito all' interno della funzione se l' input rispetta i canoni della pre condizione.

int main() {
    
    bool ok = true;
    int n_partecipanti = 0, partenza = 0;
    int sensore = 0, corridore = 0, tempo=0;
    int status[3][100];
    
    cin >> n_partecipanti;
    partenza = timeInS();
    cout << "start" << endl;
    

// PRE : i e' compreso tra 0 e 2, j e' compreso tra 0 e 100,status e' un array bi-dimensionale.
    for(int i = 0; i<2; i++){
        for(int j = 0; j<100; j++ ){
            if(i==0){
                status[i][j] = 0;
            }
            /*
            else if(i==1){
                status[i][j] = partenza;
            }
            */
            else if(i==2){
                status[i][j] = 0;
            }
        }
    }
// POST : lo strato 0 e lo strato 2 dello' array a tre dimensioni "status" vengono riempiti con il valore "0".
    
    // status[i][0]
    // i => 0 = sensore
    // i => 1 = tempo
    // i => 2 = errore
    // status[0][j]

// PRE : sensore e' un numero intero e diverso da -1
    while(sensore != -1){
        cin >> sensore;
        if (sensore != -1){
            cin >> corridore;
            tempo = timeInS();
            
            if(status[0][corridore] < sensore-1){
                status[2][corridore] = 1;
                ok=false;
            }else{
                status[0][corridore] = sensore;
                if(sensore == 0){
                    status[1][corridore] = tempo;
                }else if(sensore == 1){
                    if(tempo-1815 < status[1][corridore]){
                        status[2][corridore] = 2;
                        ok=false;
                    }else{
                        status[1][corridore] = tempo;
                    }
                }else if(sensore == 2){
                    if(tempo-1811 < status[1][corridore]){
                        status[2][corridore] = 2;
                        ok=false;
                    }else{
                        status[1][corridore] = tempo;
                    }
                }
            }
        }
    }
// R : l' array viene riempito con i dati catturati in input
// POST : l' array contiene i dati relativi alla tipologia di sgarro del corridore nello strato "2" relazionato alla matricola del corridore
    
// PRE : i e' compreso tra 0 ed il numero di partecipanti alla gara
    for(int i = 0; i< n_partecipanti; i++){
        if(status[2][i] == 1){
             cout << i << ": salto sensore" << endl;
        }else if(status[2][i] == 2){
            cout << i << ": tempo sospetto" << endl;
        }
    }
// POST : a seconda del tipo di sgarro del corridore viene stampato il relativo messaggio di errore in ordine di matricola del corridore
   
    if(ok){
        cout << "gara regolare" << endl;
    }

    cout << "end" << endl;
}
