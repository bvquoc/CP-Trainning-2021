#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

const int inf = 1e9 + 1;
const int maxn = 1e5 + 1;
int x, t, dp[maxn];
int a[15] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
vector<int> adj;
queue<int> Queue;

void Input()
{
    cin >> x >> t; adj.clear();
    for (int i = 0; i < 15; i++)
        adj.push_back(a[i]);
    adj.push_back(x);
    sort(adj.begin(), adj.end());
}

void Prepare()
{
    for (int i = 0; i < maxn; i++)
        dp[i] = inf;
    dp[0] = 0; Queue.push(0);
    while (!Queue.empty())
    {
        int qu = Queue.front();
        Queue.pop();

        for (int i : adj)
        if (qu + i >= maxn) break;
        else
        {
            if (dp[qu + i] == inf)
            {
                dp[qu + i] = dp[qu] + 1;
                Queue.push(qu + i);
            }
        }
    }
}

void Solve()
{
    int res = 0;
    while (t >= maxn)
    {
        t -= adj.back();
        res++;
    }
    res += dp[t];
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp" , "r" , stdin);
    //freopen("test.out" , "w" , stdout);

    freopen("oddcoin.inp" , "r" , stdin);
    freopen("oddcoin.out" , "w" , stdout);

    int q; cin >> q;
    while (q--)
    {
        Input();
        Prepare();
        Solve();
    }
}

