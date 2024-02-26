#include <iostream>
using namespace std;
struct node{
    node* left;
    int dat;
    int pri;
    node* right;
};
node* insert(node* root,node* temp,int c){
    if (root == NULL) {
        root = temp;
    } 
    else {
        if ((root)->left == NULL) {
            insert(((root)->left), temp,c);
        } else if ((root)->right == NULL) {
            insert(((root)->right), temp,c);
        } else {
            // If left and right subtrees are already filled, 
            // insert into the left subtree to maintain completeness
                for(int i=0;i<c;i++){
                    insert(((root)->left), temp,c);
                    insert(((root)->right), temp,c);
                }
                return temp;
        }
    }
    return temp;
}
node* correct(node* root,node* temp){

}
node* push(node* root){
    cout<<"enter the new data"<<endl;
    int dat;
    cin>>dat;
    cout<<"enter the priority"<<endl;
    int pri;
    cin>>pri;
    node* temp=new node;
    temp->dat=dat;
    temp->pri=pri;
    temp->left=NULL;
    temp->right=NULL;
    int c=0;
    node* t1=root;
    while(t1->left!=NULL){
       c++;t1=t1->left;
    }
    node* t2=root;

    
    temp=insert(root,temp,c);
    correct(root,temp);
    return root;
}

int main(){
    node* root=NULL;
    while(true){
        cout<<"pick a choice: "<<endl;
        cout<<"1. push"<<endl;
        cout<<"2. pop"<<endl;
        cout<<"3. display"<<endl;
        cout<<"4. exit"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                push(root);

    }    
}
}