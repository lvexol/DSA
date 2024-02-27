#include <string>
#include <iostream>
#include <stack>

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
                    if(each.empty()){
                        each.push(z);
                        break;
                    }
                    else if(indux(z)==indux(each.top())){
                        if(indux(z)==3){
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
    
        cout<<resl<<endl;
}