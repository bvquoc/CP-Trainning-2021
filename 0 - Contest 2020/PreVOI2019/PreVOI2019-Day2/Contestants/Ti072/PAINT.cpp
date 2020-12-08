#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e6+7;
char a[MAXN];
int n;
vector <int> pos[27];
int cnt=0;
void sub1()
{
    for(int i=1; i<=n; i++)
    {
        int te;
        cin>>te;
        if(te==1)
        {
            char x;
            cin>>x;
            pos[x-'a'].push_back(++cnt);
        }
        else
        {
            char x,y;
            cin>>x>>y;
            if(x==y)
                continue ;
            for(int j=0; j<(int)pos[x-'a'].size(); j++)
                pos[y-'a'].push_back(pos[x-'a'][j]);
            pos[x-'a'].clear();
        }
    }
    //cerr<<cnt;
    for(int i=0; i<26; i++)
        for(int j=0; j<(int)pos[i].size(); j++)
            a[pos[i][j]]=char(i+'a');
    for(int i=1; i<=cnt; i++)
        cout<<a[i];
}
int edges[27][27];
int d[27],counter[27];
int lol[MAXN];
int col[27][27];
//void trace(int u)
//{
//    int root=u;
//    while(par[u])
//    {
//        u=par[u];
//        col[root].push_back(u);
//    }
//}
//void DFS(int u)
//{
//    dd[u]=1;
//    bool ok=false;
//    for(int v=0; v<=25; v++)
//        if(edges[u][v]&&dd[v]==0)
//        {
//            ok=true ;
//            par[v]=u;
//            DFS(v);
//        }
//    if(!ok)
//        trace(u);
//}
void sub2()
{
    for(int i=1; i<=n; i++)
    {
        int te;
        cin>>te;
        if(te==1)
        {
            cin>>a[++cnt];
            counter[a[cnt]-'a']++;
        }
        else
        {
            char x,y;
            cin>>x>>y;
            if(!counter[x-'a'])
                continue ;
            //d[y-'a']=cnt;
            col[x-'a'][x-'a']=cnt;
            //col[y-'a'][y-'a']=cnt;
            if(x==y)
                continue ;
            for(int j=0; j<=25; j++)
            {
                col[y-'a'][j]=max(col[y-'a'][j],col[x-'a'][j]);
                col[x-'a'][j]=0;
            }
        }
    }
//    for(int i=0;i<=25;i++)
//    {
//        for(int j=0;j<=25;j++)
//            cerr<<col[i][j]<<" ";
//        cerr<<'\n';
//    }
//    for(int i=0; i<=25; i++)
//    {
//        memset(dd,0,sizeof(dd));
//        memset(par,0,sizeof(par));
//        DFS(i);
//    }
    for(int i=0; i<=25; i++)
    {
        int maxx=0;
        for(int j=0; j<=25; j++)
            maxx=max(maxx,col[i][j]);
        if(maxx)
            lol[maxx]=i+1;
    }
    for(int i=1; i<=cnt; i++)
    {
        pos[a[i]-'a'].push_back(i);
        if(lol[i])
        {
            int color=lol[i]-1;
            for(int j=0; j<=25; j++)
                if(col[color][j]&&j!=color)
                {
                    while(!pos[j].empty()&&pos[j][0]<=col[color][j])
                    {
                        pos[color].push_back(pos[j][0]);
                        pos[j].erase(pos[j].begin());
                    }
                }

        }
    }
    for(int i=0; i<26; i++)
        for(int j=0; j<(int)pos[i].size(); j++)
            a[pos[i][j]]=char(i+'a');
    for(int i=1; i<=cnt; i++)
        cout<<a[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    cin>>n;
    if(n<=1e4)
        sub1();
    else
        sub2();
    return 0;
}
