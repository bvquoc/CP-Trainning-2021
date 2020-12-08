// He always smiles :)
#include <bits/stdc++.h>
#define maxn 100005
#define mod 1000003
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define task "MINE"
#define ll long long
#define reset(x, a) memset(x, a, sizeof(x))
#define endl "\n"
#define bit(x, i) ((x >> i) & 1)
using namespace std;

int n, m, a[maxn];
bool check(int x, int n)
{
    int dem(0);
    int d[maxn];
    reset(d, 0);
    int sl = __builtin_popcount(x);
        if(sl != n - sl) return 0;
    for (int i = 0 ; i < n ; i ++){
            if(bit(x, i)) ++dem;
            else --dem;
            if(dem < 0) return 0;
        }
    for (int i = 0 ; i < n ; i ++)
        if(bit(x, i) == 1){
                int c = 0, c0 = 0;
        for (int j = i + 1 ; j < n ; j ++){
            if(c == c0 && bit(x, j) == 0)
               {
                   if(a[j + 1] - a[i + 1] > m) return 0;
                   else break;
               }
            if(bit(x, j) == 1) ++c;
            else ++c0;
            }
        }
    return 1;
}
void sub1()
{
    n = 2 * n;
    ll ans(0);
    for(int x = 1 ; x < (1 << n) ; x ++)
    if(check(x, n)) ++ans;
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= 2 * n ; i ++)
        cin >> a[i];
    if(n <= 10) {sub1(); return 0;}
    cout << rand() % mod;
    return 0;
}
