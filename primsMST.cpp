#include<bits/stdc++.h>
using namespace std;
int main()
{
    int graph[7][7], i = 0, j = 0,sedge[10], k = 0, mst[10], start = 0, taken[10], small = 0;
    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 7; j++)
        {
            cin>>graph[i][j];
        }
    }
    while(k < 6)
    {
        i = start;
        small = 9999;
        for(j = 0; j < 7; j++)
        {
            if(graph[i][j] > 0 && graph[i][j] < small)
            {
                small = graph[i][j];
                taken[k] = j;
            }
        }
        if(k > 0)
        {
            for(int n = 0; n < k; n++)
            {
                i = taken[n];
                for(j = 0; j < 7; j++)
                {
                    if(graph[i][j] > 0 && graph[i][j] < small)
                    {
                        small = graph[i][j];
                        taken[k] = j;
                        start = i;
                    }
                }
            }
            for(int n = 0; n < k; n++)
            {
                i = sedge[n];
                for(j = 0; j < 7; j++)
                {
                    if(graph[i][j] > 0 && graph[i][j] < small)
                    {
                        small = graph[i][j];
                        taken[k] = j;
                        start = i;
                    }
                }
            }
        }

        mst[k] = small;
        graph[start][taken[k]] = 0;
        graph[taken[k]][start] = 0;
        sedge[k] = start;
        start = taken[k];
        k++;
    }
    for(i = 0; i < k; i++)
    {
        cout<<sedge[i]<<" - "<<taken[i]<<" "<<mst[i]<<"\n";
    }
}   