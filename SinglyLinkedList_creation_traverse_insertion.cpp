#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* next;
};
node* head = NULL;
int no_of_elements = 0;
void traverse()
{
    no_of_elements = 0;
    cout<<"The elements in the list are :"<<endl;
    node* tmp;
    tmp = head;
    while(tmp!=NULL)
    {
        no_of_elements++;
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
    cout<<"No of Elements in the list is = "<<no_of_elements<<endl;
}
void creation()
{

    int add=1,a;
    node* tmp;
    while(1)
    {

        cout<<"Enter the element:"<<endl;
        cin>>a;
        node* newNode = new node;
        newNode->data=a;
        newNode->next = NULL;
        if(head==NULL)
        {
            head=newNode;
            tmp = newNode;
        }
        else
        {
            tmp->next=newNode;
            tmp = newNode;
        }
        cout<<"***Type 1 to add elements otherwise type 0***"<<endl;
        cin>>add;
        if(add!=1)
        {
            cout<<"list is ended"<<endl;
            break;
        }
    }
    traverse();
}
void insert_at_begin()
{
    int a;
    cout<<"Enter the element:"<<endl;
    cin>>a;
    node* newNode = new node;
    newNode->data=a;
    newNode->next = head;
    head = newNode;
    traverse();
}
void insert_at_end()
{
    int a;
    cout<<"Enter the element:"<<endl;
    cin>>a;
    node* newNode = new node;
    newNode->data=a;
    newNode->next = NULL;
    node* tmp;
    tmp = head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next = newNode;
    traverse();
}
void insert_after()
{
    int a,pos,i=0;
    cout<<"Enter Position: "<<endl;
    cin>>pos;
    if(pos> no_of_elements-1)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    else if(pos==no_of_elements-1){
        insert_at_end();
        return;
    }
    cout<<"Enter the element:"<<endl;
    cin>>a;
    node* newNode = new node;
    newNode->data=a;
    newNode->next = NULL;
    node* tmp;
    tmp = head;
    node* prev;
    if(pos==0)
    {
        newNode->next=head->next;
        head->next=newNode;
        traverse();
        return;
    }
        while(i!=pos)
        {
            tmp=tmp->next;
            prev  =tmp;
            i++;
        }
        newNode->next=tmp->next;
        tmp = newNode;
        prev->next = tmp;
    traverse();

}
void insert_before()
{
     int pos;
    cout<<"Enter Position: "<<endl;
    cin>>pos;
    if(pos==0){
        insert_at_begin();
        return;
    }
    int a,i=0;
    cout<<"Enter the element:"<<endl;
    cin>>a;
    node* newNode = new node;
    newNode->data=a;
    newNode->next = NULL;
    node* tmp;
    tmp = head;
    node* prev,*cp;
    if(pos> no_of_elements-1)
    {
        cout<<"Invalid Position"<<endl;
    }
    else if(pos==1)
    {
        newNode->next=head->next;
        head->next=newNode;
    }
    else
    {
        while(i!=pos-1)
        {
           tmp=tmp->next;
            prev  =tmp;
            i++;
        }
       newNode->next=tmp->next;
        tmp = newNode;
        prev->next = tmp;

    }
    traverse();
}
void insert_at()
{
    int pos;
    cout<<"Enter Position: "<<endl;
    cin>>pos;
    if(pos==0){
        insert_at_begin();
        return;
    }
    else if(pos==no_of_elements)
    {
        insert_at_end();
        return;
    }
    int a,i=0;
    cout<<"Enter the element:"<<endl;
    cin>>a;
    node* newNode = new node;
    newNode->data=a;
    newNode->next = NULL;
    node* tmp;
    tmp = head;
    node* prev;
    if(pos> no_of_elements-1)
    {
        cout<<"Invalid Position"<<endl;
    }
    else if(pos==1)
    {
        newNode->next=head->next;
        head->next=newNode;
    }
    else
    {
        while(i!=pos)
        {
             prev  =tmp;
            tmp=tmp->next;
            i++;
        }
        newNode->next=tmp;
        tmp = newNode;
        prev->next = newNode;
    }
    traverse();
}
int main()
{
    int d;
    while(1){
    cout<<"Break = 0,creation = 1,Traverse=2,Insert at Begin=3,Insert at End=4,Insert before=5,Insert at=6,Insert after=7"<<endl;
    cin>>d;
    if(d==1){
    cout<<"***Creation***"<<endl;
    creation();
    }
    else if(d==2){
    cout<<"***Traverse***"<<endl;
    traverse();
    }
    else if(d==3){
    cout<<"***Insert at Begin***"<<endl;
    insert_at_begin();
    }
    else if(d==4)
    {
    cout<<"***Insert at End***"<<endl;
    insert_at_end();
    }
    else if(d==5){
    cout<<"***Insert before given Position***"<<endl;
    insert_before();
    }
    else if(d==6){
    cout<<"***Insert at given Position***"<<endl;
    insert_at();
    }
    else if(d==7){
    cout<<"***Insert after given Position***"<<endl;
    insert_after();
    }
    else{
        break;
    }
    }
}
