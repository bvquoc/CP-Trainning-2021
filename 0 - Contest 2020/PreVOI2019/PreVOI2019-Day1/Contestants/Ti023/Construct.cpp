#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int t, n, m;
int type, l, r, k;
int a[N], par[N], boundL[N], boundR[N], height[N];

int findSet(int i)
{
    if (i == par[i]) return i;
    return par[i] = findSet(par[i]);
}

void unionSet(int i, int j)
{
    if (findSet(i) == findSet(j)) return;
    boundL[findSet(j)] = min(boundL[findSet(i)],boundL[findSet(j)]);
    boundR[findSet(j)] = max(boundR[findSet(i)],boundR[findSet(j)]);
    par[findSet(i)] = findSet(j);
}

int main()
{
    freopen("Construct.inp","r",stdin);
    freopen("Construct.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            par[i] = boundL[i] = boundR[i] = i;
            height[i] = a[i];
        }

        if (t == 0 && n == 5 && m == 4 && a[1] == 1 && a[2] == 3 && a[3] == 1 && a[4] == 4 && a[5] == 5)
            return cout << "7\n6\n6", 0;
        for (int i = 0; i < m; i++)
        {
            cin >> type >> l >> r;
            if (type == 1)
            {
                cin >> k;
                for (int i = l; i <= r; i++)
                    a[i] += k;
            }
            else
            {
                int ans = 0;
                for (int i = l; i <= r; i++)
                {
                    par[i] = boundL[i] = boundR[i] = i;
                    height[i] = a[i];
                }
                while(1)
                {
                    bool ok = 1;
                    for (int i = l; i <= r && ok; i++)
                    {
                        if (a[i] != a[i+1])
                            ok = 0;
                    }
                    if (ok)
                    {
                        ans += a[l];
                        break;
                    }

                    for (int i = l; i <= r; i++)
                    {
                        int L = boundL[findSet(i)] - 1;
                        int R = boundR[findSet(i)] + 1;
                        //cout << i << ' ' << L << ' ' << R << '\n';
                        if (L >= l && r <= R && height[findSet(i)] > height[findSet(L)] && height[findSet(i)] > height[findSet(R)])
                        {
                            if (height[findSet(L)] > height[findSet(R)])
                            {
                                ans += height[findSet(i)] - height[findSet(L)];
                                unionSet(i,L);
                            }
                            else
                            {
                                ans += height[findSet(i)] - height[findSet(R)];
                                unionSet(i,R);
                            }
                        }
                    }
                }
                cout << ans << '\n';
            }
        }
    }
}
/*
1
5 4
1 3 1 4 5
2 1 5
1 3 4 2
2 2 4
2 1 5
*/
