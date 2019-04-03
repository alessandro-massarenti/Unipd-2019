#include<iostream>
using namespace std;

//PRE=(A contiene una sequenza di interi che termina con -2 e che consiste di una serie
//(possibilmente vuota) di sottosequenze che terminano con -1, inoltre n >=0)
int S(int *A, int n){
    int count = 0;
    for(int i = 0; A[i] != -2;i++){
        if( count >= n){
            return i;
        }
        if (A[i] == -1){
            count ++;
        }
    }
}
//POST=(se A contiene la sottosequenza n ed essa inizia in A[i], allora S restituisce i,
//altrimenti S restituisce -2)

int main() {
    int X[400];
    cin >> X[0];
    for (int i = 1; i < 400 && X[i - 1] != -2; i++)
        cin >> X[i];

    int n;
    cin >> n;
    cout << "start" << endl;
    int b=S(X,n);
    
    if(b==-2)
    cout << "sottosequenza " << n << " non presente" << endl;
    else
    cout << "inizio sottosequenza " << n << " indice=" << b << endl;
    cout << "end" << endl;
}
