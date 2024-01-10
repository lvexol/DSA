#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

struct node* inbeg(node* head,node* n1){
    n1->next=head;
    head=n1;
    return head;
}

void inend(node* head,node* n1){
    struct node* temp=NULL;
    temp=new node;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n1;
}
void inmid(node* head,node* n1){
    struct node* temp=NULL;
    temp=new node;
    int pos;
    cout<<"enter the position to be inserted"<<endl;
    cin>>pos;
    temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    struct node* temp1=NULL;
    temp1=new node;
    temp1=temp->next;
    temp->next=n1;
    n1->next=temp1;
}

struct node* insertion(node* head,int da){
    struct node* n1=NULL;
    n1= new node;
    n1->data=da;
    n1->next=NULL;
    cout<<"enter the position\n 1.begining\n 2.ending\n 3.middle"<<endl;
    int a;
    cin>>a;
    switch(a){
        case 1:
        head=inbeg(head,n1);
        break;
        case 2:
        inend(head,n1);
        break;
        case 3:
        inmid(head,n1);
        break;
    }
    return head;
}
void print(struct node* head){
    struct node* temp=NULL;
    temp=new node;
    temp=head;
    while(temp->next!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<temp->data;
}

int main(){
    int siz;
    cout<<"enter the size";
    cin>>siz;
    int dat1;
    cout<<"enter the head data";
    cin>>dat1;
    struct node* head=NULL;
    head= new node;
    head->data=dat1;
    head->next=NULL;
    for(int i=0;i<siz;i++){
        int dat;
        cout<<"enter the data"<<endl;
        cin>>dat;
        insertion(head,dat);
    }
    print(head);

}