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
struct node* del_beging (struct node* head){
    struct node* temp=NULL;
    temp=new node;
    temp=head;
    head=head->next;
    free(temp);
    return head;
}
void del_ending(struct node* head){
    struct node* temp=NULL;
    temp=new node;
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    struct node* prev=NULL;
    prev=new node;
    prev=head;
    while(prev->next=temp)
        prev=prev->next;
    prev->next=NULL;
    free(temp);
}
void del_middle(struct node* head){
    int n;
    cout<<"enter the place to be deleted";
    cin>>n;
    struct node* temp=NULL;
    temp=new node;
    temp=head;
    for(int i=0;i<n;i++)
        temp=temp->next;
    struct node* prev=NULL;
    prev=new node;
    prev=head;
    while(prev->next != temp)
        prev=prev->next;
    prev->next=temp->next;
    free(temp);
}
void del_value(struct node* head){
    int val;
    cout<<"enter the value to be deleted";
    cin>>val;
    struct node* prev=NULL;
    prev=new node;
    prev=head;
    while(head->next != val)
        head=head->next;
    while(prev->next!=head) 
        prev=prev->next;
    prev->next=head->next;
    free(head);
}
struct node* deletion(node* head){
    while(true){
    cout<<"select the postion to be deleted\n 1.begining\n 2.ending\n 3.middle\n 4.value based\n 5.exit"<<endl;
    int type;
    cin>>type;
    switch(type){
        case 1:
        head=del_beging(head);
        break;
        case 2:
        del_ending(head);
        break;
        case 3:
        del_middle(head);
        break;
        case 4:
        del_value(head);
        break;
        case 5:
        return head;
        break;
    }
    }
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
    int val;
    
    while(true){
        cout<<"enter the process to be dont"<<endl;
        cout<<"1.insert the data\n2.delet element\n3.print data\n4.exit"<<endl;
        cin>>val;
        switch(val){
            case 1:
            int dat;
            cout<<"enter the data"<<endl;
            cin>>dat;
            head=insertion(head,dat);
            break;
            case 2:
            deletion(head);
            break;
            case 3:
            print(head);
            break;
            case 4:
            return 0;
            break;
        }
    }

}