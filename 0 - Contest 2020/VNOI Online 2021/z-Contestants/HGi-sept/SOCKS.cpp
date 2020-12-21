#include <bits/stdc++.h>

using namespace std;
int i,j,n,x,y,q,td[10000][10000],gh[10000],th,dem;
vector <int> a,b,c,tv,ds;
int main()
{
    cin>>n>>q;
    int dd=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
        if(x==1) ds.push_back(x);
    }
    th=1;
    int vt;
    for(i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        gh[x]++;
        gh[y]++;
        td[x][gh[x]]=y;
        td[y][gh[y]]=x;
        if(gh[x]>2)
        {
            th=2;
            vt=x;
        }
        if(gh[x]>2) dem++;
        if(dem>1) th=3;
        if(gh[y]>2)
        {
            th=2;
            vt=x;
        }
        if(gh[y]>2) dem++;
        if(dem>1) th=3;
    }
    for(i=1;i<=q;i++)
    {
        cin>>x;
        tv.push_back(x);
    }
    if(th==1)
    {
        for(i=1;i<=q;i++)
        {
            cout<<1<<endl;
        }
    }
    if(th==2)
    {
        int x[10000];
        int a1,b1,c1,y;
        a1=td[vt][1];
        b1=td[vt][2];
        c1=td[vt][3];
        x[vt]=0;
        x[a1]=1;
        x[b1]=2;
        x[c1]=3;
        int kt=0,t;
        t=vt;
        while(gh[a1]>1)
        {
            if(td[a1][1]==t)
            {
                a1=td[a1][2];
            } else
            {
                a1=td[a1][1];
            }
            x[a1]=1;
        }
        while(gh[b1]>1)
        {
            if(td[b1][1]==t)
            {
                b1=td[b1][2];
            } else
            {
                b1=td[b1][1];
            }
            x[b1]=2;
        }
        while(gh[c1]>1)
        {
            if(td[c1][1]==t)
            {
                c1=td[c1][2];
            } else
            {
                c1=td[c1][1];
            }
            x[c1]=3;
        }
        int dem=0,dd[10]={0};
        for(i=1;i<=ds.size();i++)
        {
            if(dd[x[ds[i]]]==0)
            {
                dem++;
                dd[x[tv[i]]]=1;
            }
        }
        for(i=1;i<=q;i++)
        {
            if(a[tv[i-1]]==0)
            {
                a[tv[i-1]]=1;
                if(dd[x[tv[i-1]]]==0)
                {
                    dem++;
                    dd[x[tv[i]]]=1;
                }
            } else
            {
                a[tv[i-1]]=0;
                int kt=0;
                for(j=1;j<=n;j++)
                {
                    if(i!=j-1 && x[i]==x[tv[j-1]]) kt=1;
                }
                if(kt==0 && dem==2) dem--;
            }
        }
        cout<<dem;
    }
    return 0;
}

