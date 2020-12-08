#include <bits/stdc++.h>

#define task "FIXSTR"
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (int i = (r); i >= (l); --i)
#define DEBUG(X) { cerr << #X << " = " << (X) << '\n'; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << '\n'; }
#define sz(x) ((int)(x).size())
#define pb push_back
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
const int N = 1e6 + 1;
int m, b[N], leaf[N];
string s;
string undo[N];
int solve(int l, int r)
{
    int cnt = 0, res = 0;
    rep(i, l, r)
    {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0)
        {
            res++;
            cnt = 0;
        }
    }
    res += cnt;
    return res;
}
void sub1()
{
    undo[0] = s;
	rep(i, 1, m)
	{
	    char type;
	    int x, y;
	    cin >> type >> x;
	    if (type == 'C')
        {
            s[x] = (s[x] == ')') ? '(' : ')';
        } else if (type == 'U')
        {
            s = undo[x - 1];
        } else
        {
            cin >> y;
            cout << solve(x, y) << '\n';
        }
        undo[i] = s;
	}
	exit(0);
}
struct IT
{
    vi it, lz;
    IT(int n) {it.assign(4 * n, 0); lz.assign(4 * n, 0);}
    void build(int id, int l, int r)
    {
        if (l == r)
        {
            it[id] = b[l];
            leaf[l] = id;
            return;
        }
        int m = (l + r) >> 1;
        build(id << 1, l, m);;
        build((id << 1) | 1, m + 1, r);
        it[id] = min(it[id << 1], it[(id << 1) | 1]);
    }
    void dolazy(int id, int l, int r)
    {
        if (lz[id] == 0) return;
        it[id] += lz[id];
        if (l != r)
        {
            lz[id << 1] += lz[id];
            lz[(id << 1) | 1] += lz[id];
        }
        lz[id] = 0;
    }
    void update(int id, int l, int r, int L, int R, int val)
    {
        dolazy(id, l ,r);
        if (l > R || r < L) return;
        if (L <= l && r <= R)
        {
            lz[id] += val;
            dolazy(id, l, r);
            return;
        }
        int m = (l + r) >> 1;
        update(id << 1, l, m, L, R, val);
        update((id << 1) | 1, m + 1, r, L, R, val);
        it[id] = min(it[id << 1], it[(id << 1) | 1]);
    }
    int get(int id, int l, int r, int L, int R)
    {
        dolazy(id, l, r);
        if (l > R || r < L) return N;
        if (L <= l && r <= R) return it[id];
        int m = (l + r) >> 1;
        return min(get(id << 1, l, m, L, R), get((id << 1) | 1, m + 1, r, L, R));
    }
    void downr(int id, int l, int r, int pos)
    {
       dolazy(id, l, r);
       if (l > pos || r < pos) return;
       if (l == r) return;
       int m = (l + r) >> 1;
       downr(id << 1, l, m, pos);
       downr((id << 1) | 1, m + 1, r, pos);
    }
};

int main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin >> s >> m;
	int n = sz(s);
	s = '0' + s;
	if (n * m <= 1000000) sub1();
	IT st(n);
	rep(i, 1, n) if (s[i] == '(') b[i] = b[i - 1] + 1;
	else b[i] = b[i - 1] - 1;
	//rep(i, 1, n) cout << b[i] << " \n"[i == n];
	st.build(1, 1, n);
	undo[0] = s;
	rep(i, 1, m)
	{
	    char type;
	    int x, y;
	    cin >> type >> x;
	    if (type == 'C')
        {
            s[x] = (s[x] == ')') ? '(' : ')';
            int delta = (s[x] == ')') ? -2 : 2;
            //DEBUG(delta);
            st.update(1, 1, n, x, n, delta);
            //cout << "AFter update : " << st.get(1, 1, n, 1, n) << '\n';
        } else if (type == 'U')
        {
            st.lz.assign(4 * n, 0);
            s = undo[x - 1];
            rep(i, 1, n) if (s[i] == '(') b[i] = b[i - 1] + 1;
            else b[i] = b[i - 1] - 1;
            //rep(i, 1, n) cout << b[i] << " \n"[i == n];
            st.build(1, 1, n);
        } else
        {
            cin >> y;
            int mn = st.get(1, 1, n, x, y);
            //DEBUG(mn);
            st.downr(1, 1, n, y);
            st.downr(1, 1, n, x - 1);
            int mnn = abs(min(0, mn - st.it[leaf[x - 1]]));
            //cout << "val of " << st.it[leaf[x - 1]] << '\n';
            //cout << "val of " << st.it[leaf[y]] << '\n';
            cout << mnn + ((st.it[leaf[y]] - st.it[leaf[x - 1]]) + mnn) << '\n';
        }
        undo[i] = s;
	}
	//rep(i, 1, m) cout << undo[i] << '\n';
}
