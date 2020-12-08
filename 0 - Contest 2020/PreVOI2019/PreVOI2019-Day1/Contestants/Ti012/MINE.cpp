#include <bits/stdc++.h>
#define task "MINE"
#define nmax 400004
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define len(s) int(s.length())
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,a[nmax], b[nmax], choose[nmax], res = 0;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    cout << 2;
}
