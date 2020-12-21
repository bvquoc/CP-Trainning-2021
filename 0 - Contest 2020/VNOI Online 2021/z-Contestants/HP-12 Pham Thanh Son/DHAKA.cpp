#include<bits/stdc++.h>
using namespace std;
///#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return rng()%(r-l+1) +l;}
#define fi first
#define se second
#define pii pair<int,int>
#define ii pair<long long,pii>
#define getbit(i,x) ((x>>i)&1ll)
#define tatbit(i,x) (x&~(1ll<<i))
#define batbit(i,x) (x^(1ll<<i))


const int maxn=1e5+10;
const long long INF=1e15;
int n,m,k,l;
long long ret=INF;
vector<int> a[maxn];
vector<pii> ad[maxn];

long long f[40][maxn];
int LIM;

void dijkstra(){
    forinc(i,1,LIM) forinc(j,1,n) f[i][j]=INF;
    int st_mask=0;
    for(auto &v:a[1]) st_mask+=(1ll<<(v-1));
    f[st_mask][1]=0;

    priority_queue<ii,vector<ii>,greater<ii>> st;
    st.push({0,{0,1}});
    while(!st.empty()){
        auto X=st.top();
        st.pop();
        long long dmin=X.fi;
        int mask=X.se.fi,umin=X.se.se;
        if(dmin>f[mask][umin]) continue;
        for(auto &j:ad[umin]){
             int v=j.fi;
             long long cost=j.se;
             int tmp=mask;
             for(auto &i:a[v]){
                if(!getbit(i-1,mask)) tmp+=(1ll<<(i-1));
             }
            if(f[tmp][v]>dmin+cost){
                f[tmp][v]=dmin+cost;
                st.push({f[tmp][v],{tmp,v}});
            }
        }
    }

}

main(){
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k>>l;
    LIM=(1ll<<k)-1;
    forinc(i,1,n){
        int sz;
        cin>>sz;
        forinc(j,1,sz){
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    forinc(i,1,m){
        int u,v,c;
        cin>>u>>v>>c;
        ad[u].push_back({v,c});
        ad[v].push_back({u,c});
    }
    dijkstra();
    forinc(j,0,LIM){
        int sl=__builtin_popcount(j);
        if(sl>=l) ret=min(ret,f[j][n]);
    }
    cout<<(ret==INF?-1:ret);
}
