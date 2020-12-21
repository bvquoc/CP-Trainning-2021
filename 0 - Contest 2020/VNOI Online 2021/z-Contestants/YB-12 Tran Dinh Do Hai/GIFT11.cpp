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
#define Kurumi "GIFT11"
#define nmax 2005

const ll OO = 1e15+7 ;
const ll mod = 1e9+7;
using namespace std;

int T,cnt = 0;
string s[nmax];
int h[nmax],x[nmax];

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

void check(int N){
//    foru(i,1,N){
//        cout << s[h[i]] << ' ';
//    }
//    cout << '\n';
    string LL = "";
    foru(i,1,N){
        LL += s[h[i]];
    }

    int dd = 0;
    foru(i,0,LL.size() - 1){
        if(i % 2 == 1){
            dd += (LL[i] - '0');
        }
        else dd -= (LL[i] - '0');
    }
//    cout << dd << '\n';
    if(dd % 11 == 0){
//        cout << LL << '\n';
        cnt++;
        cnt %= mod;
    }
//    cout << LL << '\n';
}

void _s(int i, int N){
    foru(j,1,N){
        h[i] = j;
        if(x[j] == 0){
            x[j] = 1;
            if(i == N) check(N);
            else _s(i + 1,N);
            x[j] = 0;
        }
    }
}

ll gt(ll n){
    ll s = 1;
    foru(i,1,n){
        s *= i;
        s %+ mod;
    }

    return s;
}
void kurumi(){
    cin >> T;
    while(T--){
        int n;
        cin >> n;
//        reset(x);
        cnt = 0;
        foru(i,1,n){
            cin >> s[i];
        }

        if(n <= 9){
            _s(1,n);
        }
        else{
            string LL = "";
            foru(i,1,n){
                LL += s[i];
            }

            int dd = 0;
            foru(i,0,LL.size() - 1){
                if(i % 2 == 1){
                    dd += (LL[i] - '0');
                }
                else dd -= (LL[i] - '0');
            }
            if(dd % 11 == 0){
                cnt = gt(n);
            }
        }

        cout << cnt << '\n';
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
