#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define piii pair<ll,ii>
#define fi first
#define se second
#define add push_back
#define N 500010
using namespace std;
int n,m,k,li[N],ans=0,ans1,countt=0,Num[N],Low[N],dd[N],nextt[N],t,tp[N];
string s;
stack<int>ngxep;
vector<int>ed[N],sw[N];
void sub1()
{
    int dem=0,st;
    for(int i=1; i<=n; i++)
    {
        if(li[i]==0)
            dem=0;
        else
        {
            if(dem==0)
            {
                st=i;
                dem++;
            }
            else
                dem++;
            if(dem>ans)
            {
                ans=dem;
                ans1=st;
            }
        }
    }
    cout<<ans1<<" "<<ans1+ans-1;
}
void sub2()
{
    int j=1,use=0;
    for(int i=1; i<=n; i++)
    {
        while(j<=n)
        {
            if(li[j]==0)
            {
                if(use<k)
                {
                    use++;
                    j++;
                }
                else
                    break;
            }
            else
                j++;
        }
        if(j-i>ans)
        {
            ans=j-i;
            ans1=i;
        }
        if(li[i]==0)
            use--;
    }
    cout<<ans1<<" "<<ans1+ans-1;
}
void DFS(int u)
{
    countt++;
    Low[u]=Num[u] = countt;
    ngxep.push(u);
    for(int v=0; v<ed[u].size(); v++)
    {
        if(Num[ed[u][v]]!=0)
        {
            Low[u]=min(Low[u],Num[ed[u][v]]);
        }
        else
        {
            DFS(ed[u][v]);
            Low[u]=min(Low[u],Low[ed[u][v]]);
        }
    }
    if(Low[u]==Num[u])
    {
        t++;
        int v;
        do
        {
            v = ngxep.top();
            tp[v]=t;
            Low[v]=Num[v]=100000;
            ngxep.pop();
        }
        while(v!=u);
    }
}
void sub3()
{
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        ed[u].add(v);
        ed[v].add(u);
    }
    for(int i=1; i<=n; i++)
        if(!Num[i])
            DFS(i);
    for(int i=1; i<=n; i++)
        sw[tp[i]].add(i);
    int j=1,use=0;
    for(int i=1; i<=n; i++)
    {
        while(j<=n)
        {
            if(li[j]==0 or dd[j]==1)
            {
                bool ok=false;
                for(int v:sw[tp[j]])
                {
                    if(v>=i and v<=j)
                        continue;
                    if(dd[v]==0 and li[v]==1)
                    {
                        dd[v]=1;
                        nextt[j]=v;
                        ok=true;
                        break;
                    }
                }
                if(ok)
                    j++;
                else
                {
                    if(use<k)
                    {
                        use++;
                        j++;
                    }
                    else
                        break;
                }
            }
            else
                j++;
        }
        if(j-i>ans)
        {
            ans=j-i;
            ans1=i;
        }
        if(li[i]==0 or dd[i]==1)
        {
            int tmp=nextt[i];
            while(tmp!=0)
            {
                dd[tmp]=0;
                int x=tmp;
                tmp=nextt[tmp];
                nextt[x]=0;
            }
            nextt[i]=0;
            use--;
        }
    }
    cout<<ans1<<" "<<ans1+ans-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    bool ok1=true;
    for(int i=0; i<s.size(); i++)
    {
        li[i+1]=s[i]-'0';
        if(li[i+1]==1)
            ok1=false;
    }
    if(ok1 and k==0)
    {
        cout<<"-1";
        exit(0);
    }
    if(m==0 and k==0)
        sub1();
    else
    {
        if(m==0)
            sub2();
        else
            sub3();
    }
}
