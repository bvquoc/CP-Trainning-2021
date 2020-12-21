#include <bits/stdc++.h>

using namespace std;

#define N 500005
#define fi first
#define se second

int n, m, k;
string a;
pair < int, int > p[N];

void read()
{
    cin >> n >> m >> k;
    cin >> a;
    for(int i = 1; i <= m; i ++)
        cin >> p[i].fi >> p[i].se;
}

vector < int > s;

void sub1()
{
    int l = 0, r = 0, maxval = 0, tmp;
    for(int i = 0; i < n; i ++)
        if(a[i] == '0')
            s.push_back(i);
    for(int i = 0; i < s.size(); i ++)
    {
        if(i == s.size() - 1 && maxval < n - 1 - (s[i] + 1) + 1)
        {
            l = s[i] + 2;
            r = n;
            break;
        }
        tmp = (s[i + 1] - 1) - (s[i] + 1) + 1;
        if(maxval < tmp)
        {
            maxval = tmp;
            l = s[i] + 2;
            r = s[i + 1];
        }
    }
    cout << l << " " << r;
}

void sub2()
{
    int maxval = 0, l = 0, r = 0;
    for(int i = 0; i < n; i ++)
        if(a[i] == '0')
            s.push_back(i);
    for(int i = 0; i < s.size(); i ++)
    {
        if(i == s.size() - 1)
            break;
        if(i + k < s.size())
        {
            if(i == 0 && maxval < s[i + k] + 1)
            {
                maxval = s[i + k];
                l = i + 1;
                r = s[i + k];
                continue;
            }
            if(maxval < s[i + k] - (s[i - 1] + 1))
            {
                maxval = s[i + k] - (s[i - 1] + 1);
                l = s[i - 1] + 2;
                r = s[i + k];
            }
        }
        else
        {
            int sz = s.size() - 1;
            if(s[i] == 0 && maxval < s[sz] - s[i] + 1)
            {
                maxval = s[sz] - s[i] + 1;
                l = s[i];
                r = s[sz];
                continue;
            }
            if(i == 0 && maxval < n - 1 + 1)
            {
                maxval = n - 1 + 1;
                l = 1;
                r = n;
                continue;
            }
            if(maxval < n - 1 - (s[i - 1] + 1) + 1)
            {
                maxval = n - 1 - (s[i - 1] + 1) + 1;
                l = s[i - 1] + 2;
                r = n;
            }
        }
    }
    cout << l << " " << r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
    read();
    if(m == 0 && k == 0)
    {
        sub1();
        return 0;
    }
    if(m == 0)
    {
        sub2();
        return 0;
    }
    return 0;
}
