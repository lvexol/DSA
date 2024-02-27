#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the array"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int temp=arr[0];
    for(int i=1; i<n; i++){
        if(temp<arr[i]){
            temp=arr[i];
        }
    }
    int c=0;
    while(temp>0){
        temp=temp/10;
        c++;
    }
    int a,b;
    cout<<endl;
    for(int i=1; i<c+1; i++){
        //buble sort is used here
        for(int j=0; j<n; j++){
            for(int k=0; k<n-1; k++){
                a=(arr[k]%int(pow(10,i)))/(int(pow(10,i-1)));
                b=(arr[k+1]%int(pow(10,i)))/(int(pow(10,i-1)));
                if(a>b){
                    temp=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=temp;
                }
            }
        }

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

}