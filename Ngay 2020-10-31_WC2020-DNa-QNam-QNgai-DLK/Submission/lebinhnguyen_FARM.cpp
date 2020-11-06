#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int n,k,q,p,m,a[10001],f[10001][10001],kq=0,check[10001][10001];
void truyvet()
{
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(check[i][j]==1)
        {
            ans.push_back(i);
            i=i-k;
            j--;
            continue;
        }
        if(check[i][j]==0)
        {
            i--;
            continue;
        }
        ans.push_back(i);
        break;
    }
}
int main()
{
    cin>>n>>k>>q>>p;
    m=(q/p)+1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(i>=k)
        {
            if(f[i-1][j]< f[i-k][j-1]+a[i])
            {
                f[i][j]=f[i-k][j-1]+a[i];
                check[i][j]=1;
            }
            else
            {
                f[i][j]=f[i-1][j];
                check[i][j]=0;
            }
        }
        else
        {
            f[i][j]=a[i];
            check[i][j]=-1;
        }
    truyvet();
    sort(ans.begin(),ans.end(),greater <int> ());
    //cout<<ans.size()<<endl;
    for(int i :ans)
        kq=kq+ a[i]*(min(q,p)),q-=p;//,cout<<i<<endl;
    cout<<kq;
}
