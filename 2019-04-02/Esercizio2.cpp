#include<iostream>
using namespace std;

int htos(int h){
    int s = h*3600;
    return s;
}

int mtos(int m){
    int s = m*60;
    return s;
}

int timeInS(){
    int h,m,s;
    cin >> h;
    cin >> m;
    cin >> s;
    return (s + htos(h) + mtos(m));
}


int main() {
    
    bool ok = true;
    int n_partecipanti = 0, partenza = 0;
    int sensore = 0, corridore = 0, tempo=0;
    int status[3][100];
    
    cin >> n_partecipanti;
    partenza = timeInS();
    cout << "start" << endl;
    
    for(int i = 0; i<2; i++){
        for(int j = 0; j<100; j++ ){
            if(i==0){
                status[i][j] = 0;
            }else if(i==1){
                status[i][j] = partenza;
            }else if(i==2){
                status[i][j] = 0;
            }
        }
    }
    
    while(sensore != -1){
        cin >> sensore >> corridore;
        tempo = timeInS();
        
        if(status[0][corridore] < sensore-1){
            status[2][corridore] = 1;
            ok=false;
        }else{
            status[0][corridore] = sensore;
            if(sensore == 1){
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
    
    for(int i = 0; i< n_partecipanti; i++){
        if(status[2][i] == 1){
             cout << i << ": salto sensore" << endl;
        }else if(status[2][i] == 2){
            cout << i << ": tempo sospetto" << endl;
        }
    }
   
    if(ok){
        cout << "gara regolare" << endl;
    }

    cout << "end" << endl;
}
