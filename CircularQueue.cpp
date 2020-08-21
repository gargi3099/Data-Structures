#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* createnode(int data)
{
    node* temp=new node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}
node* front=NULL;
node* rear=NULL;

void insert(int data)
{   node* temp=createnode(data);
    if(front==NULL)
    {
       front=rear=temp;
       rear->next=front;
    }
    else
    {   
        rear->next=temp;
        rear=rear->next;
        rear->next=front;
    }
}

void deleten()
{   if(front==NULL)
        cout<<"\nThe queue is empty.";
    else if(front==rear)
         {  node* temp=front;
            front=rear=NULL;
            free(temp);
         }
         else
         {
            node* temp=front;
            front=front->next;
            rear->next=front;
            temp->next=NULL;
            free(temp);
         }
}

void count()
{   node* t=front;
    int c=0;
    while(t!=rear)
    {
        c++;
        t=t->next;
    }
    cout<<"\nThe number of nodes are "<<++c;
}

void display()
{   node* t=front;
    while(t!=rear)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<rear->data;
    cout<<endl;
}

int main()
{   insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    deleten();
    deleten();
    display();
    count();
  /*  count();
    p=search(3);
    if(p>0)
        cout<<"\nThe number was found at position "<<p;
    else
        cout<<"\nThe number was not found.";   */
}