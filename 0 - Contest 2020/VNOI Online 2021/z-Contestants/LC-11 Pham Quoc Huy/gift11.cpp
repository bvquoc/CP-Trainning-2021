#include <bits/stdc++.h>

using namespace std;
int n, a[100009], ans[100009], check[100009], res;
void out()
{
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        stringstream ss;
        ss << ans[i];
        string p = ss.str();
        s = s + p;
    }
    int cntl = 0, cntr = 0;
    for (int i = 0; i < s.size(); i++)
        if (i % 2 == 0)
            cntl += (s[i] - 48);
        else
            cntr += (s[i] - 48);
    if (abs(cntr - cntl) % 11 == 0)
        res++;
}
void backtrack(int cnt)
{
    if (cnt == n)
    {
        out();
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!check[i])
        {
            check[i] = 1;
            ans[cnt+1] = a[i];
            backtrack(cnt+1);
            check[i] = 0;
        }
}
int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    int t;
    cin >> t;
    while (t)
    {
        t--;
        res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        backtrack(0);
        cout << res << '\n';
    }
}
