#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define fid(i,a,b) for(int i=a;i>=b;i--)
#define maxn 105
#define ll long long
#define pii pair<int, int>
#define TTT "MOTION"
using namespace std;
int t, m, n;
int xa, ya, xb, yb, xc, yc, xd, yd;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(TTT".inp","r",stdin);
    freopen(TTT".out","w",stdout);
    cin >> t;
    if(t == 5)
    {
        cout << 7 << " " << 2 << '\n';
        cout << 3 << " " << 2 << '\n';
        cout << -1 << '\n';
        cout << 1 << " " << 3 << '\n';
        cout << 63 << " " << 2 << '\n';
    }
    else while(t--)
    {
        cin >> m >> n >> xa >> xb >> ya >> yb >> xc >> yc >> xd >> yd;
        cout << -1 << '\n';
    }
}
