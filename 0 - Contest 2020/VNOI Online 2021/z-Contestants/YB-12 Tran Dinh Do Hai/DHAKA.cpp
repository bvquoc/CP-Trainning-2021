///Kurumi
#include <bits/stdc++.h>
#define ll long long
//#define int long long
#define ull unsigned long long
#define Pll pair < ll, ll >
#define Pii pair < int, int >
#define Piii pair < int, Pii >
#define Vi vector < int >
#define Vii vector < Pii >
#define pb push_back
#define mp make_pair
#define reset(x) memset(x, 0, sizeof(x))
#define foru(i, a, b) for(int i = a; i <= b; i++)
#define ford(i, a, b) for(int i = a; i >= b; i--)
#define forv(xx, gg) for(auto xx : gg)
#define fi first
#define se second
#define Lelouch main()
#define Kurumi "DHAKA"
#define nmax 100005

const ll OO = 1e15+7 ;
const ll mod = 1e9+7;
using namespace std;

int n,m,k,l;
int Xiao = mod,visit[15];
map < Pii, int > ddd;
int h[nmax],x[nmax];
int d[nmax],d1[nmax],d2[nmax];
Vii g[nmax];
int s[nmax], check[nmax],dd = 0;
Vi gg[nmax];

ll read(){
    ll res = 0;
    char c = getchar();
    bool Neg = false;
    while(c == ' ' || c == '\n') c = getchar();
    if(c == '-'){
        Neg = true;
        c = getchar();
    }
    while('0' <= c && c <= '9'){
        res = res * 10 + c - '0';
        c = getchar();
    }
    if(Neg) return -res;
    return res;
}

inline void add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void _check(){
    reset(visit);
    int CC = 0;
    int kt = 0;
    h[0] = 1;
    foru(i,1,n){
        if(ddd[{h[i],h[i - 1]}] == 0) break;

        CC += ddd[{h[i],h[i - 1]}];
        if(h[i] == n){
            kt = 1;
            break;
        }
    }

    if(kt == 1){
        int cnt = 0;
        foru(i,1,n){
            if(s[h[i]] > 0){
                forv(v,gg[h[i]]){
                    if(visit[v] == 0){
                        visit[v] = 1;
                        cnt++;
                    }
                }

            }

            if(h[i] == n) break;
        }

        if(cnt >= l) Xiao = min(Xiao, CC);
    }
}

void _s(int i){
    foru(j,1,n){
        h[i] = j;
        if(x[j] == 0){
            x[j] = 1;
            if(i == n) _check();
            else _s(i + 1);
            x[j] = 0;
        }
    }
}

void sub1(){
    _s(1);
    if(Xiao ==  mod) Xiao = -1;

    cout << Xiao << '\n';
}

void dij2(int x){
    priority_queue < Pii, Vii, greater < Pii > > q;

    foru(i,1,n){
        d[i] = mod;
    }

    d[x] = 0;

    q.push({0,x});

    while(!q.empty()){
        int u = q.top().se;
        int du = q.top().fi;

        q.pop();

        if(d[u] != du) continue;

        forv(xx,g[u]){
            int v = xx.fi;
            int dv = xx.se;

            if(d[v] > d[u] + dv){
                d[v] = d[u] + dv;
                q.push({d[v],v});
            }
        }
    }
}

void sub2(){
    dij2(1);
    if(d[n] == mod) d[n] = -1;
    cout << d[n] << '\n';
}

void dij3(int d[], int x){
    priority_queue < Pii, Vii, greater < Pii > > q;

    foru(i,1,n){
        d[i] = mod;
    }

    d[x] = 0;

    q.push({0,x});

    while(!q.empty()){
        int u = q.top().se;
        int du = q.top().fi;

        q.pop();

        if(d[u] != du) continue;

        forv(xx,g[u]){
            int v = xx.fi;
            int dv = xx.se;

            if(d[v] > d[u] + dv){
                d[v] = d[u] + dv;
                q.push({d[v],v});
            }
        }
    }
}

void sub3(){
    dij3(d1,1);
    dij3(d2,n);

    int LL = mod;

    foru(i,1,n){
        if(s[i] > 0){
            LL = min(LL, d1[i] + d2[i]);
        }
    }

    if(LL == mod) LL = -1;

    cout << LL << '\n';
}

void kurumi(){
    cin >> n >> m >> k >> l;

    foru(i,1,n){
        cin >> s[i];
        foru(j,1,s[i]){
            int u;
            cin >> u;
            gg[i].pb(u);
            if(check[u] == 0){
                check[u] = 1;
                dd++;
            }
        }
    }

    foru(i,1,m){
        int u,v,w;
        cin >> u >> v >> w;
        if(n <= 10){
            ddd[{u,v}] = w;
            ddd[{v,u}] = w;
        }
        g[u].pb({v,w});
        g[v].pb({u,w});
    }

    if(dd < l){
        cout << -1;
        return;
    }

    if(l == 0){
        sub2();
        return;
    }

    if(k == 1){
        sub3();
        return;
    }

    sub1();
}

Lelouch
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen(Kurumi".inp","r",stdin);
    freopen(Kurumi".out","w",stdout);
    kurumi();
    return 0;
}
