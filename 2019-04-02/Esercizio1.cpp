#include<iostream>
using namespace std;

int rowCount(char x[]){
    int count = 0;
    for(int i = 0; x[i] != '\0'; i++){
        count ++;
    }
    return count;
}

// PRE = (P e' un pattern che termina con '\0' && S e' una sequenza di char che termina con '\0')
bool match(char* P, char* S){
    
    int count = 0;
    for(int i = 0; i<rowCount(P) && S[i] != '\0' ; i++ ){
        if (P[i] == *(S+i) || P[i] == '?'){
            count ++;
        }
    }
    if(count == rowCount(P)){
        return true;
    }else{
        return false;
    }
}
// POST = (la funzione ritorna true se e solo se P occorre in S a partire dalla posizione 0)

bool row(char* P, char* x,int r){
    bool trovato = false;
    for(int i = 0; x[i] != '\0';i++){
        if (P[0] == x[i] || P[0] == '?'){
            if(match(P,x+i) == true){
                
                trovato = true;
                cout << "riga: " << r << " ";
                cout << "colonna: " << i << endl ;
            }
        }
    }
    return trovato;
}
// POST = ( la funzione ritorna true e stampa riga e colonna se e solo se match risulta true)

// PRE = (cin contiene un pattern P, seguito un intero n_righe, seguito da un testo T lungo n_righe righe)
int main() {
    char P[100], T[100][100];
    int n_righe = 0;
    
    cin.getline(P, 100);
    cin >> n_righe;
    cin.ignore();       // ignora il carattere "a capo" dopo la lettura del numero di righe 
    for(int i = 0; i < n_righe; i++) {
        cin.getline(T[i],100);
    }
    cout << "start" << endl;
    
    char* x = &T[0][0];
   
    /*
    for(int i=0; i < n_righe; i++){
        cout << rowCount(x+100*i) << endl;
    }
    */
    
    bool trovato = false;
    
    for(int i = 0; i< n_righe; i++){
        bool riga = row(P,x+(100*i),i);
        if(!trovato){
            trovato = riga;
        }
    }
    
    if(!trovato){
       cout << "Pattern non trovato" << endl; 
    }
    
    cout << "end" << endl;
}
// POST = (stampa "riga: i colonna: j" per ogni occorrenza i,j di P in T, 
//   
