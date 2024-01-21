#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int i = 0, j = 0,sedge[10], k = 0, mst[10],n = 0,m = 0,size[10], start = 0, taken[10],end = 0, small = 0, arr1[10][10];
    int graph[7][7] = {{0,28,0,0,0,10,0},
    {28,0,16,0,0,0,14},
    {0, 16, 0, 12, 0, 0, 0},
    {0, 0, 12, 0, 22, 0, 18},
    {0, 0, 0, 22, 0, 25, 24},
    {10, 0, 0, 0, 25, 0, 0},
    {0,14,0,18,24,0,0}
    };
    int cost[10] = {10,12,14,16,18,22,24,25,28};
    for(int q = 0; q < )
    for(k =0; k < 9; k++)
    {
        int edge = cost[k];
        for(i = 0; i < 7; i++)
        {
            for(j = 0; j < 7; j++)
            {
                if(edge == graph[i][j])
                {
                    start = i; 
                    arr1[n][m] = i;
                    end = j;
                    arr1[n][m+1] = j;
                }
            }
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {

            }
        }
        
    }
}