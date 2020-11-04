#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int n,k,q,p,a[N];
long long dp[N][N];
long long tinh(int i,int j)
{
    if (dp[i][j]!=-1) return dp[i][j];
    if (i>n) return 0;
    if (j==0) return 0;
    long long tam=tinh(i+1,j);
    for (int l=1;l<=min(j,min(1000,p));l++)
        tam=max(tam,tinh(i+k,j-l)+a[i]*l);
    dp[i][j]=tam;
    return tam;
}
int main()
{
    cin>>n>>k>>q>>p;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<tinh(1,q);
}
