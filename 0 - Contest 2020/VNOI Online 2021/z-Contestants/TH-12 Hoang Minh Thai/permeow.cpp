/** Kujoh **/
#include <bits/stdc++.h>
#define fi first
#define se second
#define bug(x) cerr << #x << " = " << x << '\n';
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FFOR(i,a,b) for(int i = a; i < b; i++)
#define DFOR(i,b,a) for(int i = b; i >= a; i--)
#define getbit(x,i) ((x>>i)&1)
#define onbit(x,i) (x(1<<i))
#define offbit(x, i) (x &(~(1<<i)))
#define cntone(x) __builtin_popcount(x)
#define mask(i) (1<<i)
#define pb push_back
#define mp make_pair
#define taskname "permeow"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const ld eps = 1e-9;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {
    if (x > 9) Write(x/10);
    putchar(x%10+48);
}
template <typename T> void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    Write(x);
    putchar(' ');
}
template <typename T> void writeln(T x) {
    write(x);
    putchar('\n');
}

             /** END OF TEMPLATE **/

const ll base = 1e9 + 7;
const int N = 2e5 + 1;
ll Pow(ll x, ll n){
    ll res = 1;
    while(n){
        if(n & 1) res = (res * x) % base;
        x = (x * x) % base;
        n >>= 1;
    }
    return res;
}
ll fac[N];
ll inv[N];
ll C(int n, int k){
    if(k > n) return 0;
    return ((fac[n] * inv[k]) % base * inv[n - k]) % base;
}
int n;
int a[N], b[N];
int ft[N];
void update(int x){
    for(; x <= n; x += x&(-x))
        ft[x]++;
}
int get(int x){
    int res = 0;
    for(; x > 0; x -= x&(-x))
        res += ft[x];
    return res;
}
void sub1(){
    ll res = 0;
    DFOR(i, n, 1){
        res += 1LL * get(a[i]);
        update(a[i]);
    }
    write(res % base);
}
void init(){
    fac[0] = inv[0] = 1;
    FOR(i, 1, n){
        fac[i] = (fac[i - 1] * i) % base;
        inv[i] = Pow(fac[i], base - 2);
    }
}
void sub2(){
    ll res = 0;
    ll tmp = C(n, 2);
    res = (tmp * tmp) % base;
    res = (res * fac[n - 2]) % base;
    write(res);
}
bool taken[11];
int per[N];
int res1, res;
void solve(){
    int tmp = 0;
    FOR(i, 2, n) FFOR(j, 1, i){
        if(per[j] > per[i]) tmp++;
    }
    res += tmp;
    //cout << res << '\n';
    bool ok = 1;
    FOR(i, 1, n) if(per[i] != a[i]) ok = 0;
    if(ok){
        res1 = res - tmp;
    }
    ok = 1;
    FOR(i, 1, n) if(per[i] != b[i]) ok = 0;
    if(ok){
        write(res - res1);
        exit(0);
    }
}
void Try(int i){
    FOR(j, 1, n) if(!taken[j]){
        taken[j] = i;
        per[i] = j;
        if(i == n) solve();
        else Try(i + 1);
        taken[j] = 0;
    }
}
int main(){
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) read(b[i]);
    if(n == 1){
        write(0);
        return 0;
    }
    bool ok = 1;
    FOR(i, 1, n) if(a[i] != b[i]) ok = 0;
    if(ok){
        sub1();
        return 0;
    }
    init();
    ok = 1;
    FOR(i, 1, n){
        if(a[i] != i || b[i] != n - i + 1) ok = 0;
    }
    if(ok){
        sub2();
        return 0;
    }
    Try(1);
    return 0;
}
