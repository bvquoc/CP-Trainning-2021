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
#define Kurumi "COOLMAC"
#define nmax 100005

const ll OO = 1e15+7 ;
const ll mod = 1e9+7;
using namespace std;

int m,n,mi = mod,ma = -mod;
Pii a[nmax];
int t[nmax];
int ddd[nmax];
Vii g;

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

bool cmp(Pii a, Pii b){
    if(a.fi != b.fi) return a.fi < b.fi;

    return a.se > b.se;
}

int random(int minn, int maxx){
    return minn + rand() % (maxx - minn + 1);
}

void kurumi(){
//    srand((int)time(0));
//
//    m = random(100000,100000);
//    cout << m << '\n';
//    int l = random(0,100000);
//    int r = 100000;
//    cout << l << ' ' << r << '\n';
//    foru(i,2,50000){
//        int l = random(0,30000);
//        int r = random(l,50000);
//        cout << l << ' ' << r << '\n';
//    }
//
//    foru(i,50001,100000){
//        int l = random(30000,100000);
//        int r = random(l,100000);
//        cout << l << ' ' << r << '\n';
//    }
//    n = random(100000,100000);
//    cout << n << '\n';
//
//    foru(i,1,n){
//        int u = random(0,100000);
//        cout << u << ' ';
//    }

    cin >> m;
    foru(i,1,m){
        int u,v;
        cin >> u >> v;
//        g.pb({u,v});
        a[i].fi = u;
        a[i].se = v;
        ma = max(ma, v);
    }

    cin >> n;
    foru(i,1,n){
        cin >> t[i];
        mi = min(mi,t[i]);
    }

    if(ma < 100000){
        cout << -1;
        return;
    }

    int cnt = 0;
    sort(a + 1, a + m + 1, cmp);

//    sort(g.begin(), g.end());

//    while(1){
//        if(mi >= 100000 || g.size() == 0) break;
//        int dd = 0;
//        int vt = -1;
//        int l = -1;
//
//        foru(i,0,g.size() - 1){
//            int u = g[i].fi;
//            int v = g[i].se;
//            if(u <= mi){
//                if(v > mi && v > l){
//                    l = v;
//                    vt = i;
//                    dd = 1;
//                }
//            }
//            else break;
//        }
//
//        if(dd == 0){
//            break;
//        }
//        else{
//            mi = l;
//            cnt++;
//            g.erase(g.begin(), g.begin() + vt + 1);
//        }
//    }

    int i = 1;
    int l = mi;

    while(i <= m){
        if(mi >= 100000 || i > m) break;
        int dd = 0;
        int vt = -1;

        while(a[i].fi <= mi && i <= m){
            l = max(l,a[i].se);
            i++;
            dd++;
        }

        if(dd == 0){
            break;
        }
        else{
            mi = l;
            cnt++;
        }
    }

    if(mi >= 100000) cout << cnt << '\n';
    else cout << -1 << '\n';
}

Lelouch
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen(Kurumi".inp","r",stdin);
    freopen(Kurumi".out","w",stdout);
    kurumi();
    return 0;
}
