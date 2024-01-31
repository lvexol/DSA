#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* left_child;
    struct node* right_child;
};
void print_tree(struct node* root){
    int position;
    int count=0;
    struct node* temp=NULL;
    temp=new node;
    temp=root;
    while(temp->left_child!=NULL){
        count++;
        temp=temp->left_child;
    }
    temp=root;
    struct node* right=NULL;w
    right=root->right_child;
    struct node* left=NULL;
    left=root->left_child;
    for(int i=0; i<count; i++)
        cout<<" "<<endl;
    cout<<root->data<<endl;count--;
    while(right->right_child!=NULL&&left->left_child!=NULL){
        if(left->left_child==NULL&&right->left_child!=NULL)
            left=right->left_child;
        if(right->right_child==NULL&&left->right_child!=NULL)
            right=left->right_child;
        for(int i=0;i<count;i++)
            cout<<" "<<endl;
        count--;

    }
}
void insert_leaf(int data,struct node* root){
    cout<<"Pick and enter the position to be inserte the data: "<<endl;
    print_tree(root);

}
