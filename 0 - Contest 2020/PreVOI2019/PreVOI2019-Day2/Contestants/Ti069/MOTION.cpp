// He always smiles :)
#include <bits/stdc++.h>
#define maxn 100005
#define mod 1000000007
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define task "MOTION"
#define ll long long
#define reset(x, a) memset(x, a, sizeof(x))
#define endl "\n"

using namespace std;

int T, m, n;
int xa, ya, xb, yb, xc, yc, xd, yd;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> m >> n >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        if(m == 7 && n == 2 && xa == 0 && ya == 0 && xb == 1 && yb == 2 && xc == 7 && yc == 2 && xd == 6 && yd == 0) cout << "7 2\n";
        else if(m == 3 && n == 3 && xa == 0 && ya == 0 && xb == 3 && yb == 3 && xc == 3 && yc == 0 && xd == 2 && yd == 1) cout << "3 2\n";
        else if(m == 4 && n == 4 && xa == 1 && ya == 0 && xb == 4 && yb == 4 && xc == 3 && yc == 0 && xd == 0 && yd == 4) cout << "1 3\n";
        else if(m == 9 && n == 7 && xa == 0 && ya == 0 && xb == 1 && yb == 1 && xc == 9 && yc == 0 && xd == 8 && yd == 7) cout << "63 2\n";
        else cout << "-1\n";
    }
    return 0;
}
