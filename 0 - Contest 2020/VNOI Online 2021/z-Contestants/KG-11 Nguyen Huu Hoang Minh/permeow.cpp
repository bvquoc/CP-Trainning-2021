#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 200005
#define remain(x) if (x > MOD) x -= MOD
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< ii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "PERMEOW"
#define int long long

using namespace std;
const int Mod = 1e9+7;

int n, a[N], b[N];
int bit[N];
int res = 0;
int dis = 0;

typedef long double ld;

int get(int x) {
  int ans = 0;
  for(; x < N; x+=x&-x) ans += bit[x];
    return ans;
}

void update(int x) {
  for (; x>0;  x-=x&-x) bit[x]++;
}

void check(int &ans)
{
    dis++;
    reset(bit);
    for(int i=1; i<=n; i++)
    {
        ans += get(a[i]+1);
        res += get(a[i]+1);
        update(a[i]);
    }
}

void readfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen(Task".inp","r"))
    {
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
}

void proc()
{
    bool ok = false;
    do{
        if (equal(a+1,a+1+n,b+1,b+1+n)) ok = true;
        int ans = 0;
        check(ans);
    } while (next_permutation(a+1,a+1+n) && !ok);
    cout << res;
}

signed main()
{
    readfile();
    proc();
    return 0;
}
