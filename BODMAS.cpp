#include<bits/stdc++.h>
#include<conio.h>
#include<string.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct cnode
{
    char data;
    cnode* next;
};

node* top=NULL;
cnode* ctop=NULL;

void push(int data)
{   node* temp=new node();
    temp->data=data;
    if(top==NULL)
    {
        temp->next=NULL;
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

void cpush(char data)
{   cnode* temp=new cnode();
    temp->data=data;
    if(ctop==NULL)
    {
        temp->next=NULL;
        ctop=temp;
    }
    else
    {
        temp->next=ctop;
        ctop=temp;
    }
}

void pop()
{   node* temp=top;
    top=top->next;
    temp->next=NULL;
    free(temp);
}

void cpop()
{   cnode* temp=ctop;
    ctop=ctop->next;
    temp->next=NULL;
    free(temp);
}

int precedence(char a)
{   if(a=='+' || a=='-')
        return 1;
    else if(a=='*' || a=='/')
            return 2;
         else
            return 0;
}

int calculate(int a,int b,char o)
{
    switch (o)
    {
        case '+':   return a+b;
                    break;
        case '-':   return a-b;
                    break;
        case '*':   return a*b;
                    break;
        case '/':   return a/b;
                    break;
        default: cout<<"\nWrong operation.";
                 break;
    }
}

int evaluate(string s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
            continue;
        else if(s[i]=='(')
                cpush(s[i]);
             else if(isdigit(s[i]))
                {   int val=0;
                    while(i<s.length() && isdigit(s[i]))
                    {
                        val=(val*10) + (s[i]-'0');
                        i++;    
                    }
                    push(val);
                }
                else if(s[i]==')')
                    {   int val1,val2;
                        while(ctop!=NULL && ctop->data!='(')
                        {   val2=top->data;
                            pop();
                            val1=top->data;
                            pop();
                            char t=ctop->data;
                            cpop();
                            push(calculate(val1,val2,t));
                        }
                        if(ctop!=NULL)
                            cpop();
                    }
                    else
                    {
                        while (ctop!=NULL && (precedence(ctop->data)>=precedence(s[i])))
                        {   int val1,val2;
                            char t=ctop->data;
                            cpop();
                            val2=top->data;
                            pop();
                            val1=top->data;
                            pop();
                            push(calculate(val1,val2,t));
                        }
                        cpush(s[i]);
                    }
                        
    }
    while(ctop!=NULL)
    {                       int val1,val2;
                            char t=ctop->data;
                            cpop();
                            val2=top->data;
                            pop();
                            val1=top->data;
                            pop();
                            push(calculate(val1,val2,t));
    }
  return top->data;                  
}


int main()
{   cout<<"\nThe result is "<<evaluate("15 / 5 +  ( 4 * 2 ) ");
}