 #include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    printf("Enter number of objects & capacity: ");
    double x[100], profit = 0,p[100],w[100],W, M = 0, perunitp[100], big = 0.0;
    int i = 0, n = 0,ind = 0;
    
    cin>>n>>W;
    M = W;
    
    for(i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }
    printf("Enter the profits: ");
    for(i = 0; i < n; i++)
    {
        cin>>p[i];
    }
    for(i = 0; i < n; i++)
    {
        cin>>w[i];
    }
    for(i = 0; i < n; i++)
    {
        perunitp[i] = p[i] / w[i];
        //cout<<"perunitp = "<<perunitp[i]<<"\n";
    }
    big = perunitp[0];
    while(M > 0)
    {
    for(i = 0; i < n; i ++)
    {
        if(big < perunitp[i])
        {
            big = perunitp[i];
            ind = i;
        }
    }
    perunitp[ind] = 0;
    if(w[ind] <= M)
    {
        x[ind] = 1.0;
    }
    else
    {
        x[ind] = M / w[ind];
    }
    profit += p[ind]*x[ind];
    M = M - (w[ind]*x[ind]);
    big = 0;
    ind = 0;
    //cout<<"M = "<<M<<"\n";
    }
    for(i = 0; i < n; i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<"\n"<<profit<<"\n";
}