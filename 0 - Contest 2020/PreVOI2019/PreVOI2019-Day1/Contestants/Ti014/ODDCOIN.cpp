#include <bits/stdc++.h>
using namespace std;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(false),cin.tie(nullptr);
#define task "ODDCOIN"
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))

main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    fasty;
    int T; cin>>T; while(T--){
        int x,t; cin>>x>>t;
        vector<int> val={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
        if(t<=100000){
            queue<int> q;
            vector<int> f(100010,INT_MAX);
            q.push(t); f[t]=0;
            val.pb(x);
            while(q.size()){
                int u=q.front(); q.pop();
                if(!u){
                    cout<<f[u]<<"\n";
                    break;
                }
                forv(w,val){
                    if(w>u) continue;
                    int v=u-w;
                    if(f[v]>f[u]+1){
                        f[v]=f[u]+1;
                        q.push(v);
                    }
                }
            }
        } else{
            auto brute=[&](int n){
                int ret=0, i=val.size()-1;
                while(n){
                    while(val[i]>n) i--;
                    ret+=n/val[i];
                    n%=val[i];
                }
                return ret;
            };
            int ret=brute(t);
            forinc(i,0,min(ret,t/x)){
                ret=min(ret,brute(t-i*x)+i);
            }
            cout<<ret<<"\n";
        }
    }
}

