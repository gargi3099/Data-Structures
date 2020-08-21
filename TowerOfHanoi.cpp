#include<bits/stdc++.h>
using namespace std;

void towerofhanoi(int n,char from,char to,char aux)
{
    if(n==1)
    {
        cout<<"\nMove disk 1 from "<<from<<" to "<<to;
        return;
    }

    towerofhanoi(n-1,from,aux,to);
    cout<<"\nMove disk "<<n<<" from "<<from<<" to "<<to;
    towerofhanoi(n-1,aux,to,from);
}

int main()
{
    towerofhanoi(3,'A','C','B');
    return 0;
}