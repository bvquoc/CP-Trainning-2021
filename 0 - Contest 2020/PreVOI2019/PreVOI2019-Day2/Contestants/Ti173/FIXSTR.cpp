#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1000005;

struct Query
{
    char type;
    int x, y;
};

int n, m;
string s;
Query q[MaxN];

void Sub1()
{
    bool a[1005][1005];
    for (int i = 1; i <= n; i++)
    {
        a[0][i] = (s[i] == '(');
    }
    for (int i = 1; i <= m; i++)
    {
        if (q[i].type == 'U')
        {
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = a[q[i].x - 1][j];
            }
            continue;
        }
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = a[i - 1][j];
        }
        if (q[i].type == 'C')
        {
            a[i][q[i].x] = !a[i][q[i].x];
        }
        else if (q[i].type == 'Q')
        {
            int res = 0, sum = 0;
            for (int j = q[i].x ; j <= q[i].y; j++)
            {
                sum += (a[i][j] == true ? 1 : -1);
                if (sum < 0)
                {
                    res++;
                    sum = 0;
                }
            }
            res += sum;
            cout << res << '\n';
        }
    }
}


void sub2()
{
    int b[1000005];
    for (int i = 1; i <= n; i++)
    {
        b[i] = (s[i] == '(');
    }
    for (int i = 1; i <= m; i++)
    {
        if (q[i].type == 'C')
        {
            b[q[i].x] = b[q[i].x];
        }
        else if (q[i].type == 'Q')
        {
            int res = 0, sum = 0;
            for (int j = q[i].x; j <= q[i].y; j++)
            {
                sum += (b[j] == true ? 1 : -1);
                if (sum < 0)
                {
                    res++;
                    sum = 0;
                }
            }
            res += sum;
            cout << res << '\n';
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.inp", "r", stdin);
    freopen("FIXSTR.out", "w", stdout);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    cin >> m;
    int du = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].type;
        if (q[i].type == 'Q')
        {
            cin >> q[i].x >> q[i].y;
        }
        else
        {
            cin >> q[i].x;
        }
        du += (q[i].type == 'U');
    }
    if (n <= 1000 && m <= 1000)
    {
        Sub1();
        return 0;
    }
    if (du == 0)
    {
        sub2();
    }
    return 0;
}