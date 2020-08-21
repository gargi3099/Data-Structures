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
node* top=NULL;
void push(int data)
{   node* temp=createnode(data);
    if(top==NULL)
    {
       top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

int search(int ele)
{   node* t=top;
    int f=0,p=0;
    while(t!=NULL)
    {   p++;
        if(t->data==ele)
        {   f=1;
            break;
        }
        t=t->next;
    }
    if(f!=0)
        return p;
    else
        return -1;   
}

void pop()
{   node* temp=top;
    top=top->next;
    temp->next=NULL;
    free(temp);
}

void count()
{   node* t=top;
    int c=0;
    while(t!=NULL)
    {
        c++;
        t=t->next;
    }
    cout<<"\nThe size of stack is "<<c;
}

void display()
{   cout<<top->data<<"<---------TOP";
    node* t=top->next;
    while(t!=NULL)
    {   cout<<endl;
        cout<<t->data;
        t=t->next;
    }
    cout<<endl;
}

int main()
{   int p;
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    display();
    pop();
    pop();
    display();
    count();
    p=search(3);
    if(p>0)
        cout<<"\nThe number was found at position "<<p;
    else
        cout<<"\nThe number was not found."; 
}