#include <iostream>
#include <cstdio>
using namespace std;

int h[1005];
int a[1005];
int oo = 1e7;
int n,m;


void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
}


void p2()
{
    int l,r;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        h[i] = a[i];
    }
    int ans = 0;
    while (true)
    {
        int cnt = 0;
        int fi = oo;
        int last = l-1;
        for (int i = l; i <= r; i++)
        {
            if (h[i] == 0)
            {
                cnt++;
                if (last == i-1)
                {
                    last = i;
                    continue;
                }
                else
                {
                    for (int j = i-1; j > last; j--)
                    {
                        h[j] -= fi;
                    }
                    ans+=fi;
                }
                fi = oo;
                last = i;

            }
            else
            {
                fi = min(fi,h[i]);
            }
        }
        if (fi < oo)
        {
            for (int j = r; j > last; j--)
            h[j] -= fi;
            ans+=fi;
        }
        if (cnt == r-l+1) break;
    }
    cout << ans << endl;
}


void p1()
{
    int l,r,k;
    cin >> l >> r >> k;
    for (int i = l; i <= r; i++)
    {
        a[i] += k;
    }
}


void proc()
{
    while (m--)
    {
        int c;
        cin >> c;
        if (c == 1) p1();
        else p2();
    }
}


int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
    inp();
    proc();
    }
    return 0;
}
