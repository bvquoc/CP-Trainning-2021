#include <bits/stdc++.h>
#define task "DHAKA"
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define N 100005
#define X first
#define Y second
#define oo 100000000
using namespace std;
typedef pair<int, int> ii;

bool Have[N];
bool Free3[N];
vector<ii> A[N];
int D[N], d[N];
int n,m,K,L;
int Seed[N];
int ans3 = oo;
int DIJ(){
    priority_queue< ii, vector<ii>, greater<ii>> PQ;
    bool Free[N];
    memset(Free, true, sizeof(Free));
    //Free[1] = false;
    REP(i,1,n) D[i] = oo;
    D[1] = 0;
    PQ.push(ii(0,1));
    #define sz PQ.size()
    while(sz >0){
        int u = PQ.top().Y;
        PQ.pop();
        if (!Free[u] || u == 0) continue;
        Free[u] = false;
        for(ii t:A[u]){
            int v = t.Y;
            int dd = t.X;
            if (Free[v] && D[v] > D[u] + dd){
                D[v] = D[u] + dd;
                PQ.push(ii(D[v],v));
            }
        }
    }
    return 0;
}
int DIJ2(){
    priority_queue<ii, vector<ii>, greater<ii>> PQ;
    bool Free[N];
    memset(Free, true, sizeof(Free));
  //  Free[1] = false;
    REP(i,1,n) d[i] = oo;
    d[n] = 0;
    PQ.push(ii(0,n));
    #define sz PQ.size()
    while(sz >0){
        int u = PQ.top().Y;
        PQ.pop();
        if (!Free[u] || u == 0) continue;
        Free[u] = false;
        for(ii t:A[u]){
            int v = t.Y;
            int dd = t.X;
            if (Free[v] && d[v] > d[u] + dd){
                d[v] = d[u] + dd;
                PQ.push(ii(d[v],v));
            }
        }
    }
    return 0;
}

bool Check(int Seed){
    int ans = 0;
    REP(i,1,4){
        ans += (Seed >>(i-1)) & 1;
    }
    if (ans >= L) return true;
    else
        return false;
}
int DFS(int u, int w, int NowSeed){
    if (u == n && Check(NowSeed)){
        ans3 = min(ans3, w);
        return 0;
    }
    Free3[u] = false;
    for(ii t: A[u]){
        int v = t.Y;
        int ww = t.X;
        if (Free3[v]){
            DFS(v, w+ ww, NowSeed | Seed[v]);
        }
    }
    Free3[u] = true;
    return 0;
}
int Sub2(){
    DIJ();
    if (D[n] == oo) cout<<"-1";
    else
    cout<<D[n];
    return 0;
}
int Sub1(){
    memset(Free3,true, sizeof(Free3));
    DFS(1,0,0);
    if (ans3 == oo) cout<<"-1";
    else cout<<ans3;
    return 0;
}
int Sub3(){
    DIJ();
    DIJ2();
    int ans = oo;
    REP(i,1,n){
        if (Have[i]){
            ans = min(ans, D[i] + d[i]);
        }
    }
    if (ans == oo) cout<<"-1";
    else
    cout<<ans;
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m>>K>>L;
    REP(i,1,n){
        int seed,temp;
        cin>>seed;
        Have[i] = (seed >0);
        REP(j,1,seed) {
            cin>>temp;
            Seed[i] = (Seed[i] | (1<< (temp-1)));
        }
    }
    REP(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        A[u].push_back(ii(w,v));
        A[v].push_back(ii(w,u));
    }
    if (L == 0){
        Sub2();
        return 0;
    }
    if (K == 1){
        Sub3();
        return 0;
    }
    if (n <=10){
        Sub1();
        return 0;
    }
    if (n <=100 || m<=100){
        Sub1();
        return 0;
    }

    else{
        cout<<"-1";
        return 0;
    }
}
