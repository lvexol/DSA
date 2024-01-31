#include <iostream>
#include <cmath>

using namespace std;

void Entry(char tree[],int size){
    
}
int main(){
    int lvl;
    cout<<"Enter the level present in the tree: "<<endl;
    cin>>lvl;
    int number=pow(lvl,2.0);
    char tree[number]];
    cout<<"Enter the root element of the tree: "<<endl;
    cin>>tree[0];
    while(true){
        cout<<"Enter your option\n1.Enter element\n2.Exit\n"<<endl;int i;
        cin>>i;
        switch(i){
            case 1:
                Entry(tree,number);break;
            case 2:
                break;
        }
    }
}