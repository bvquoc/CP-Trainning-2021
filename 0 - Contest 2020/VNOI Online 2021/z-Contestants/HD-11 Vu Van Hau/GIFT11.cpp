#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
#define N 500005
#define x first
#define y second
#define ii pair <int, int>
#define iii pair <int, ii>
#define mode (int) 998244353
#define inf (ll) 2e18

using namespace std;

int n, ans = 0;
int a[N], p[N];
int gt[N];

vector <int> get(int val)
{
    vector <int> dg;
    if(val == 0)
        dg.push_back(val);
    while(val)
    {
        dg.push_back(val % 10);
        val /= 10;
    }
    reverse(dg.begin(), dg.end());
    return dg;
}

void prepare()
{
    int M = N - 5;
    gt[0] = 1;
    FOR(i, 1, M)
    gt[i] = (1ll * gt[i - 1] * i) % mode;
}

bool ok()
{
    FOR(i, 1, n)
    {
        vector <int> dg = get(a[i]);
        if(dg.size() & 1) return false;
    }
    return true;
}

void xuli()
{
    int sum = 0;
    int id = 1;
    FOR(i, 1, n)
    {
        vector <int> dg = get(a[p[i]]);
        for(auto &v : dg)
        {
            id++;
            if(id & 1) sum = (sum + v) % 11;
            else sum = (sum - v + 11) % 11;
        }
    }
    if(sum % 11 == 0)
        ans = (ans + 1) % mode;
}

void sub1()
{
    ans = 0;
    FOR(i, 1, n)
    p[i] = i;
    do
    {
        xuli();
    }
    while(next_permutation(p + 1, p + n + 1));
    printf("%d\n", ans);
}

void sub2()
{
    int sum = 0, id = 0;
    FOR(i, 1, n)
    {
        vector <int> dg = get(a[i]);
        if(dg.size() & 1) return;
        for(auto &v : dg)
        {
            id++;
            if(id & 1) sum = (sum + v) % 11;
            else sum = (sum - v + 11) % 11;
        }
    }
    if(sum % 11 == 0)
        printf("%d\n", gt[n]);
    else printf("%d\n", 0);
}

void sub3()
{

}

void solve()
{
    scanf("%d ", &n);
    FOR(i, 1, n)
    scanf("%d ", &a[i]);
}

int main()
{
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    int t;
    scanf("%d ", &t);
    prepare();
    while(t--)
        solve();
}
