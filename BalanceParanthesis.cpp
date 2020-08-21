#include<bits/stdc++.h>
#include<conio.h>
#include<string.h>
using namespace std;

struct node
{
    char data;
    node* next;
};

node* createnode(char data)
{
    node* temp=new node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}
node* top=NULL;
void push(char data)
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

void pop()
{   node* temp=top;
    top=top->next;
    temp->next=NULL;
    free(temp);
}

bool balance(string s)
{   char t;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {    push(s[i]);
             continue;
        }
        else if(top==NULL)
                return false;
             else
             {
                 switch (s[i])
                 {
                    case ')' :  t=top->data;
                                pop();
                                if(t=='{' || t=='[')
                                {    return false;
                                }
                                break;
                    case '}' :  t=top->data;
                                pop();
                                if(t=='(' || t=='[')
                                {    return false;
                                }
                                break;
                    case ']' :  t=top->data;
                                pop();
                                if(t=='{' || t=='(')
                                {    return false;
                                }
                                break;
                 default:   cout<<"\n Wrong input";
                     break;
                 }
             }   
    }
        if(top==NULL)
            return true;
        else
            return false;  
}

int main()
{   bool p=balance("[{()()}()]");
    if(p==1)
        cout<<"\nThe paranthesis are balanced.";
    else
        cout<<"\nThe paranthesis are not balanced."; 
}