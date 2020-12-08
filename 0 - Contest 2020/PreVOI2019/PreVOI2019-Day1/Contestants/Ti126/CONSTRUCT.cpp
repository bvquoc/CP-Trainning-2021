#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
const int maxn = 1e5 + 5;
int T;
int n, m;
lli a[maxn];
bool in[maxn];

int to[maxn];
stack<int> stck;

void ReadInput()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

lli Work(int L, int R)
{
    lli res = 0;
    res = a[L];
    for(int i = L + 1; i <= R; ++i)
        if(a[i] > a[i - 1])
            res += a[i] - a[i - 1];
    return res;
}

void Solve()
{
    for(; m > 0; --m)
    {
        int type, L, R, k;
        cin >> type >> L >> R;
        if(type == 1)
        {
            cin >> k;
            for(int i = L; i <= R; ++i)
                a[i] += (lli)k;
        }
        else cout << Work(L, R) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CONSTRUCT.inp", "r", stdin);
    freopen("CONSTRUCT.out", "w", stdout);
    cin >> T;
    while(T-- > 0)
    {
        ReadInput();
        Solve();
    }
}
