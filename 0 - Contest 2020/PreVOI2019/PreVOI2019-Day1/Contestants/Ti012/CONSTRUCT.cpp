#include <bits/stdc++.h>
#define task "CONSTRUCT"
#define nmax 100005
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define len(s) int(s.length())
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int T, m, n, a[nmax], s[nmax];
ll res[nmax];

void check()
{
    for (int i = 1; i <= n; i++)
        cout << a[i] <<' ';
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << s[i] <<' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] > a[i - 1]) s[i] = a[i] - a[i-1];
            else s[i] = 0;
        }
        for (int i = 1; i <= n; i++)
            res[i] = res[i - 1] + s[i];
        //check();

        int type, l, r, k;
        for (int i = 1; i <= m; i++)
        {
            cin >> type >> l >> r;
            if (type == 2)
                cout << res[r] - res[l] + a[l] << endl;
            else
            {
                cin >> k;
                for (int i = l; i <= r; i++) a[i] += k;
                for (int i = 1; i <= n; i++){
                    if (a[i] > a[i-1]) s[i] = a[i] - a[i-1];
                    else s[i] = 0;
                    res[i] = res[i-1] + s[i];
                }
                //check();
            }
        }
    }
}
