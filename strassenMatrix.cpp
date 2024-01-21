#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A[3][3], B[3][3];
    for(int i = 1; i < 3; i++)
    {
        for(int j = 1; j < 3; j++)
        {
            cin>>A[i][j];
        }
    }
    for(int i = 1; i < 3; i++)
    {
        for(int j = 1; j < 3; j++)
        {
            cin>>B[i][j];
        }
    }
    int p1 = A[1][1]*B[1][2] - A[1][1]*B[2][2];
    int p2 = A[1][1]*B[2][2] + A[1][2]*B[2][2];
    int p3 = A[2][1]*B[1][1] + A[2][2]*B[1][1];
    int p4 = A[2][2]*B[2][1] - A[2][2]*B[1][1];
    int p5 = A[1][1]*B[1][1] + A[1][1]*B[2][2] + A[2][2]*B[1][1] + A[2][2]*B[2][2];
    int p6 = A[1][2]*B[2][1] + A[1][2]*B[2][2] - A[2][2]*B[2][1] - A[2][2]*B[2][2];
    int p7 = A[1][1]*B[1][1] + A[1][1]*B[1][2] - A[2][1]*B[1][1] - A[2][1]*B[1][2];
    int c11 = p5+p4-p2+p6;
    int c12 = p1+p2;
    int c21 = p3+p4;
    int c22 = p5+p1-p3-p7;
    cout<<c11<<" "<<c12<<"\n";
    cout<<c21<<" "<<c22<<"\n";
}