#include<bits/stdc++.h>

using namespace std;

int n,id,goc[30],par[1000006];

char a[1000006];

int cha(int u)
{
    if(par[u]==u) return u;
    else
    {
        par[u]=cha(par[u]);
        return par[u];
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin>>n;
    while(n--)
    {
        int ty;
        char x,y;
        cin>>ty;
        //cout<<goc[0]<<"  ";
        if(ty==1)
        {
            cin>>x;
            id++;
            a[id]=x;
            if(goc[x-'a']==0)
            {
                goc[x-'a']=id;
            }
            par[id]=goc[x-'a'];
        }
        else
        {
            cin>>x>>y;
            if(x!=y)
            {
                int u=goc[x-'a'];
                int v=goc[y-'a'];
                if(u!=0&&v!=0)
                {
                    if(u>v)
                    {
                        par[u]=v;
                        goc[x-'a']=0;
                    }
                    else
                    {
                        par[v]=u;
                        goc[x-'a']=0;
                        goc[y-'a']=cha(u);
                    }
                }

            }

        }
        //cout<<goc[0]<<'\n';
    }
    for(int i=0;i<='z'-'a';i++)
    {
        if(goc[i]!=0) a[goc[i]]=char('a'+i);
    }
    for(int i=1;i<=id;i++)
    {
        a[i]=a[cha(i)];
    }
    for(int i=1;i<=id;i++) cout<<a[i];
}
