#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define ins insert
#define era erase
#define ll long long
#define pii pair < int, int >
#define N 100009

using namespace std;
pii b[N];
int a[N];
int n, m;

void sub_1()
{
    b[0] = b[m];
    sort(b, b + m);
    a[0] = a[n];

    int res = 20, l, r;
    for(int bit=0; bit<(1 << m); ++bit)
    if(__builtin_popcount(bit) < res)
    {
        int kt = 0;
        for(int j=1; j<=n; ++j)
        {
            l = a[j]; r = 1e5;
            for(int i=0; i<m; ++i)
                if(bit & (1 << i))
            {
                if(b[i].F > l)
                {
                    kt = 1;
                    break;
                }

                if(b[i].S > l)
                    l = b[i].S;
                if(l >= r)
                    break;
            }
            if(l < r || kt)
            {
                kt = 1;
                break;
            }
        }
        if(kt == 0)
            res = __builtin_popcount(bit);
    }
    if(res == 20)
        cout << -1;
    else cout << res;
}

//----------------------------------------------------------
bool cmp(pii x, pii d)
{
    if(x.S != d.S)
        return x.S < d.S;
    return x.F < d.F;
}
void sub_2()
{
    int L = 1e5, R = 1e5, x, tmp, l;
    for(int i=1; i<=n; ++i)
        L = min(L, a[i]);

    sort(b +1, b + m +1, cmp);
    tmp = 0; l = m;
    while(l != 0 && R > L)
    {
        x = R;
        while(l != 0 && b[l].S >= R)
            x = min(x, b[l].F),
            l--;
        tmp++;
        if(x == R)
            break;
        R = x;
    }
    if(L >= R)
        cout << tmp;
    else cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> m;
    for(int i=1; i<=m; ++i)
        cin >> b[i].F >> b[i].S;
    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> a[i];

    if(n <= 10 && m <= 16)
        sub_1();
    else sub_2();
    return 0;
}
