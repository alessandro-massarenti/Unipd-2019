#include<iostream>
using namespace std;

int stampaS(int *p, int dim3, int dim2, int i,int  count, int elementi){
    cout << "\nstrato" << i << endl;
    for(int j = 0; j< dim2 && count<elementi ; j++){
        cout << "r" << j << ":";
        for(int k = 0; k< dim3 && count<elementi; k++){
            cout <<  p[(j*dim3)+(dim2*dim3*i)+k] << " ";
            count ++;
        }
    }
    cout << endl;
    return count;    
}

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
        count = stampaS(p,lim3,lim2,i,count, n_ele);
    }
	cout<<"end"<<endl;
}
