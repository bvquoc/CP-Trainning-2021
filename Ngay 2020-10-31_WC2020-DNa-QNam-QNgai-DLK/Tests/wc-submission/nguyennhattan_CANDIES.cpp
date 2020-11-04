#include <bits/stdc++.h>

using namespace std;

int t,dem,fi,i,m;
int f[100000],c[100000],n[1000],k[1000];

int main()
{
    cin>>t;
    m=0;
    for (int i=1; i<=t; i++)
    {
        cin>>n[i]>>k[i];
        m=max(m,n[i]);
    }
    f[1]=1;
    f[2]=1;
    c[1]=1;
    i=2;
    while (f[i]+f[i-1]<=m)
    {
        i++;
        f[i]=f[i-1]+f[i-2];
        c[f[i]]=1;
    }
    for (int i=1; i<=m; i++)
        {
                if (c[i]==1) fi=i;
                    else c[i]=c[i-fi]+1;
        }
    for (int j=1; j<=t; j++)
    {
        dem=0;
        for (int i=n[j]; i>=1; i--)
            {
                if (c[n[j]-i+1]>=k[j]) dem+=c[n[j]-i+1];
            }
        cout<<dem<<endl;
    }
}
