#include<bits/stdc++.h>
using namespace std;
#define job "DHAKA"
#define nmax 200005
#define int long long
int n,m,head[nmax],link[nmax],d[nmax],l,k;
struct edge{
    int u,v,w;
}e[nmax];
struct lab{
    int u,d;
};
struct cmp{
    bool operator() (lab& a,lab& b){
        return a.d>b.d;
    }
};
vector<int> s[nmax];
void enter(){
    cin>>n>>m>>l>>k;
    for(int i=1,t,x;i<=n;i++){
        cin>>t;
        s[i].resize(t);
        while(t--){
            cin>>x;
            s[i].push_back(x);
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
        e[i+m]={e[i].v,e[i].u,e[i].w};
    }
    memset(head,0,sizeof head);
    for(int i=1;i<=2*m;i++)
    {
        link[i]=head[e[i].u];
        head[e[i].u]=i;
    }
}
int dij(int s,int t){
    fill_n(d,n+1,INT_MAX);
    priority_queue<lab,vector<lab>,cmp> pq;
    d[s]=0;
    pq.push({s,0});
    while(pq.size())
    {
        int u=pq.top().u;
        pq.pop();
        if(u==t){
            return d[t];
        }
        for(int i=head[u];i;i=link[i])
        {
            int v=e[i].v,w=e[i].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                pq.push({v,d[v]});
            }
        }
    }
}
namespace sub2{
    void solve(){
        cout<<dij(1,n);
    }
}
namespace sub3{
    void solve(){
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            if(s[i].size()){
                ans=min(dij(1,i)+dij(i,n),ans);
            }
        }
        cout<<ans;
    }
}
void solve(){
    if(l==0)
        sub2::solve();
    else if(k==1)
        sub3::solve();
}
main()
{
    freopen(job".inp","r",stdin);
    freopen(job".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    enter();
    solve();
}
