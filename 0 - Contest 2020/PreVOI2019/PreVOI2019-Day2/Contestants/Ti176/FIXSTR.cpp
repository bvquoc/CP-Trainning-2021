//Trương Minh Trí
#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define FORN(i, x, y) for(int i = x; i >= y; --i)
#define Task "FIXSTR"
#define maxn 1000005
#define maxm
#define pii pair <int, int>
#define plong long pair <long long, long long>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
string s;
string S[maxn];
int a[maxn];
int m, n;
int res;
void Sub1()
{
    FOR(i, 1, m)
    {
        char tp; cin >> tp;
        if(tp=='C')
        {
            int pos;
            cin >> pos;
            string x = S[i-1];
            if(x[pos]=='(') x[pos] = ')';
            else x[pos] = '(';
            S[i] = x;
        }
        else if(tp=='Q')
        {
            int l, r;
            cin >> l >> r;
            res = 0;
            S[i] = S[i-1];
            string x = S[i];
            int run = 0;
            FOR(j, l, r)
            {
                if(x[j] == '(') run--;
                else run++;
                if(run > 0) res += run, run = 0;
            }
            if(run < 0) res += -run;
            cout << res << "\n";
        }
        else
        {
            int pos; cin >>pos;
            S[i] = S[pos-1];
        }
    }
}
long long sum[maxn];
int f[4 * maxn];
long long t[maxn];
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
long long getsum(int x)
{
    if(x <= 0) return 0;
    long long res= 0;
    for(;x;x-=(x&-x)) res += t[x];
    return res;
}
void Sub2()
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
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> s;
    s = ' ' + s;
    S[0] = s;
    n = s.length() - 1;
    cin >> m;
    if(m <= 1000 && m <= 1000) Sub1(); else
        Sub2();

}
