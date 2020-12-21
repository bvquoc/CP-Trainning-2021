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
#define offbit(x,i) (x&(~(1<<i)))
#define cntone(x) __builtin_popcount(x)
#define mask(i) (1<<i)
#define pb push_back
#define mp make_pair
#define taskname "gift11"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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

const int base = 998244353;
const int N = 2003;
int n;
int a[N];
int sz[N];
int Pow10[10];
ll fac[2 * N];
bool odd, even;
int sizeOfNum(int n){
    int res = 0;
    while(n){
        res++;
        n /= 10;
    }
    return res;
}
void init(){
    Pow10[0] = 1;
    fac[0] = 1;
    FOR(i, 1, 9) Pow10[i] = Pow10[i - 1] * 10;
    FFOR(i, 1, 2 * N) {
        fac[i] = (fac[i - 1] * i) % base;
    }
}
void input(){
    read(n);
    int s = 0;
    odd = 0, even = 0;
    FOR(i, 1, n) {
        read(a[i]);
        sz[i] = sizeOfNum(a[i]);
        if(sz[i] % 2) odd = 1;
        else even = 1;
    }
}
bool used[11];
int res = 0;
void Try(int i, int mod){
    if(i == n + 1 && mod == 0) {
        res++;
        return;
    }
    FOR(j, 1, n) if(!used[j]){
        used[j] = 1;
        int new_mod = (1LL * mod * Pow10[sz[j]] + a[j]) % 11;
        Try(i + 1, new_mod);
        used[j] = 0;
    }
}
void sub1(){
    res = 0;
    Try(1, 0);
    writeln(res);
}
vector<int> num[2];
ll dp[N][11][2];
ll temp[N][11];
int sum[N][2]; ///odd - even
void calc(int id){
    int len = num[id].size();
    dp[0][0][id] = 1;
    for(auto x : num[id]){
        FOR(i, 0, len) FOR(j, 0, 10) temp[i][j] = 0;
        FOR(i, 0, len){
            FOR(j, 0, 10){
                temp[i][(j + x) % 11] = (temp[i][(j + x) % 11] + dp[i][j][id]) % base;
                temp[i + 1][(j - x + 11) % 11] = (temp[i + 1][(j - x + 11) % 11] + dp[i][j][id]) % base;
            }
        }
        FOR(i, 0, len) FOR(j, 0, 10) dp[i][j][id] = temp[i][j];
    }
}
void sub4(){
    num[0].clear();
    num[1].clear();
    FOR(i, 1, n){
        num[sz[i] % 2].pb(a[i] % 11);///dif between odd and even
    }
    FOR(i, 0, 2000) FOR(j, 0, 10) FOR(k, 0, 1) dp[i][j][k] = 0;
    calc(0); calc(1);
    int len1 = num[1].size() / 2;
    int len2 = num[1].size() - len1;
    ll res = 0;
    FOR(i, 0, 10) FOR(j, 0, num[0].size()){
        ll tmp = (dp[len1][i][1] * dp[j][(11 - i) % 11][0]) % base;
        int d1 = j, d0 = num[0].size() - j;
        ll v0 = fac[len2 + d0];
        if(len1 != len2) v0 = (fac[len2 + d0 - 1] * len2) % base;
        ll v1 = fac[len1 + d1];
        if(len1 == len2) v1 = (fac[len1 + d1 - 1] * len1) % base;
        tmp = (tmp * v0) % base;
        tmp = (tmp * v1) % base;
        res = (res + tmp);
        if(res >= base) res -= base;
    }
    writeln(res);
}
void solve(){
    if(n <= 9){ ///sub1
        sub1();
        return;
    }
    if(even && !odd){ ///sub2
        bug(even);
        int cur = 0;
        FOR(i, 1, n){
            int tmp = a[i];
            int flag = 0;
            while(tmp){
                if(flag) cur += tmp % 10;
                else cur -= tmp % 10;
                tmp /= 10;
                flag = 1 - flag;
            }
        }
        if(cur == 0)writeln(fac[n]);
        else writeln(0);
        return;
    }
    sub4();
}
int main()
{
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    init();
    int test;
    read(test);
    while(test--){
        input();
        solve();
    }
    return 0;
}
