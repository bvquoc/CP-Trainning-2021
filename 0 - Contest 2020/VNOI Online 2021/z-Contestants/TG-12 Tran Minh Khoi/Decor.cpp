#include <bits/stdc++.h>
#define fi "Decor.inp"
#define fo "Decor.out"

using namespace std;

int n, m, k;
int f[500011];
string s;

void INP()
{
    cin >> n >> m >> k;
    cin >> s;
}

void Solve()
{
    s = "0" + s;
    int l = 1, r = 0, ans1 = 0, ans2 = 0, t = 0;
    while (r < n)
    {
        r++;
        if (s[r] == '0')
        {
            t++;
            if (t > k)
            {
                t--;
                l++;
            }
        }
        //cout << l << " " << r << " " << t << endl;
        if (r - l > ans2 - ans1)
        {
            ans1 = l;
            ans2 = r;
        }
    }
    if (l <= r) cout << ans1 << " " << ans2; else cout << -1;
}

int main()
{
    freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
    INP();
    Solve();
    return 0;
}
