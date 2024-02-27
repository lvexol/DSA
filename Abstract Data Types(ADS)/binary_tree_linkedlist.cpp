#include<iostream>
using namespace std;
class node{
    public:
int data;
node*left;
node*right;
node(int dat){
    data=dat;
    left=NULL;
    right=NULL;
}
};
node* buildTree(node* root){
    cout<<"enter data:";
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    cout<<"enter data for inserting in left of " <<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node *root=NULL;
    root=buildTree(root);
    inorder(root);
    postorder(root);
    preorder(root);
}