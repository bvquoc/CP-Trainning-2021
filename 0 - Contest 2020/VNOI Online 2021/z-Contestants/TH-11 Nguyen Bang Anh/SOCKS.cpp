#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
#define oo 1000000000
#define MAXN 500001
#define ll long long
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define PR(x,a,b) {cout<<#x<<' '; for(long long i=a;i<=b;i++) cout<<x[i]<<' '; cout<<'\n'; }
#define all(x) x.begin(),x.end()
#define pb push_back
#define taskname "SOCKS"
#define fi first
#define se second
#define base 998244353

int n,q;
int t[MAXN];
vector<int> neighs[MAXN];
int queries[MAXN];

void read()
{
    int x,y;

    cin>>n>>q;
    FOR(i,1,n) cin>>t[i];
    FOR(i,1,n-1)
    {
        cin>>x>>y;
        neighs[x].push_back(y);
        neighs[y].push_back(x);
    }
    FOR(i,1,q) cin>>queries[i];
}

int tri[MAXN];
int central;

void init()
{
//    int Fa, Child, tam;
//    FOR(i,1,n)
//    {
//        if(neighs[i].size()==3) central=i;
//    }
//    tri[central]=0;
//    FOR(i,0,neighs[central].size()-1)
//    {
//        Fa=central;
//        Child=neighs[central][i];
//        while(1)
//        {
//            tri[Child]=i+1;
//            if(neighs[Child].size()==1) break;
//            FOR(i,0,neighs[Child].size()-1)
//            {
//                if(neighs[Child][i]!=Fa) tam=neighs[Child][i];
//            }
//            Fa=Child;
//            Child=tam;
//        }
//    }
}

void solve()
{
    bool sub1=true;
    FOR(i,1,n) if(neighs[i].size()>2) sub1=false;
    if(sub1)
    {
        int dem=0;
        FOR(i,1,n) if(t[i]) dem++;
        if(dem>1) cout<<1<<'\n';
        else cout<<0<<'\n';
        FOR(i,1,q)
        {
            if(t[queries[i]]==1)
            {
                t[queries[i]]=0;
                dem--;
            }
            else
            {
                t[queries[i]]=1;
                dem++;
            }
            if(dem>1) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
//    else
//    {
//        int kq=0;
//        int dem[4];
//        FOR(i,1,n)
//        {
//            if(t[i]) dem[tri[i]]++;
//        }
//        FOR(i,1,3) if(dem[i]) kq++;
//        cout<<kq-1<<'\n';
//        FOR(i,1,q)
//        {
//            if(t[queries[i]]==1)
//            {
//                t[queries[i]]=0;
//                dem[tri[i]]--;
//            }
//            else
//            {
//                t[queries[i]]=1;
//                dem[tri[i]]++;
//            }
//        }
//    }
}

int main()
{
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    read();
    init();
    solve();
    return 0;
}
