#include <bits/stdc++.h>
#define N 500009

using namespace std;
int n, m, k;

void sub_1()
{
    int res = 0, sum = 0, l, r;
    char c;
    for(int i=1; i<=n; ++i)
    {
        cin >> c;
        if(c == '1')
            sum++;
        else
        {
            if(sum > res)
            {
                res = sum;
                l = i - sum; r = i -1;
            }
            sum = 0;
        }
    }

    if(sum > res)
    {
        res = sum;
        l = n + 1- sum; r = n;
    }
    if(res == 0)
        cout << -1;
    else cout << l << ' ' << r << '\n';
    exit(0);
}

//----------------------------------------------------
int sum[N];
void sub_2()
{
    char c;
    int tmp, L, R, res = 0, l;

    for(int i=1; i<=n; ++i)
    {
        cin >> c;
        sum[i] = sum[i -1] + (c == '1');
    }

    for(int i=1; i<=n; ++i)
    {
        l = i + res;
        while(l <= n)
        {
            tmp = sum[l] - sum[i -1] + k;

            if(tmp >= l - i +1)
            {
                if(res < l - i +1)
                {
                    res = l - i +1;
                    L = i; R = l;
                }
            }
            else break;
            l++;
        }
    }

    if(res == 0)
        cout << -1;
    else cout << L << ' ' << R << '\n';

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);
    cin >> n >> m >> k;
    if(m == 0 && k == 0)
        sub_1();
    if(m == 0)
        sub_2();
    return 0;
}
