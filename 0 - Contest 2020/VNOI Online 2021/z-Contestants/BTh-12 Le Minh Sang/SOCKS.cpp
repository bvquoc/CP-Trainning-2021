#include <bits/stdc++.h>
#define TASK "SOCKS"
#define X first
#define Y second
#define ll long long
#define pi pair<int,int>
#define Bit(i) (1<<(i))
#define Get_Bit(i,x) (((x)>>i)&1)

using namespace std;
const int N = 5e5 + 5;
int n,q,cnt[N];
bool a[N];
vector<int> ke[N];

bool check1()
{
    int ans1 = 0, ans2 = 0;
    for (int i=1; i<=n; ++i) {
        ans1 += (cnt[i]==1);
        ans2 += (cnt[i]==2);
    }
    return (ans1 + ans2 == n);
}

void Sub1()
{
    for (int i=0; i<=n; ++i) cout << 1 << "\n";
}

vector<int> v;
int cl;
int calc(int u)
{
    int res = 0;
    if (a[v[1]] && a[v[0]]) {
        ++res;
        if (a[u]) {if (cl>3) ++res;}
        else if (cl>2) ++res;
    } else {
        if (a[v[1]] || a[v[0]]) {
            if (cl>1) ++res;
        } else {
            if (cl>=2) ++res;
        }
    }
    return res;
}

void Sub2()
{
    int u = 0;
    for (int i=1; i<=n; ++i) {
        if (cnt[i]==3) u = i;
        cl += a[i];
    }
    for (int i=0; i<ke[u].size(); ++i) {
        if (cnt[ke[u][i]]==1) v.push_back(ke[u][i]);
    }
    cout << calc(u) << "\n";
    while (q--) {
        int x;  cin >> x;
        if (a[x]) a[x] = 0, --cl;
        else a[x] = 1, ++cl;
        cout << calc(u) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    cin >> n >> q;
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<n; ++i) {
        int u,v;    cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
        ++cnt[u];   ++cnt[v];
    }
    if (check1()) Sub1(); else Sub2();
    return 0;
}
