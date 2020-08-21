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
node* head=NULL;
void insertatbeg(int data)
{   node* temp=createnode(data);
    if(head==NULL)
    {
       head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void insertatend(int data)
{   node* t=head;;
    node* temp=createnode(data);
    if(head==NULL)
    {
       head=temp;
    }
    else
    {   while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
    }
}

void insertatpos(int pos,int data)
{   node* temp=createnode(data);
    node* p=head;
    for(int i=1;i<pos-1;i++)
    {
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
}

int search(int ele)
{   node* t=head;
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

void insertafteranode(int ele,int data)
{   int p=search(ele);
    if(p==-1)
        cout<<"Cannot insert. The element was not found.";
    else
    {   insertatpos(p+1,data);
    }  
}

void insertbeforeanode(int ele,int data)
{   int p=search(ele);
    if(p==-1)
        cout<<"Cannot insert. The element was not found.";
    else if(p==1)
    {
        insertatbeg(data);
    }
    else
    {   insertatpos(p,data);
    } 
}

void deletefrombeg()
{   node* temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
}

void deletefromend()
{   node* p=head;
    node* q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
}

void deletefrompos(int pos)
{   node* p=head;
    node* q=head->next;
    for(int i=1;i<pos-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    q->next=NULL;
    free(q);

}

void swap(node* a,node* b)
{   int temp=a->data;
    a->data=b->data;
    b->data=temp;
}

void sort()
{   node* t;
    node* last=NULL;
    int swapped;
    do
    {
       swapped=0;
       t=head;
       while (t->next!=last)
       {
           if(t->data > t->next->data)
           {
               swap(t,t->next);
               swapped=1;
           }
            t=t->next;
       }
       last=t;   
    } while (swapped);
}

void reverse()
{
    node* curr=head;
    node* prev=NULL;
    node* next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

void remduplicate()
{   node* dup;
    node* p=head;
    node* q;
    while (p!=NULL && p->next!=NULL)
    {   q=p;
        while (q->next!=NULL)
        {
            if(p->data==q->next->data)
            {
                dup=q->next;
                q->next=q->next->next;
                free(dup);
            }
            else
            {
                q=q->next;
            }
        }
        p=p->next;
    }
}

void count()
{   node* t=head;
    int c=0;
    while(t!=NULL)
    {
        c++;
        t=t->next;
    }
    cout<<"\nThe number of nodes are "<<c;
}

void display()
{   node* t=head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

int main()
{   int p;
    insertatbeg(72);
    insertatbeg(84);
    insertatend(84);
    insertatend(25);
    insertatpos(3,3);
    display();
    deletefrombeg();
    deletefromend();
    deletefrompos(2);
    display();
    insertbeforeanode(72,84);
    insertbeforeanode(84,3);
    insertafteranode(84,25);
    sort();
    display();
    reverse();
    remduplicate();
    display();
  /*  count();
    p=search(3);
    if(p>0)
        cout<<"\nThe number was found at position "<<p;
    else
        cout<<"\nThe number was not found.";   */
}