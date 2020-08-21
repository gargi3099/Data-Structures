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
node* last=NULL;
void insertatbeg(int data)
{   node* temp=createnode(data);
    if(last==NULL)
    {
       last=temp;
       last->next=last;
    }
    else
    {
        temp->next=last->next;
        last->next=temp;
    }
}

void insertatend(int data)
{   node* temp=createnode(data);
    if(last==NULL)
    {
       last=temp;
       last->next=last;
    }
    else
    {   
        temp->next=last->next;
        last->next=temp;
        last=last->next;
    }
}

void insertatpos(int pos,int data)
{   node* temp=createnode(data);
    node* p=last->next;
    for(int i=1;i<pos-1;i++)
    {
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
}

int search(int ele)
{   node* t=last->next;
    int f=0,p=0;
    do
    {   p++;
        if(t->data==ele)
        {   f=1;
            break;
        }
        t=t->next;
    }while(t!=last->next);
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
{   node* temp=last->next;
    last->next=last->next->next;
    temp->next=NULL;
    free(temp);
}

void deletefromend()
{   node* p=last->next;
    node* q;
    while(p->next!=last)
    {
        p=p->next;
    }
    p->next=last->next;
    q=last;
    last=p;
    q->next=NULL;
    free(q);
}

void deletefrompos(int pos)
{   node* p=last->next;
    node* q=last->next->next;
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
    node* end=last;
    int swapped;
    do
    {
       swapped=0;
       t=last->next;
       while (t->next!=end)
       {
           if(t->data > t->next->data)
           {
               swap(t,t->next);
               swapped=1;
           }
            t=t->next;
       }
       end=t;   
    } while (swapped);
}

int count()
{   node* t=last->next;
    int c=0;
    while(t!=last)
    {
        c++;
        t=t->next;
    }
    return ++c;
}

void reverse()
{   node* curr=last->next;
    node* prev=last;
    node* next;
    int c=count();
    while (c!=0)
    {    
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        c--;
    }
    last=curr;
    last->next=prev;
    
}

void remduplicate()
{   node* dup;
    node* p=last->next;
    node* q;
    while (p!=last)
    {   q=p;
        while (q!=last)
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

void display()
{   node* t=last->next;
    while(t!=last)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<last->data;
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
    //sort();
    display();
    reverse();
    remduplicate();
    display();
  //  count();
    p=search(3);
    if(p>0)
        cout<<"\nThe number was found at position "<<p;
    else
        cout<<"\nThe number was not found.";   
}