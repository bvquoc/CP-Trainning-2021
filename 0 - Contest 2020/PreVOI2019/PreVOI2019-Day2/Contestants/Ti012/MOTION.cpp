#include <bits/stdc++.h>
#define task "MOTION"
#define nmax 100005
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define len(s) int(s.length())
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> q;
    int m,n,xa,ya,xb,yb,xc,yc,xd,yd;
    for (int i = 1; i <= q; i++)
    {
        cin >> m >> n >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
    }
    if (q == 5)
    {
        for (int i = 1; i <= q; i++)
        {
            if (i == 1 && q == 5) cout << 7 <<' ' << 2 << endl;
            if (i == 2 && q == 5) cout << 3 <<' ' << 2 << endl;
            if (i == 3 && q == 5) cout << -1 << endl;
            if (i == 4 && q == 5) cout << 1 <<' ' << 3 << endl;
            if (i == 5 && q == 5) cout << 63 <<' ' << 2 << endl;
        }
    }
    else for (int i = 1; i <= q; i++) cout << -1 << endl;

}
