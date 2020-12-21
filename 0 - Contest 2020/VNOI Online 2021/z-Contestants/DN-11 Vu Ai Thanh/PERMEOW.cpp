/*
    Who the hell you think you are?
    Comin' in to break my heart
    Make it like an operation
    But I ain't one of your patients
    Tired of this waiting and I don't play that game

    I can't get you off my brain
    So I'm poppin pills for the pain
    And as soon as I go wake up
    You're caught up in your haze
    And I can't get out of my bed

    Tears are almost gone but the symptoms in my heart
    So tell me what's the cure for you (tell me now)
    'Cause girl you make me so confused
    (girl you got me so confused)

    You got me feeling like a psycho, psycho
    Got me chasin' shots of NyQuil, NyQuil
    Without you got me dizzy and upset
    Got me so obsessed with you
    Look what you started
    I'm psycho, you're heartless
*/
// peachthuw
#include <bits/stdc++.h>
#define EL cout<<'\n'
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "PERMEOW"
using namespace std;
typedef long long ll;
typedef double db;


template <typename T>
inline void read(T& x){
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}


void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r",stdin);
        freopen(PROB".out", "w",stdout);
    }
}

const int N = 200002;
const ll mod = 1e9 + 7;
int n, a[N], b[N];
int d[N];
ll f[2002][2002];
ll gt[2002];

void readinp(){
    cin >> n;
    FU(i, 1, n) cin >> a[i];
    FU(i, 1, n) cin >> b[i];
}

int cal(){
    FU(i, 1, n) b[i] = a[i];
//    FU(i, 1, n) cout << a[i] << " ";
    int res = 0;
    while (1){
        bool ok = true;
        FU(i, 1, n - 1){
            if (b[i] > b[i+1]){
                swap(b[i], b[i+1]);
                ok = false;
                break;
            }
        }
        if (ok) break;
        else res++;
    }
//    cout << " : " << res << ' ';
    return res;
}

ll go(int c[]){
    int res = 0;
    FU(i, 1, n){
        int cnt = 0;
        FU(j, 1, i - 1) cnt+= (c[j] > c[i]);
        int j = i - cnt;
        res+= abs(c[i] - j);
    }

    return res;
}


ll MOD(ll x){
    if (x >= mod) return x % mod;
    if (x < 0) return (x % mod + mod) % mod;
    return x;
}


void sub1(){
    FU(i, 1, n) if (a[i] != b[i]) return;
    cout << cal();
    exit(0);
}

void sub2(){
    FU(i, 1, n) if (a[i] != i || b[i] != n - i + 1) return;
    gt[0] = 1;
    FU(i ,1 ,n) gt[i] = MOD(gt[i-1] * ll(i));

    f[1][0] = 0;
    FU(i, 1, n + 1){
        ll s = 0;
        FU(j, 1, i - 1) s = MOD(s + f[i-1][j]);
        f[i][1] = s;
        FU(j, 2, i) f[i][j] = MOD(f[i][j-1] + gt[i-1]);
    }
    cout << f[n+1][1];
    exit(0);
}



bool in[N]{0};
ll dp(int c[]){
    ll res = 0;
    FU(i, 1, n) in[i] = false;
    FU(i, 1, n){
        in[c[i]] = true;
        FU(j, 1, c[i]) if (!in[j]) res+= f[n - i + 1][j];
    }
    cout << res,EL;
    return res;
}

void solve(){
    sub1();
    sub2();


}

int main(){
    setIO();
    int t = 1;
//    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}
