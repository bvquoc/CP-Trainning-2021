#include <bits/stdc++.h>
#define ft                          first
#define sd                          second
#define task                        "decor"
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

const LL MOD = 1e9 + 7;
const LL N   = 5e5 + 5;
const LL INF = INT_MAX;
const int base = 27;

/* ------------- ------------- ------------- ------------- ------------- ------------- ------------- */
int n, m, k, cnt[N], l, r, len, low[N], num[N], lab[N], cLab, cur, tc[N];
bool ON[N];
vector<int> adj[N];
stack<int> st;

void Sub1_2()
{
    for (int i = 1; i <= n; i++)
        cnt[i] = cnt[i-1] + !ON[i];

    if (cnt[n] == n)
    {
        cout << -1;
        exit(0);
    }

    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(cnt, cnt + 1 + i, cnt[i] - k) - cnt;
        if (i - pos > len)
        {
            len = i - pos;
            l = pos + 1, r = i;
        }
    }

    cout << l << ' ' << r;
    exit(0);
}

void DFS(int u)
{
    num[u] = low[u] = ++cur;
    st.push(u);

    for (int v : adj[u])
        if (num[v])
            MIN(low[u], num[v]);
        else
        {
            DFS(v);
            MIN(low[u], low[v]);
        }

    if (low[u] == num[u])
    {
        cLab++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            num[v] = low[v] = INF;
            lab[v] = cLab;
            cnt[cLab] += ON[v];
        }
        while (v != u);
    }

    return;
}

void RE()
{
    for (int i = 1; i <= cLab; i++)
        tc[i] = cnt[i];

    return;
}

void Sub3()
{
    for (int i = 1; i <= n; i++)
        if (!lab[i])
            DFS(i);

    for (int i = 1; i <= n; i++)
    {
        RE();
        int j = i, LED = k;

        while(1)
        {
            if ((!tc[lab[j]] && !LED) || j > n)
                break;

            if (tc[lab[j]])
                tc[lab[j]]--;
            else LED--;
            j++;
        }

        if (j - i > len)
        {
            len = j - i;
            l = i, r = j - 1;
        }
    }

    if (!len)
        cout << -1;
    else
        cout << l << ' ' << r;
    exit(0);
}

void Sub4()
{
    int i = 1, j = 1;
    for (int i = 1; i <= n; i++)
        if (!lab[i])
            DFS(i);

    while (i <= n)
    {
        while (j <= n && (tc[lab[j]] < cnt[lab[j]] || k))
        {
            if (tc[lab[j]] >= cnt[lab[j]])
                k--;
            tc[lab[j]]++;
            j++;
        }

        if (j - i > len)
        {
            len = j - i;
            l = i, r = j - 1;
        }

        while (i < j)
        {
            if (tc[lab[i]] > cnt[lab[i]])
                k++;

            tc[lab[i]]--;

            i++;
            if (tc[lab[j]] < cnt[lab[j]] || k)
                break;
        }
    }

    if (!len)
        cout << -1;
    else
        cout << l << ' ' << r;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    fi;
    fo;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        ON[i] = (c == '1');
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (!m)
        Sub1_2();

    if (n <= 2000)
        Sub3();

    Sub4();
    return 0;
}
