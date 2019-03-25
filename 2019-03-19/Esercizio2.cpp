#include<iostream>
using namespace std;

int main(){

	int n_ele, lim1,lim2, lim3, X[400];
	cin>>n_ele;
	for(int i=0; i<n_ele; i=i+1)
	   cin>>X[i];
	cin>>lim1>>lim2>>lim3;

	cout<<"start"<<endl;

	int * p=X;

    int count = 0;
    
    
    for(int i = 0; i< lim1 && count<n_ele ; i++){
        cout << "\nstrato" << i << endl;
        for(int j = 0; j< lim2 && count<n_ele ; j++){
            cout << "r" << j << ":";
            for(int k = 0; k< lim3 && count<n_ele; k++){
                cout << p[count] << " ";
                count ++;
            }
            cout << endl;
        }
    }
	cout<<"end"<<endl;
}
