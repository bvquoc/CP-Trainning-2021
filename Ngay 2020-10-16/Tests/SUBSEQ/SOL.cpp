//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "election"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int  n, s = 0, tr[maxn], res;
pii a[1003];

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].F, a[i].S = i, s+= a[i].F;
    sort(a+1, a+n+1, greater<pii>());
    tr[0] = -1;
    int ns = s/2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= a[i].F; j--)
            if (tr[j] == 0 && tr[j-a[i].F] != 0)
            {
                tr[j] = i;
                if (j > ns && j-a[i].F <= ns) res = max(res, j);
            }
    }
    vector <int> ans;
    while (res)
    {
        ans.PB(a[tr[res]].S);
        res -= a[tr[res]].F;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}

