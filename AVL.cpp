#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    int height;
};

node* root=NULL;

node* createnode(int data)
{
    node* temp=new node();
    temp->data=data;
    temp->left = temp->right = NULL;
    return temp;
}

int height(node* rootptr)
{   int hleft,hright;
    if(rootptr!=NULL && rootptr->left!=NULL)
    {
        hleft = rootptr->left->height;
    }
    else
    {
        hleft=0;
    }
    
    if(rootptr!=NULL && rootptr->right!=NULL)
    {
        hright = rootptr->right->height;
    }
    else
    {
        hright=0;
    }
    return (max(hleft,hright) + 1);
}

int balancefactor(node* rootptr)
{   int hleft,hright;
    if(rootptr!=NULL && rootptr->left!=NULL)
    {
        hleft = rootptr->left->height;
    }
    else
    {
        hleft=0;
    }
    
    if(rootptr!=NULL && rootptr->right!=NULL)
    {
        hright = rootptr->right->height;
    }
    else
    {
        hright=0;
    }
    return (hleft - hright);
}

node* LLrotation(node* rootptr)
{   node* tl=rootptr->left;
    node* tlr=tl->right;

    rootptr->left=tlr;
    tl->right=rootptr;
    rootptr->height=height(rootptr);
    tl->height=height(tl);
    if(root==rootptr)
        root=tl;

    return tl;
}

node* LRrotation(node* rootptr)
{   node* tl=rootptr->left;
    node* tlr=tl->right;

    tl->right=tlr->left;
    rootptr->left=tlr->right;
    tlr->left=tl;
    tlr->right=rootptr;
    rootptr->height=height(rootptr);
    tl->height=height(tl);
    tlr->height=height(tlr);
    if(root==rootptr)
        root=tlr;

    return tlr;
}

node* RRrotation(node* rootptr)
{   node* tr=rootptr->right;
    node* trl=tr->left;

    rootptr->right=trl;
    tr->left=rootptr;
    rootptr->height=height(rootptr);
    tr->height=height(tr);
    if(root==rootptr)
        root=tr;

    return tr;
}

node* RLrotation(node* rootptr)
{   node* tr=rootptr->right;
    node* trl=tr->left;

    tr->left=trl->right;
    rootptr->right=trl->left;
    trl->left=rootptr;
    trl->right=tr;
    rootptr->height=height(rootptr);
    tr->height=height(tr);
    trl->height=height(trl);
    if(root==rootptr)
        root=trl;

    return trl;
}

node* insert(node* rootptr,int data)
{   if(rootptr==NULL)
    {    node* temp=createnode(data);
         temp->height=0;
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
    rootptr->height=height(rootptr);
    if(balancefactor(rootptr)==2 && balancefactor(rootptr->left)==1)
        rootptr = LLrotation(rootptr);
    else if(balancefactor(rootptr)==2 && balancefactor(rootptr->left)==-1)
            rootptr = LRrotation(rootptr);
         else if(balancefactor(rootptr)==-2 && balancefactor(rootptr->right)==-1)
                rootptr = RRrotation(rootptr);
              else if(balancefactor(rootptr)==-2 && balancefactor(rootptr->right)==1)
                     rootptr = RLrotation(rootptr);
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
                   }
                   if(rootptr==NULL)
                      return NULL;

                    rootptr->height=height(rootptr);
                    if(balancefactor(rootptr)==2 && balancefactor(rootptr->left)>=0)
                        rootptr = LLrotation(rootptr);
                    else if(balancefactor(rootptr)==2 && balancefactor(rootptr->left)==-1)
                            rootptr = LRrotation(rootptr);
                         else if(balancefactor(rootptr)==-2 && balancefactor(rootptr->right)<=0)
                                 rootptr =  RRrotation(rootptr);
                              else if(balancefactor(rootptr)==-2 && balancefactor(rootptr->right)==1)
                                     rootptr =  RLrotation(rootptr);
                
    return rootptr;
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
{   root=insert(root,10);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,15);
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
    cout<<"\nPostorder traversal - ";
    postorder(root);
    cout<<"\nPreorder traversal - ";
    preorder(root);
    root=deleteanode(root,30);
    root=deleteanode(root,1);
    root=deleteanode(root,7);
    cout<<"\nPreorder traversal - ";
    preorder(root);
    node* insuccessor=inordersuccessor(root,15);
    cout<<endl<<insuccessor->data;
    insuccessor=inordersuccessor(root,3);
    cout<<endl<<insuccessor->data;
    return 0;
}