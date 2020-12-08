#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define reset(x) memset(x, 0, sizeof x)
#define MIN(x,y) {if (x > (y)) x = (y);}
#define MAX(x,y) {if (x < (y)) x = (y);}
#define remain(x) while (x >= MOD) x -= MOD
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 1000010
#define maxC INT_MAX
#define MOD 1000000007
#define ll long long
#define pii pair <int, int>
#define task "FIXSTR"

using namespace std;

int m, n;
string s, a[maxn];

void rev(char &c)
{
    if (c == ')') c = '(';
    else c = ')';
}

void sub1()
{
    a[0] = s;
    cin >> m;
    FOR(i, 1, m)
    {
        char type;
        cin >> type;
        if (type == 'C') {int x; cin >> x; rev(s[x]);}
        else if (type == 'U') {int x; cin >> x; s = a[x-1];}
        else
        {
            int u, v, res = 0, dem = 0;
            cin >> u >> v;
            FOR(j, u, v)
            {
                if (s[j] == '(') dem++;
                else if (s[j] == ')')
                {
                    if (dem) dem--;
                    else res++;
                }
            }
            cout << res + dem << "\n";
        }
        a[i] = s;
    }
}
struct data {char type; int u, v;} Q[maxn];
struct BIT
{
    int t[maxn];
    void update(int x, int sign){
        if (x <= 0) return;
        for (; x<=n; x += x&-x) t[x] += sign;}
    int get(int x){
        if (x <= 0) return 0;
        int res = 0;
        for (; x; x -= x &-x) res += t[x];
        return res;
    }
} val[2];
int dau[4*maxn], cuoi[4*maxn], id[maxn];
void init(int node, int l, int r)
{
    if (l == r)
    {
        dau[node] = (s[l] == '1' ? l : MOD);
        cuoi[node] = (s[l] == '0' ? l : 0);
        id[l] = node; return;
    }
    int mid = (r + l) >> 1;
    init(node * 2, l, mid); init(node * 2 + 1, mid + 1, r);
    dau[node] = min(dau[node * 2], dau[node * 2 + 1]);
    cuoi[node] = max(cuoi[node * 2], cuoi[node * 2 + 1]);
}
void Change(int pos)
{
    int x = id[pos];
    cuoi[x] = (s[pos] == '0' ? 0 : pos);
    dau[x] = (s[pos] == '1' ? MOD : pos);
    x /= 2;
    while (x)
    {
        cuoi[x] = max(cuoi[x * 2], cuoi[x * 2 + 1]);
        dau[x] = min(dau[x * 2], dau[x * 2 + 1]);
        x /= 2;
    }
}
pii get_pos(int node, int l, int r, int u, int v)
{
    if (r < u || v < l) return {MOD, 0};
    if (u <= l && r <= v) return {dau[node], cuoi[node]};
    int mid = (r + l) >> 1;
    pii trai = get_pos(node * 2, l, mid, u, v);
    pii phai = get_pos(node * 2 + 1, mid + 1, r, u, v);
    return {min(trai.F, phai.F), max(trai.S, phai.S)};
}
void Update(int u)
{
    Change(u);
    int then = s[u] - '0';
    int now = then ^ 1;
    s[u] = (char) (now + '0');
    val[then].update(u, -1);
    val[now].update(u, 1);
}
int Get(int u, int v)
{
    pii x = get_pos(1, 1, n, u, v);
    int mo = min(x.F, v);
    int dong = max(x.S, u-1);
    int res1 = val[0].get(mo) - val[0].get(u-1);
    int res2 = val[1].get(v) - val[1].get(dong);
    int mm = val[1].get(dong) - val[1].get(mo - 1);
    int dd = val[0].get(dong) - val[0].get(mo - 1);
    return res1 + res2 + abs(mm - dd);
}

void sub2()
{
    cin >> m;
    char type; int u, v;
    for (int i=1; i<=m; i++)
    {
        cin >> type >> u;
        if (type == 'Q') {cin >> v; Q[i] = {type, u, v};}
        else Q[i] = {type, u, 0};
    }
    for (int i=1; i<=n; i++) if (s[i] == '(') s[i] = '1'; else s[i] = '0';
    init(1, 1, n);
    for (int i=1; i<=n; i++) val[s[i] - '0'].update(i, 1);
    for (int i=1; i<=m; i++)
    {
        char type = Q[i].type;
        if (type == 'C') Update(Q[i].u);
        if (type == 'Q') cout << Get(Q[i].u, Q[i].v) << "\n";
    }
}

int main()
{
    ios_base:: sync_with_stdio(NULL);
    cin. tie(NULL) ; cout. tie(NULL);
    freopen(task".INP" , "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = " " + s;
    if (n <= 1000 && m <= 1000) sub1();
    else sub2();
    return 0;
}
