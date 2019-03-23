#include<iostream>

using namespace std;

int colonna(int X[], int n, int step); //da fare

int colonna(int *A, int n, int step) {
    int sum = 0;
    for (int j = 0; j < step; j++) {
        sum = sum + *(A + n + (8 * j));
    }
    return sum;
}

//PRE=(cin contiene n_ele, 0<n_ele<=400, seguito da n_ele interi qualsiasi)
int main() {
    int A[10][5][8], *p = A[0][0];
    int n_ele;
    cin >> n_ele;
    for (int i = 0; i < n_ele; i = i + 1)
        cin >> p[i];

    int bestfetta, bestvalue;
    int numero_righe, ultima_riga;

    int step = 0;
    bool prima = true;
    cout << "start" << endl;

    numero_righe = n_ele / 8;
    ultima_riga = n_ele % 8;

    for (int i = 0; i < 8; i++) {
        if (ultima_riga > 0) {
            step = numero_righe + 1;
            ultima_riga--;
        } else {
            step = numero_righe;
        }
        if (colonna(p, i, step) >= bestvalue or prima == true) {
            bestvalue = colonna(p, i, step);
            bestfetta = i;
            prima = false;
        }
    }

    cout << "V-fetta massima= " << bestfetta << " con somma= " << bestvalue << endl;
    cout << "end" << endl;
}
//POST=(stampa l'indice della V-fetta a somma massima seguito dalla sua somma e in caso di parità, stampa l'indice massimo)
