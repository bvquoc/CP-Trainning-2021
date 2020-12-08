#include<bits/stdc++.h>
using namespace std;
int type[1000010],value[1000010],par[1000010],color[1000010],x[1000010],y[1000010];
int getroot(int u)
{
    if(par[u]==-1)return u;
    par[u]=getroot(par[u]);
    return par[u];
}
void uni(int u,int v)
{
    int x=getroot(u),y=getroot(v);
    if(x!=y)
    {
        par[x]=y;
    }
}
main()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(par,-1,sizeof(par));
    //memset(value,1,sizeof(value));
    int n;
    cin>>n;
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        cin>>type[i];
        if(type[i]==1)
        {
            char c;
            cin>>c;
            color[i]=c-'a'+1;
        }
        else
        {
            char p,q;
            cin>>p>>q;
            x[i]=p-'a'+1;
            y[i]=q-'a'+1;
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(type[i]==2)
        {
            uni(x[i],y[i]);
            //cout<<par[2]<<" "<<getroot(2);
        }
        else
        {
            s.push(getroot(color[i]));
        }
    }
    while(s.size())
    {
        cout<<char(s.top()+'a'-1);
        s.pop();
    }
}
