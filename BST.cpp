#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* createnode(int data)
{
    node* temp=new node();
    temp->data=data;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* rootptr,int data)
{   if(rootptr==NULL)
    {    node* temp=createnode(data);
         rootptr=temp;
    }
    else if(data <= rootptr->data)
    {
        rootptr->left=insert(rootptr->left,data);
    }
    else if(data > rootptr->data)
    {
        rootptr->right=insert(rootptr->right,data);
    }
    return rootptr;
}

bool search(node* rootptr,int data)
{   if(rootptr==NULL)
        return false;
    else if(data==rootptr->data)
            return true;
         else if(data < rootptr->data)
                return search(rootptr->left,data);
              else if(data > rootptr->data)
                     return search(rootptr->right,data);

}

int minimum(node* rootptr)
{   while(rootptr->left!=NULL)
        rootptr=rootptr->left;
    return rootptr->data;
}

int maximum(node* rootptr)
{   while(rootptr->right!=NULL)
        rootptr=rootptr->right;
    return rootptr->data;
}

int height(node* rootptr)
{   if(rootptr==NULL)
        return -1;
    else 
        return (max(height(rootptr->left),height(rootptr->right)) + 1);

}

void leveltraverse(node* rootptr)
{   queue<node*> discovered;
    node* t;
    if(rootptr==NULL)
    {   cout<<"\nTree is empty.";
        return;
    }
    else
    {   while(!discovered.empty())
        {   discovered.push(rootptr);
            t=discovered.front();
            discovered.pop();
            cout<<t->data<<" ";
            discovered.push(rootptr->left);
            discovered.push(rootptr->right);
        }
    }  
}

void preorder(node* rootptr)
{   if(rootptr==NULL)
        return;
    else
    {
        cout<<rootptr->data<<" ";
        preorder(rootptr->left);
        preorder(rootptr->right);
    }
}

void inorder(node* rootptr)
{   if(rootptr==NULL)
        return;
    else
    {
        inorder(rootptr->left);
        cout<<rootptr->data<<" ";
        inorder(rootptr->right);
    }
}

void postorder(node* rootptr)
{   if(rootptr==NULL)
        return;
    else
    {
        postorder(rootptr->left);
        postorder(rootptr->right);
        cout<<rootptr->data<<" ";
    }
}

node* deleteanode(node* rootptr,int data)
{   if(rootptr==NULL)
        return NULL;
    else if(data < rootptr->data)
            rootptr->left=deleteanode(rootptr->left,data);
         else if(data > rootptr->data)
                rootptr->right=deleteanode(rootptr->right,data);
              else if(data==rootptr->data)
                   {   node* temp=rootptr;
                       if(rootptr->left==NULL && rootptr->right==NULL)
                       {
                           rootptr=NULL;
                           delete temp;
                       }
                       else if(rootptr->left==NULL)
                            {
                                rootptr=rootptr->right;
                                delete temp;
                            }
                            else if(rootptr->right==NULL)
                                {
                                    rootptr=rootptr->left;
                                    delete temp;
                                }
                                else
                                {   int t=minimum(rootptr->right);
                                    rootptr->data=t;
                                    rootptr->right= deleteanode(rootptr->right,t);
                                }
                        return rootptr;
                   }
}

bool check(node* rootptr, int minvalue, int maxvalue)
{   if(rootptr==NULL)
        return true;
    if(minvalue < rootptr->data && maxvalue > rootptr->data && 
       check(rootptr->left,minvalue,rootptr->data) && check(rootptr->right,rootptr->data,maxvalue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

node* find(node* rootptr,int data)
{   if(rootptr==NULL)
        return NULL;
    else if(data < rootptr->data)
            return find(rootptr->left,data);
         else if(data > rootptr->data)
                return find(rootptr->right,data);
              else if(data==rootptr->data)
                      return rootptr;
}

node* inordersuccessor(node* rootptr,int data)
{   node* current = find(rootptr,data);
    if(current->right!=NULL)
    {   node* temp=current->right;
        while(temp->left!=NULL)
            temp=temp->left;
        return temp;
    }
    else
    {   node* successor=NULL;
        node* ancestor=rootptr;
        while (ancestor!=current)
        {
            if(current->data < ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else
            {
                ancestor=ancestor->right;
            }
        }
        return successor;
    }
}  

int main()
{   node* root=NULL;
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,7);
    root=insert(root,6);
    root=insert(root,8);
    root=insert(root,10);
    if(search(root,3)==true)
        cout<<"\nNumber found.";
    else
        cout<<"\nNumber not found.";
    cout<<"\nMinimum value = "<<minimum(root);
    cout<<"\nMaximum value = "<<maximum(root);
    cout<<"\nHeight of tree = "<<height(root);
    cout<<"\nInorder traversal - ";
    inorder(root);
    cout<<"\nPreorder traversal - ";
    preorder(root);
    cout<<"\nPostorder traversal - ";
    postorder(root);
    root=deleteanode(root,4);
    root=deleteanode(root,1);
    root=deleteanode(root,7);
    cout<<"\nPreorder traversal - ";
    preorder(root);
    if(check(root,INT_MIN,INT_MAX)==true)
        cout<<"\nIt is a binary search tree.";
    else
        cout<<"\nIt is not a binary search tree.";
    node* insuccessor=inordersuccessor(root,2);
    cout<<endl<<insuccessor->data;
    insuccessor=inordersuccessor(root,3);
    cout<<endl<<insuccessor->data;
    return 0;
}