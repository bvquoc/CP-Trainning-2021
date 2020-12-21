#include <bits/stdc++.h>
#define MAX 500000
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define task "decor"
using namespace std;
int n,m,k,a[MAX+5];
struct subtask12
{
    int prefix[MAX+5];
    bool f(int len)
    {
        rep(i,1,n-len+1)
        if(prefix[i+len-1]-prefix[i-1]+k>=len) return true;
        return false;
    }

    void process()
    {
        rep(i,1,n) prefix[i]=prefix[i-1]+a[i];

        int lo=1,hi=n,ans=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(f(mid))
            {
                lo=mid+1;
                ans=mid;
            }else hi=mid-1;
        }

        for(int i=1;i<=n-ans+1;++i) if(prefix[i+ans-1]-prefix[i-1]+k>=ans)
        {
            cout<<i<<" "<<i+ans-1;
            return ;
        }
    }
}res12;


struct subtask3
{
    int prefix[MAX+5];
    vector<int> g[MAX+5];
    int cnt[MAX+5],flag[MAX+5],the;

    bool f(int len)
    {
        rep(i,1,n-len+1)
        {
            vector<int> vc;vc.clear();
            int res=0;
            rep(j,i,i+len-1) if(a[j])                vc.push_back(j),cnt[flag[j]]--;
            rep(j,i,i+len-1) if(!a[j]&&cnt[flag[j]]) vc.push_back(j),cnt[flag[j]]--,res++;
            for(auto u : vc) cnt[flag[u]]++;
            if(res+prefix[i+len-1]-prefix[i-1]+k>=len) return true;
        }
        return false ;
    }

    void dfs(int u)
    {
        flag[u]=the;cnt[the]+=a[u];
        for(auto v : g[u]) if(!flag[v]) dfs(v);
    }

    void process()
    {
        rep(i,1,m)
        {
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }


        rep(i,1,n) if(!flag[i]) ++the,dfs(i);
        rep(i,1,n) prefix[i]=prefix[i-1]+a[i];

        int lo=1,hi=n,ans=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(f(mid))
            {
                lo=mid+1;
                ans=mid;
            }else hi=mid-1;
        }

        int len=ans;
        rep(i,1,n-len+1)
        {
            vector<int> vc;vc.clear();
            int res=0;
            rep(j,i,i+len-1) if(a[j])                vc.push_back(j),cnt[flag[j]]--;
            rep(j,i,i+len-1) if(!a[j]&&cnt[flag[j]]) vc.push_back(j),cnt[flag[j]]--,res++;
            for(auto u : vc) cnt[flag[u]]++;
            if(res+prefix[i+len-1]-prefix[i-1]+k>=len)
            {
                cout<<i<<" "<<i+len-1<<endl;
                return ;
            }
        }
    }
}res3;

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>m>>k;

    string s;cin>>s;
    rep(i,1,n) a[i]=s[i-1]-'0';
    if(!m) res12.process();else res3.process();
}
