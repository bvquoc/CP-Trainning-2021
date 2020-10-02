#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
using namespace std;
long long n,r,k,a[501][501],x,y,kt[501][501],s;
int main()
{
    FastIO;
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    cin >> n >> r >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    for (int l = 1; l <= k; l++)
    {
        cin >> x >> y;
        for (int i = x; i <= x+r-1; i++)
        {
            for (int j = y; j <= y+r-1; j++)
            {
                if (kt[i][j] == 0)
                {
                    s = s + a[i][j];
                    kt[i][j] = 1;
                }
            }
        }
    }
    cout << s;
    return 0;
}
