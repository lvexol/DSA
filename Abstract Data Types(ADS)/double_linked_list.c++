#include <iostream>

using namespace std;

struct node{
    struct node* previous;
    int data;
    struct node* next;
};

struct node* insert_begining(struct node* head,struct node* n1){
    head->previous = n1;
    n1->next = head;
    head=n1;
    return head;
}

void insert_ending(struct node* temp,struct node* n1){
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=n1;
    n1->next=temp;
}
void insert_middle(struct node* nex,struct node* n1){
    int postion;
    cout<<"Enter the position to be inserted: ";
    cin>>postion;
    for(int i=0;i<postion;i++)
        nex=nex->next;
    n1->next=nex;
    nex=nex->previous;
    n1->previous=nex;
    nex->next=n1;
    nex=n1->next;
    nex->previous=n1;
}
struct node* insertion(struct node* head){
    struct node* n1=NULL;
    n1=new node;
    cout<<"Enter the data to be inserted: ";
    int dat;
    cin>>dat;
    n1->data=dat;
    n1->previous=NULL;
    n1->next=NULL;
    if(head==NULL){
        head=n1;
        return head;
    }
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