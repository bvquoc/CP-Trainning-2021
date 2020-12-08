#include <bits/stdc++.h>

#define task "PAINT"
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
const int N = 1e6 + 4;
vi color[26];
int n, cnt, p[26][N];
string s;
char ans[N];
struct query
{
    int t, x, y;
} q[N];
//int findset(int i) {return p[i] == i ? i : p[i] = findset(p[i]);}
void sub1()
{
    cnt = 1;
    rep(i, 1, n)
	{
	    int type;
	    char x;
	    cin >> type >> x;
	    if (type == 1)
        {
            s.pb(x);
            color[x - 'a'].pb(cnt - 1);
            cnt++;
        }
	    else
        {
            char y;
            cin >> y;
            if (x == y) continue;
            for (int pos : color[x - 'a'])
            {
                s[pos] = y;
                color[y - 'a'].pb(pos);
            }
            color[x - 'a'].clear();
        }
	}
	cout << s;
	exit(0);
}
int main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin >> n;
	if (n < 5001) sub1();
	rep(i, 1, n)
	{
	    int type;
	    char x, y = 'a';
	    cin >> type >> x;
	    if (type == 2) cin >> y;
	    else cnt++;
	    q[i] = {type, x - 'a', y - 'a'};
	}
	rep(i, 0, 25) p[i][n] = p[i][n + 1] = i;
	int cnt1 = cnt;
	Rep(i, n, 1)
	{
	    int type = q[i].t;
	    int x = q[i].x, y = q[i].y;

	    if (type == 1) ans[cnt --] = (char) (p[x][i] + 'a');
        else p[x][i] = p[y][i + 1];
        rep(j, 0, 25) p[j][i - 1] = p[j][i];
	}
	rep(i, 1, cnt1) cout << ans[i];
}
