#include <bits/stdc++.h>
#define task "PAINT"
#define nmax 1000006
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define len(s) int(s.length())
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n, pos = 0;
char a[nmax];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n;
    int t;
    char x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> x;
        if (t == 1) a[++pos] = x;
        else
        {
            cin >> y;
            if (x == y) continue;
            for (int j = 1; j <= pos; j++)
                if (a[j] == x) a[j] = y;
        }
    }
    for (int i = 1; i <= pos; i++)
        cout << a[i];
    exit(0);

}
