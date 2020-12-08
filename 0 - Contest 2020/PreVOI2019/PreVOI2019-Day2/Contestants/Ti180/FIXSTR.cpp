// Nguyen Anh Tu
#include <bits/stdc++.h>
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define FORD(x,a,b) for(int x=a;x>=b;x--)
#define maxn 1000005
#define maxc 1000000007
#define MOD 1000000007
#define reset(x,y) memset(x,y,sizeof(x))
#define task "FIXSTR"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
#define remain(a,b) (a+b >= MOD) ? (a+b - MOD) : (a+b)

using namespace std;
int n,m;
ll sum[maxn];
string s;
int f[4 * maxn];
ll t[maxn];
int lazy[4 * maxn];
void init(int k, int l, int r)
{
    if(l == r)
    {
        f[k] = sum[l];
        return;
    }
    int mid = (l+r)/2;
    init(k*2,l,mid);
    init(k*2+1,mid+1,r);
    f[k] = min(f[k*2], f[k*2+1]);
}
void dolazy(int k, int l, int r) {
	if (lazy[k] == 0) return;
	f[k] += lazy[k];
	if (l != r) {
		lazy[k * 2] += lazy[k];
		lazy[k * 2 + 1] += lazy[k];
	}
	lazy[k] = 0;
}
void update(int k, int l, int r, int L, int R, int val) {
	dolazy(k, l, r);
	if (r < L || R < l) return;
	if (L <= l && r <= R) {
		f[k] += val;
		if (l != r) {
			lazy[k * 2] += val;
			lazy[k * 2 + 1] += val;
		}
		return;
	}
	int mid = (l + r) / 2;
	update(k * 2, l, mid, L, R, val); update(k * 2 + 1, mid +
                                          1, r, L, R, val);
	f[k] = min(f[k * 2], f[k * 2 + 1]);
}
int get(int k, int l, int r, int L, int R) {
	dolazy(k, l, r);
	if (r < L || R < l) return 1e18;
	if (L <= l && r <= R) return f[k];
	int mid = (l + r) / 2;
	return min(get(k * 2, l, mid, L, R), get(k * 2 + 1, mid + 1, r, L, R));
}
void updatesum(int x, int val)
{
    for(;x<=maxn;x+=(x&-x)) t[x] += val;
}
ll getsum(int x)
{
    if(x <= 0) return 0;
    ll res= 0;
    for(;x;x-=(x&-x)) res += t[x];
    return res;
}
string cur[maxn];
void sub1()
{
    cur[0] = s;
    char type;
    for(int i=1; i<=m; ++i)
    {
        cur[i] = cur[i-1];
        cin >> type;
        if(type == 'C')
        {
            int x;
            cin >> x;
            cur[i][x] = ((cur[i][x] == '(') ? ')' : '(');
        }
        else if(type == 'Q')
        {
            int ans = 0, sl = 0;
            int l,r;
            cin >> l >> r;
            for(int j=l; j<=r; ++j)
            {
                sl += ((cur[i][j] == '(') ? 1 : -1);
                if(sl < 0) ans ++,sl++;
            }
            cout << ans + sl << '\n';
        }
        else
        {
            int k;
            cin >> k;
            cur[i] = cur[k-1];
        }
    }
}
void sub2()
{
    for(int i=1; i<=n; ++i)
    {
        sum[i] = sum[i-1] + ((s[i] == '(') ? 1 : -1);
        updatesum(i,((s[i] == '(') ? 1 : -1));
    }
    init(1,1,n);
    char type;
    for(int i=1; i<=m; ++i)
    {
        cin >> type;
        if(type == 'C')
        {
            int x;
            cin >> x;
            if(s[x] == '(')
            {
                update(1,1,n,x,n,-2);
                s[x] = ')';
                updatesum(x,-2);
            }
            else
            {
                update(1,1,n,x,n,2);
                s[x] = '(';
                updatesum(x,2);
            }
        }
        else
        {
            int l,r;
            cin >> l >> r;
            int k = getsum(r);
            int y = get(1,1,n,l,r) - getsum(l-1);
            int x = getsum(r) - getsum(l-1);
            if(y < 0) x += 2 * abs(y);
            cout << x << '\n';
        }
    }
}
int main()
{
    //#ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    //#endif
    cin >> s >> m;
    n = s.size();
    s = ' ' + s;
    if(n <= 1000 && m <= 1000) sub1();
    else
        sub2();
}
