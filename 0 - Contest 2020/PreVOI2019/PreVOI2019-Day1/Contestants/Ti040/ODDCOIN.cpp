#include <bits/stdc++.h>

using namespace std;
#define taskname "ODDCOIN"

int x, t;
int ntest;
int f[300005];
vector < int > cost;
vector < int > cost2;

int main()
{
    if (fopen (taskname".inp", "r"))
    {
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> ntest;
    cost.push_back(1);
    cost.push_back(3);
    cost.push_back(5);
    cost.push_back(10);
    cost.push_back(30);
    cost.push_back(50);
    cost.push_back(100);
    cost.push_back(300);
    cost.push_back(500);
    cost.push_back(1000);
    cost.push_back(3000);
    cost.push_back(5000);
    cost.push_back(10000);
    cost.push_back(30000);
    cost.push_back(50000);
    while (ntest --> 0)
    {
        int res = 0;
        cost2.clear();
        cin >> x >> t;
        cost2.push_back(x);
        for (int i = 0; i < cost.size(); i++)
            cost2.push_back(cost[i]);
        sort (cost2.begin(), cost2.end());
        if (t > 250000)
        {
            for (int i = cost2.size() - 1; i >= 0; i--)
                if (cost2[i] <= t)
                {
                    int p = t - 250000;
                    if (cost2[i] >= p)
                    {
                        res++;
                        t -= cost2[i];
                        break;
                    }
                    else
                    {
                        p = p / cost2[i];
                        res += p;
                        t -= cost2[i] * p;
                        if (t > 250000)
                        {
                            res++;
                            t -= cost2[i];
                        }
                        break;
                    }
                }
        }
        for (int i = 1; i <= t; i++)
        {
            f[i] = 1e9;
            for (int j = 0; j < cost2.size(); j++)
            {
                int cur = cost2[j];
                if (i >= cur)
                    f[i] = min(f[i], f[i - cur] + 1);
            }
        }
        cout << f[t] + res << '\n';
    }
}
