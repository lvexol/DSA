#include <string>
#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int indux(char value) {
    if(value=='^'){
        return 3;
    }
    if(value=='*'||value=='/'){
        return 2;
    }
    if(value=='+'||value=='-'){
        return 1;
    }
}


int main(){
    string full;
    cin>>full;
    stack<char> each;
    string resl="result: ";
    int n = full.length();

    for (int i = 0; i < n / 2; i++)
        swap(full[i], full[n - i - 1]);
    for( int i=0;i<n;i++){
        if(full[i]=='(')
            full[i]=')';
        else if(full[i]==')')
            full[i]='(';
    }

    cout<<full<<endl;
    for (int i=0;i<full.length();i++){
        char z= full[i];
        bool bracket;
        if(z=='*'||z=='/'||z=='+'||z=='-'||z=='('||z==')'||z=='^'){
            if(z=='('){
                bracket=true;
            }
            if(z==')'){
                bracket=false;
            }
            if(each.empty()||bracket){
                each.push(z);
            }
            else{
                while(1>0){
                    if(indux(z)==indux(each.top())){
                        if(indux(z)!=3){
                            each.push(z);
                            break;
                        }
                        else{
                            resl+=each.top();
                            each.pop();
                            each.push(z);
                            break;
                        }
                    }
                    else if(indux(z)>indux(each.top())){
                        each.push(z);
                        break;
                    }
                    else if(each.empty()){
                        each.push(z);
                        break;
                    }
                    else{
                        resl+=each.top();
                        each.pop();
                    } 
            }  
            }
            if(each.top()==')'){
                while(!(each.top()=='(')){
                    resl+=each.top();
                    each.pop();
                }
            }
        }
        else{
            resl+=z;
        }
    }
    while(!each.empty()){
        resl+=each.top();
        each.pop();
    }
    n=resl.length();
    for (int i = 0; i < n / 2; i++)
        swap(resl[i], resl[n - i - 1]);
    
        cout<<resl<<endl;
}