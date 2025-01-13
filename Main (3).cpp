#include<iostream>
#include<limits>
using namespace std;
struct node{
    int data;
    node* next;
};
struct Header{
    int count;
    int maxval;
    int minval;
    node* head;
};
void initHeader(Header& header){
    header.count = 0;
    header.maxval = numeric_limits<int>::min();
    header.minval = numeric_limits<int>::max();
    header.head = NULL;
    
}
void insertnode(Header&header,int value){
    node* newnode=new node();
    newnode->data =  value;
    newnode->next = header.head;
    header.head = newnode;
    
    header.count++;
    if(value>header.maxval){
        header.maxval = value;
    }
    if (value < header.minval){
        header.minval = value;
    }
}
void InsertAtEnd(Header& header,int value){
    node* newnode = new node();
    newnode->data=value;
    newnode->next=NULL;
    node* temp=header.head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=newnode;
    
    header.count++;
    if(value>header.maxval){
        header.maxval = value;
    }
    if (value < header.minval){
        header.minval = value;
    }
    
}
void print(const Header& header){
    if(header.head == NULL){
        cout<<"This list is empty."<<endl;
        return;
        
    }
    cout<< "List the elements: ";
    node* temp = header.head;
    while(temp!=NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    
    }
    cout<< endl;
    cout<<"count of elements: "<<header.count<<endl;
    cout<<"maximun value: "<<header.maxval <<endl;
    cout<<"minimum value: "<<header.minval <<endl;
    
}
int main(){
    Header header;
    initHeader(header);
    insertnode(header,10);
    
    print(header);
}
