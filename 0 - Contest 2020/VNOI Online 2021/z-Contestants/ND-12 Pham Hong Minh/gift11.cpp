#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
int n[11],t[5],a[11][2005],x[11],T,res,v;
vector <int> kq;

bool check(int kk)
{
    bool ok = true; t[0] = 0; t[1] = 0;
    for (int i = 1;i<=n[kk];++i)
    {
        kq.clear();
        v = a[kk][x[i]];
        while (v > 0)
        {
            kq.push_back(v % 10);
            v = v / 10;
        }

        for (int i = kq.size() - 1;i>=0;--i)
        {
            t[ok] = t[ok] + kq[i];
            ok = !ok;
        }
    }
    if ((t[0] - t[1]) % 11 == 0) return true; return false;
}

void sub1()
{
    for (int kk = 1;kk<=T;++kk)
    {
        for (int i = 1;i<=n[kk];++i) x[i] = i;

        res = 0;
        do
        {
           if (check(kk)) res++;
        } while (next_permutation(x + 1,x + n[kk] + 1));

        cout << res <<'\n';
    }
    return;
}

void sub2()
{
    for (int kk = 1;kk <= T;++kk)
    {
        bool ok = true; t[0] = 0; t[1] = 0;

        for (int i = 1;i<=n[kk];++i)
        {
           kq.clear();
           v = a[kk][i];
           while (v > 0)
           {
              kq.push_back(v % 10);
              v = v / 10;
           }

           for (int i = kq.size() - 1;i>=0;--i)
           {
              t[ok] = t[ok] + kq[i];
              ok = !ok;
           }
        }

        if ((t[0] - t[1]) % 11 == 0)
        {
            res = 1;
            for (int i = 2;i<=n[kk];i++) res = (res * i) % mod;
            cout << res <<'\n';
        } else cout << 0 <<'\n';
    }

    return;
}

int main()
{
    freopen("gift11.inp","r",stdin); freopen("gift11.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;

    int S = 0;
    for (int kk = 1;kk <= T;++kk)
    {
        cin >> n[kk]; S = S + n[kk];
        for (int i = 1;i<=n[kk];++i)
         cin >> a[kk][i];
    }

    if (S <= 8) {sub1(); return 0;}
    sub2();

    return 0;
}
