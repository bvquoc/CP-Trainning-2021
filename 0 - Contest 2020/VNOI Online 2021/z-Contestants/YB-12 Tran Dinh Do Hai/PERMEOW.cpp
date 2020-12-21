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
#define Kurumi "PERMEOW"
#define nmax 200005
#define mmax 2000005
const ll OO = 1e15+7 ;
const ll mod = 1e9+7;
using namespace std;

int n,a[nmax],b[nmax];
int Bit[nmax];
int f[nmax],g[nmax];

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

void update(int u){
    for(; u > 0; u -= u & (-u)){
        Bit[u]++;
        Bit[u] %= mod;
    }
}

int get(int u){
    int T = 0;
    for(; u <= n; u += u & (-u)){
        T += Bit[u];
        T %= mod;
    }
    return T;
}

void sub1(){
    int CC = 0;
    foru(i,1,n){
        CC += get(a[i] + 1);
        update(a[i]);
        CC %= mod;
    }

    cout << CC << '\n';
}

void sub2(){
    f[0] = 1;
    g[0] = 1;
    int N = n * (n - 1) / 2;

    foru(i,2,n){
        int ii = i * (i - 1) / 2;
        g[0] = g[ii] = 1;
        f[0] = 1;

//        foru(j,0,ii / 2){
//            cout << f[j] << ' ';
//        }
//        cout << '\n';

        foru(j,1,ii / 2){
            if(j - i >= 0){
//                cout << f[j] << ' ' << f[j - (ii / 2)] << '\n';
                g[j] = f[j] - f[j - i];
            }
            else g[j] = f[j];
            g[ii - j] = g[j];
        }

        foru(j,1,ii){
            f[j] = g[j] + f[j - 1];
            f[j] %= mod;
        }

//        foru(j,0,ii){
//            cout << g[j] << ' ';
//        }
//        cout << '\n';
    }

    int LL = 0;

//    foru(i,0,N){
//        cout << g[i] << ' ';
//    }
//    cout << '\n';

    foru(i,0,N){
        LL = (LL + i * g[i]) % mod;
    }

    cout << LL << '\n';

}

void kurumi(){
    cin >> n;
    foru(i,1,n){
        cin >> a[i];
    }

    foru(i,1,n){
        cin >> b[i];
    }

    int kt = 0;

    foru(i,1,n){
        if(a[i] != b[i]){
            kt = 1;
            break;
        }
    }

    if(kt == 0){
        sub1();
        return;
    }

    sub2();
}

Lelouch
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen(Kurumi".inp","r",stdin);
    freopen(Kurumi".out","w",stdout);
    kurumi();
    return 0;
}
