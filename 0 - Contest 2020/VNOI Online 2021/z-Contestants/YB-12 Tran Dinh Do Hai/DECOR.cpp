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
#define Kurumi "DECOR"
#define nmax 500005

const ll OO = 1e15+7 ;
const ll mod = 1e9+7;
using namespace std;

int n,m,k;
Pii a[nmax];
string s;

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

void sub1(){
    int LL = 0;
    int l = 1, r = n;
    s = "0" + s;
    int cnt = 0;

    foru(i,1,n){
        if(s[i] == '1') cnt++;
        else{
            if(cnt > LL){
                r = i - 1;
                l = i - cnt;
                LL = cnt;
            }
            cnt = 0;
        }
    }

    if(cnt > LL){
        LL = cnt;
        r = n;
        l = n - cnt + 1;
    }

    cout << l << ' ' << r << '\n';
}

void kurumi(){
    cin >> n >> m >> k;
    cin >> s;
    foru(i,1,m){
        cin >> a[i].fi >> a[i].se;
    }

    if(m == 0 && k == 0){
        sub1();
        return;
    }
}

Lelouch
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen(Kurumi".inp","r",stdin);
    freopen(Kurumi".out","w",stdout);
    kurumi();
    return 0;
}
