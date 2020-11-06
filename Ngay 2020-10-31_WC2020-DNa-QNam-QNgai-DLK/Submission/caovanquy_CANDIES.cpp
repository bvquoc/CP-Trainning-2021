#include <bits/stdc++.h>

using namespace std;

int t,dem,fi,i,m,be;
int c[200000],n[1000],k[1000];

int main()
{
    cin>>t;
    m=0;
    for (int i=1; i<=t; i++)
    {
        cin>>n[i]>>k[i];
        m=max(m,n[i]);
    }
    c[1]=1;
    c[0]=1;
    /*f[1]=1;
    f[2]=1;
    c[1]=1;
    i=2;
    while (f[i]+f[i-1]<=m)
    {
        i++;
        f[i]=f[i-1]+f[i-2];
        c[f[i]]=1;
    }*/
    fi=1;
    be=0;

    for (int i=1; i<=m; i++)
        {
                if (c[i-fi]==1 && i-fi==be)
                {
                    be=fi;
                    fi=i;
                    c[i]=1;
                }
                    else c[i]=c[i-fi]+1;
        }
    for (int j=1; j<=t; j++)
    {
        dem=0;
        for (int i=n[j]; i>=1; i--)
            {
                if (c[n[j]-i+1]>=k[j] && (n[j]-i+1)!=0) dem+=c[n[j]-i+1];
            }
        cout<<dem<<endl;
    }
}
