#include <iostream>
using namespace std;
int main(){
    
    int C[2][4][5];
    bool B[2][4][5];
    int n, c=0;
    
    cout << "start" << endl;
    cin >> n;
    
        for(int k = 0; k<4; k++){
            for(int j = 0; j<2; j++){
                for(int i = 0; i<5; i++){
                    B[j][k][i] = false;
                }
            }
        }
    
        for(int k = 0; k<4  && c<n; k++){
            for(int j = 0; j<2  && c<n; j++){
                for(int i = 0; i<5  && c<n ; i++){
                    cin >> C[j][k][i];
                    B[j][k][i] = true;
                    c++;
                }
            }
        }
        c=0;
        
        for(int j = 0; j<2  && c<n; j++){
            for(int k = 0; k<4  && c<n; k++){
                for(int i = 0; i<5  && c<n; i++){
                    if(B[j][k][i] == true){
                        cout << C[j][k][i] << " ";
                        c++;
                    }
                }
                cout << endl;
            }
        }
    cout << "end";
}
