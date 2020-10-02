#include <bits/stdc++.h>

using namespace std;
int n,m,i,ss,tt,k,dem,j,maxc,minc=1000005,t,w[100005],d[100005],p[100005];
long long s,v,vv;
int main()
{
    freopen("TALENT.INP","r",stdin);
    freopen("TALENT.OUT","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>d[i];
        if (d[i]>maxc)
            maxc=d[i];
        if (d[i]<minc)
            minc=d[i];
    }
    for (i=1;i<=n;i++)
    {
        cin>>w[i];
        if (w[i]==1)
            dem++;
    }
    for (i=1;i<=m;i++)
        cin>>p[i];
    if (dem!=n){
        s=0;
        for (k=1;k<=m;k++)
        {
            for (i=1;i<=n;i++)
                s=s+w[i]*abs(d[i]-p[k]);
            cout<<s<<'\n';
            s=0;
        }
    }
    else {
        for (i=1;i<=n;i++)
            s=s+abs(d[i]-maxc);
        v=s;
        for (i=1;i<=n;i++)
            ss=ss+abs(d[i]-minc);
        vv=ss;
        for (i=1;i<=m;i++)
        {
            s=0;
            ss=0;
            if (p[i]==maxc)
                cout<<v<<'\n';
            if (p[i]>maxc)
            {
                t=p[i]-maxc;
                s=s+t*n+v;
                cout<<s<<'\n';
            }
            if (p[i]<maxc && p[i]>minc)
            {
                for (j=1;j<=n;j++)
                    s=s+abs(d[j]-p[i]);
                cout<<s<<'\n';
            }
            if (p[i]==minc)
                cout<<vv<<'\n';
            if (p[i]<minc)
            {
                tt=minc-p[i];
                s=s+tt*n+vv;
                cout<<s<<'\n';
            }
        }
    }
    return 0;
}
