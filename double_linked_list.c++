#include <iostream>

using namespace std;

struct node{
    struct node* previous;
    int data;
    struct node* next;
};

struct node* insert_beginig(struct node* head,struct node* n1){
    
}
struct node* insertion(struct node* head){
    struct node* n1=NULL;
    n1=new node;
    cout<<"Enter the data to be inserted: ";
    int dat;
    cin>>dat;
    n1->data=dat;
    cout<<"Pick the postion \n1.begining\n2.ending\n3.middle";
    int pic;
    cin>>pic;
    switch(pic){
        case 1:
        insert_begining(head,n1);
        break;
        case 2:
        insert_ending(head,n1);
        break;
        case 3:
        insert_middle(head,n1);
        break;
    }
}