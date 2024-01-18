#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main(){
    string input;
    cout<<"Enter the input equation"<<endl;
    cin>>input;
    
    stack<string> one;
    string resul="";
    for(int i=0;i<input.length();i++){
        char z=input[i];
        if(z=='*'||z=='/'||z=='+'||z=='-'||z=='('||z==')'||z=='^'){
            string b;
            b=one.top();
            one.pop();
            string c;
            c='('+one.top()+z+b+')';
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