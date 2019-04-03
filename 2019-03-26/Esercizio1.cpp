#include<iostream>
using namespace std;

int& TV(int* x,int dim3, int a, int b) {
    return *(x +(dim3 * b) + a);
}

void stampa(int x[], int dim1, int dim2, int dim3) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                cout << *(x + (i * dim2 * dim3) + (j * dim3) + k) << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int x[100];
    for(int i=0; i<100; i++)
        cin >> x[i];
    int lim1, lim2, lim3;
    cin >> lim1 >> lim2 >> lim3;

    int a,b,c,d;
    bool going = true;

    int* p = x;
    cout << "start" << endl;
    while(going == true){
        cin >> a;
        if(a != -1){
            cin >> b >> c >> d;
            int & axy = TV(p,lim3,a,b);
            int & axx = TV(p,lim3,c,d);
            int temp = axy;
            axy = axx;
            axx = temp;
        }else{
            going = false;
        }
    }

    // ciclo che invoca TV da fare
    stampa(x, lim1, lim2, lim3); // stampa Y[lim1][lim2][lim3] per strati
    cout << "end";
}
