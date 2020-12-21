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
#define PROB "DECOR"
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

const int N = 5e5 + 2;
int n, m, k, s[N], par[N], in[N], ra[N];
bool ok[N]{0};
string c;
pii e[N];

void readinp(){
    cin >> n >> m >> k;
    cin >> c; c = ' ' + c;
    FU(i, 1, m) cin >> e[i].fi >> e[i].se;
}

void sub1(){
    if (m > 0 || k > 0) return;
    int res = 0, l = 0, r = 0;
    int j = 1;
    while (j <= n){
        if (c[j] == '0') {
            j++;
            continue;
        }
        int i = j;
        while (i <= n && c[i] == '1') i++; i--;
        if (i - j + 1 > res){
                l = j, r = i;
                res = i - j + 1;
            }
            else if (i - j + 1 == res && j < l){
                l = j, r = i;
            }
        j = i + 1;
    }
    if (res != 0)
    cout << l << ' ' << r;
    else cout << -1;
    exit(0);
}

void sub2(){
    if (m > 0) return;
    int res = 0;
    int i = 1;
    int cnt = 0;
    int j = 1;
    int l = 0, r = 0;
    while (i <= n){
        cnt+= (c[i] == '0');
        while (j < i && cnt > k){
            cnt-= (c[j] == '0');
            j++;
        }
        if (j <= i && cnt <= k){
            if (i - j + 1 > res){
                l = j, r = i;
                res = i - j + 1;
            }
            else if (i - j + 1 == res && j < l){
                l = j, r = i;
            }
        }
        i++;
    }
    if (res != 0)
    cout << l << ' ' << r;
    else cout << -1;
    exit(0);
}

int root (int u){
    return (par[u] < 0 ? u : par[u] = root(par[u]));
}

bool unionn(int u, int v){
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (-par[u] < -par[v]) swap(u, v);
    par[u]+= par[v];
    par[v] = u;
    return true;
}

void solve(){
    FU(i, 1, n) s[i] = s[i-1] + (c[i] == '1');

    sub1();
    sub2();

    FU(i, 1, n) par[i] = -1;
    FU(i, 1, m) unionn(e[i].fi, e[i].se);
    FU(i, 1, n) in[root(i)]+= (c[i] == '1');

    int res = 0, l = 0, r = 0;
    int i = 1, j = 1;
    int cnt = 0;
    while (i <= n){
        int p = root(i);
        ra[p]++;
        if (in[p])
            cnt++, in[p]--, ok[i] = true;

        while (j < i && cnt + k < i - j + 1){
            int pj = root(j);
            ra[pj]--;
            if (ok[j] && !ra[pj])
                cnt--, in[pj]++;
            j++;
        }
        if (j <= i && cnt + k >= i - j + 1){
            int len = i - j + 1;
            if (len > res) res = len, l = j, r = i;
            else if (len == res && j < l) l = j, r = i;
        }
        i++;
    }
    if (res != 0)
    cout << l << ' ' << r;
    else cout << -1;
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
