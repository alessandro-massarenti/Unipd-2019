#include <iostream>
using namespace std;

int main(){
    
    cout << "start" << endl;
    
    int A[3][4][5];
    int n;
    char l;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<5;k++){
                cin >> A[i][j][k];
            }
        }
    }
    
    cin >> l;
    cin >> n;
    
    if(l=='H'){
        for(int i=0;i<3;i++){
            for(int j=0;j<5;j++){
                cout << A[i][n][j] << " ";
            }
            cout << endl;
        }
    }else if(l=='V'){
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                cout << A[i][j][n] << " ";
            }
            cout << endl;
        }
    }
    
    cout << "end";
    
}
