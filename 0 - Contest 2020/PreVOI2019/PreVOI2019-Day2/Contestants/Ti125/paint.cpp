#include<bits/stdc++.h>
using namespace std;
int n,cnt;
const int mn=1e6+7;
const int oo=1e9;
//-------------------------
char p[mn+5];
int minn[200];
void sub1()
{
    while(n--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            char c;
            cin>>c;
            p[++cnt]=c;
        }
        else
        {
            char c1,c2;
            cin>>c1>>c2;
            for(int i=1;i<=cnt;i++)
                if(p[i]==c1)
                p[i]=c2;
        }
    }
    for(int i=1;i<=cnt;i++)
        cout<<p[i];
}
//------------------------
int d[mn+7];
int find(int u)
{
    if(u!=d[u])
        d[u]=find(d[u]);
    return d[u];
}
void sub2()
{
    for(int i='a';i<='z';i++)
        minn[i]=oo;
    while(n--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            char c;
            cin>>c;
            ++cnt;
            minn[c]=min(minn[c],cnt);
            d[cnt]=minn[c];
        }
        else
        {
            char c1,c2;
            cin>>c1>>c2;
            if(minn[c1]!=oo&&c1!=c2)
            {
                int t=minn[c2];
                minn[c2]=min(minn[c2],minn[c1]);
                if(t!=oo)
                    d[t]=minn[c2];
                d[minn[c1]]=minn[c2];
                minn[c1]=oo;
            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        int u=find(d[i]);
        for(int j='a';j<='z';j++)
            if(u==minn[j])
        {
            cout<<(char)j;
            break;
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>n;
    if(n<=1e4)
        sub1();
    else
        sub2();
}
