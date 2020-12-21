#include <bits/stdc++.h>
#define ft                          first
#define sd                          second
#define task                        "gift11"
#define fi			                freopen(task".inp", "r", stdin)
#define fo			                freopen(task".out", "w", stdout)
#define reset(a, b)                 memset(a, b, sizeof(a))
#define MAX(a, b)                   a = max(a, b)
#define MIN(a, b)                   a = min(a, b)
#define pb  			            push_back
#define mp(a, b)                    make_pair(a, b)

using namespace std;

typedef long long                   LL;
typedef pair<int,int>               II;

const LL MOD = 998244353;
const LL N   = 1e5 + 5;
const LL INF = INT_MAX;
const int base = 27;

/* ------------- ------------- ------------- ------------- ------------- ------------- ------------- */
int a[N], b[N], n;

bool Check()
{
    string s = "";
    for (int i = n - 1; i >= 0; i--)
        do
        {
            s = char((b[i]%10)+'0') + s;
            b[i] /= 10;
        }
        while (b[i]);

//    cout << s << '\n';

    int se = 0, so = 0;
    for (int i = 0; i < s.size(); i++)
        if (i&1)
            se += int(s[i]-'0');
        else
            so += int(s[i]-'0');

    return ((so - se) % 11 == 0);
}

void Sub1()
{
    vector<int> p(0);
    for (int i = 0; i < n; i++)
        p.pb(i);

    int ans = 0;
    do
    {
        for (int i = 0; i < n; i++)
        {
            int j = p[i];
            b[i] = a[j];
        }

        ans += Check();
    }
    while (next_permutation(p.begin(), p.end()));

    cout << ans << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    fi;
    fo;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Sub1();
    }
    return 0;
}
