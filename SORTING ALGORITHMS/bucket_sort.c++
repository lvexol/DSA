#include <iostream>
#include <vector>
using namespace std;

int bucket(double a[],int n){
    vector<double> b[n];
    for(int i=0;i<n;i++){
        int bi=n*i;
        b[bi].push_back(a[i]);
    }
    for(int i=0;i<n;i++){
        if(b[i].empty())
            break;
        int z=b[i].size();
        for(int j=0;j<z-1;j++){
            for(int k=j+1;k<z-1;k++){
                if(b[j][k]>b[j][k+1]){
                    swap(b[j][k],b[j][k+1]);
                }
            }
        }
    }
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<b[i].size();j++)
            a[index++]=b[i][j];   
}
}

void main(){
    int n;
    cout<<"enter the number of elements: ";
    cin>>n;
    double a[n];
    cout<<"enter the element "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    bucket(a,n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}