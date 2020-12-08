//Tran Thuy Duong
#include <bits/stdc++.h>
#define maxn 1000006
#define maxc 1000000009
#define MOD 1000000007
#define task "PAINT"
#define reset(x) memset(x, 0, sizeof x)
#define remain(x) ((x >= MOD) ? (x-MOD) : x)
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;

int n;
char a[maxn];
void Sub1()
{
    int cnt = 0, type;
    char x, y;
    for (int i=1; i<=n; i++)
    {
        cin >> type >> x;
        if (type == 1) a[++cnt] = x;
        else
        {
            cin >> y;
            for (int j=1; j<=cnt; j++)
                if (a[j] == x) a[j] = y;
        }
    }
    for (int i=1; i<=cnt; i++) cout << a[i];
}
int root[maxn], luu[27];
int get_root(int u) {return (root[u] > 0 ? root[u] = get_root(root[u]) : u);}
void Add(int pos, char x)
{
    a[pos] = x;
    int p = luu[x - 'a'];
    if (p == 0)
        {luu[x - 'a'] = pos; root[pos] = - (x - 'a' + 1);}
    else
        root[pos] = p;
}
void Change(char x, char y)
{
    int px = luu[x - 'a'];
    int py = luu[y - 'a'];
    if (px == py) return;
    if (px == 0) return;
    if (py == 0)
    {
        luu[y - 'a'] = px;
        luu[x - 'a'] = 0;
        root[px] = - (y - 'a' + 1);
        return;
    }
    luu[x - 'a'] = 0;
    root[px] = py;
}
void Sub2()
{
    int cnt = 0, type;
    char x, y;
    for (int i=1; i<=n; i++)
    {
        cin >> type >> x;
        if (type == 1) ++cnt, Add(cnt, x);
        else
        {
            cin >> y;
            Change(x, y);
        }
    }
    for (int i=1; i<=cnt; i++)
    {
        int p = get_root(i);
        cout << (char) (-root[p] + 'a' - 1);
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(task".INP", "r", stdin);
	freopen(task".OUT", "w", stdout);
    cin >> n;
    if (n <= 1e4) Sub1();
    else
        Sub2();
	return 0;
}
