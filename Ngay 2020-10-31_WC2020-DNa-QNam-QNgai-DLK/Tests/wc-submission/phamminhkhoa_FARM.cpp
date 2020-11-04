#include<bits/stdc++.h>
using namespace std;
int n,k,q,p,a[10003],f[10003][10003];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k>>q>>p;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=q;j++)
        {
            if (i>k)
            {
                if (j<=p)
                {
                    f[i][j]=max(j*a[i],f[i-k][j]);
                }
                else
                {
                    f[i][j]=max(f[i-k][j-p]+a[i]*p,max(f[i-k][j],f[i-1][j]));
                }
            }
            else
            {
                if (j<=p)
                {
                    f[i][j]=j*a[i];
                }
                else
                {
                    f[i][j]=max(a[i]*p,f[i-1][j]);
                }
            }

        }
    }
    cout<<f[n][q];
}
