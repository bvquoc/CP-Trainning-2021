//DinoFromMar
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define fi first
#define se second
#define Task "FIXSTR"
#define maxn 1000005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long

using namespace std;

int n, m;
string s;
int tt[1003][1003];

struct po
{
    int val, m, d;
}t[4*maxn];

struct query
{
    char ty;
    int  x, y, id;
}Q[maxn];

vector<int> vt[maxn];
pii ans[maxn];

void sub1()
{
    for(int j = 1; j <= n; j++)
        if(s[j-1] == '(')tt[0][j] = 1;
    else tt[0][j] = -1;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            tt[i][j] = tt[i-1][j];
        char type;
        cin >> type;
        if(type == 'C')
        {
            int x;
            cin >> x;
            tt[i][x] = -tt[i][x];
        }
        if(type == 'Q')
        {
            int l, r;
            cin >> l >> r;
            int sum = 0, res = 0;
            for(int j = l; j <= r; j++)
                {
                    sum += tt[i][j];
                    if(sum < 0) res ++, sum ++;
                }
            cout << sum + res << "\n";
        }
        if(type == 'U')
        {
            int x;
             cin >> x;
             for(int j = 1; j <= n; j++)
                tt[i][j] = tt[x-1][j];
        }
    }
}

void init(int k, int l, int r)
{
    if(l == r)
    {
        if(s[l - 1] == '(')
        {
            t[k].val = 1;
            t[k].m = 1;
        }
        else{
            t[k].val = 1;
            t[k].d = 1;
        }
        return ;
    }
    int mid = (l + r)/2;
    init(k*2 , l , mid);
    init(k*2 + 1, mid + 1, r);
    t[k].val = t[k*2].val + t[k*2 + 1].val - 2*min(t[k*2].m , t[k*2 + 1].d);
    t[k].m = t[k*2].m + t[k*2 + 1].m - min(t[k*2].m , t[k*2 + 1].d);
    t[k].d = t[k*2].d + t[k*2 + 1].d - min(t[k*2].m , t[k*2 + 1].d);
}

void up(int k, int l, int r, int u)
{
    if(l > u || r < u)return ;
    if(l == r && r == u)
    {
        t[k].d = abs(t[k].d - 1);
        t[k].m = abs(t[k].m - 1);
        return ;
    }
    int mid = (l + r)/2;
    up(k*2 , l , mid, u);
    up(k*2 + 1, mid + 1, r, u);
    t[k].val = t[k*2].val + t[k*2 + 1].val - 2*min(t[k*2].m , t[k*2 + 1].d);
    t[k].m = t[k*2].m + t[k*2 + 1].m - min(t[k*2].m , t[k*2 + 1].d);
    t[k].d = t[k*2].d + t[k*2 + 1].d - min(t[k*2].m , t[k*2 + 1].d);
}


po get(int k, int l, int r, int u, int v)
{
    if(l > v || r < u)return t[0];
    if(l >= u && r <= v)
    {
        return t[k];
    }
    int mid = (l + r)/2;
    po A = get(k*2 , l , mid, u, v);
    po B = get(k*2 + 1, mid + 1, r, u, v);
    po C;
    C.val = A.val + B.val - 2*min(A.m , B.d);
    C.m = A.m + B.m - min(A.m , B.d);
    C.d = A.d + B.d - min(A.m , B.d);
    return C;
}

int cnt;

void sol(int u)
{
    int dem = 0;
    for(int i = u; i <= m; i++)
    {
        if(Q[i].ty == 'U')dem ++;
        if(dem == 2)break;
        if(Q[i].ty == 'C')up(1, 1, n, Q[i].x);
        if(Q[i].ty == 'Q')ans[++cnt] = {Q[i].id, get(1, 1, n, Q[i].x , Q[i].y).val};
        for(int p : vt[i])
            sol(p);
    }
    for(int i = u + 1; i <= m; i++)
        {
        if(Q[i].ty == 'U')break;
        if(Q[i].ty == 'C')up(1, 1, n, Q[i].x);
    }

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    cin >> s;
    cin >> m;
    n = s.length();
    if(n <= 1000 && m <= 1000){
            sub1();
            return 0;
    }
    init(1 , 1, n);
    for(int i = 1; i <= m; i++)
    {
        cin >> Q[i].ty;
        if(Q[i].ty == 'Q')
            cin >> Q[i].x >> Q[i].y, Q[i].id = i;
        else cin >> Q[i].x;
        if(Q[i].ty == 'U')
            vt[Q[i].x - 1].PB(i);

    }
    for(int p : vt[0])
        sol(p);
    for(int i = 1; i <= m; i++)
    {
        if(Q[i].ty == 'U')break;
        if(Q[i].ty == 'C')up(1, 1, n, Q[i].x);
        if(Q[i].ty == 'Q')ans[++cnt] = {Q[i].id, get(1, 1, n, Q[i].x , Q[i].y).val};
        for(int p : vt[i])
        sol(p);
    }

    sort(ans + 1, ans + 1 + cnt);
    for(int i = 1; i <= cnt; i++)
        cout << ans[i].se << "\n";

   return 0;
}
