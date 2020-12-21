#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define BIT(mask, i) (((mask) >> (i)) & 1ll)
#define ONBIT(mask, i) (mask^(1ll << i))
#define OFFBIT(mask, i) (mask &~ (1ll << i))
#define countBIT(x) __builtin_popcountll(x)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
using namespace std;

template<class T> inline void Write(T x)
{
    if(x<0)
    {
        putchar('-');
        x*=-1;
    }
    if(x>9) Write(x/10);
    putchar(x%10+'0');
}

template<class T>inline void Read(T &x)
{
    char c;
    for(c=getchar(); (c>'9'||c<'0')&&c!='-'; c=getchar());
    T y;
    if(c=='-')x=0,y=-1;
    else x=c-'0',y=1;
    for(c=getchar(); c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=y;
}


template <class X, class Y> bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else return false;
}

template <class X, class Y> bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else return false;
}

template <class T> T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}

typedef long long ll;
typedef pair<int,int> ii;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;
/* ---------- default ---------- */

int numNode, numQuerry;
int on[N];
vector<int> g[N];

void inp()
{
    cin >> numNode >> numQuerry;
    forr(i, 1, numNode) cin >> on[i];
    forr(i, 1, numNode - 1)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int res = 0;
void upd(int x)
{
    on[x] ^= 1;
    if(on[x]) ++res;
    else -- res;
}

void Process()
{
    forr(i, 1, numNode) res += on[i];

    cout << (res >= 2) << "\n";
    while(numQuerry--)
    {
        int u;
        cin >> u;
        upd(u);
        cout << (res >= 2) << "\n";
    }
}

int main()
{
#define Task "SOCKS"
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    inp();
    Process();
    return 0;
}
