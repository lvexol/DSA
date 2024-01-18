#include <string>
#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cout<<"Enter the input equation"<<endl;
    cin>>input;
    int n=input.length();
    for (int i = 0; i < n / 2; i++)
        swap(input[i], input[n - i - 1]);
    stack<string> one;
    string resul="";
    for(int i=0;i<n;i++){
        char z=input[i];
        if(z=='*'||z=='/'||z=='+'||z=='-'||z=='('||z==')'||z=='^'){
            string b;
            b=one.top();
            one.pop();
            string c;
            c='('+b+z+one.top()+')';
            one.pop();
            one.push(c);
        }
        else{
            string a;
            a=z;
            one.push(a);
        }
    }
    resul=one.top();
    cout<<resul<<endl;
}