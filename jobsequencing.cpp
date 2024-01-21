#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);

    int n, i = 0, index = 0, deadline = 0,d[100],numofslot;
    double p[100],perdayp[100], big = 0, profit = 0;
    cout<<"Enter number of jobs: ";
    cin>>n;
    cout<<"Enter the profits of jobs: ";
    for(i = 0; i < n; i++)
    {
        cin>>p[i];
    }
    cout<<"Enter the deadlines of jobs: ";
    for(i = 0; i < n; i++)
    {
        cin>>d[i];
    }
    for(i = 0; i < n; i++)
    {
        perdayp[i] = p[i] / d[i];
    }
    deadline = d[0];
    for(i = 0; i < n; i++)
    {
        if(d[i] > deadline)
        {
            deadline = d[i];
        }
    }
    numofslot = deadline;
    int slot[deadline];
    for(i = 0; i <= deadline; i++)
    {
        slot[i] = 0;
    }
    big = perdayp[0];
    while(numofslot > 0)
    {
    for(i = 0; i < n; i++)
    {
        if(perdayp[i] > big)
        {
            big = perdayp[i];
            index = i;
        }
    }
    perdayp[index] = 0;
    
    if(slot[d[index]] == 0)
    {
        numofslot--;
        slot[d[index]] += index+1;
    }
    else
    {
        numofslot--;
        for(i = 0; i <= d[index]; i++)
        {
            if(slot[i] == 0)
            {
                slot[i] += index+1;
            }
        }
    }
    //cout<<index<<" ";
    profit += p[index];
    index = 0;
    big = 0;
    }
    cout<<"Processing sequence: ";
    for(i = 1; i <= deadline; i++)
    {
        if(slot[i] != 0)
        {
            cout<<slot[i]<<" ";
        }
    }
    cout<<"\nValue: "<<profit<<"\n";

}