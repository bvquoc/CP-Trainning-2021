#include<bits/stdc++.h>

using namespace std;

#define ll  long long

const int   N   = 1e6 + 1;

struct BIT  {
    vector<ll>  t;
    int n;

    BIT(int _n) {
        n = _n;
        t.assign(n + 1,0);
    }

    int upd(int p,int v)    {
        if (v == 0) return  0;
        for(; p <= n ; p += p & -p)
            t[p] += v;
        return  1;
    }
    ll  get(int p)  {
        ll  ans = 0;
        for(; p >= 1 ; p -= p & -p)
            ans += t[p];
        return  ans;
    }
};

ll  a[N];

void work() {
    int n;  cin >> n;
    int m;  cin >> m;

    BIT T_val(n);
    BIT T_dif(n);

    for(int i = 1 ; i <= n ; ++i)   cin >> a[i];
    for(int i = n ; i >= 1 ; --i)   {
        a[i] -= a[i - 1];
        T_val.upd(i,a[i]);
        T_dif.upd(i,max(a[i],0ll));
    }
    for(int i = 1 ; i <= m ; ++i)   {
        int t;  cin >> t;
        int l;  cin >> l;
        int r;  cin >> r;
        if (t == 1) {
            int x;  cin >> x;   ++r;
            T_val.upd(l, x);
            T_val.upd(r,-x);

            T_dif.upd(l,-max(a[l],0ll));    a[l] += x;
            T_dif.upd(r,-max(a[r],0ll));    a[r] -= x;

            T_dif.upd(l, max(a[l],0ll));
            T_dif.upd(r, max(a[r],0ll));
        }
        if (t == 2)
            cout << T_val.get(l) + T_dif.get(r) - T_dif.get(l) << "\n";
    }
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef combi
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    #endif // combi

    int itest;
    cin >> itest;

    while (itest--)
        work();
}
