/// NHDanDz
#include <bits/stdc++.h>
#define nmax 100005
#define MOD 1000000000007
#define F first
#define S second
#define PB push_back
#define reset(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define ll long long
#define DANGCUTO "CONSTRUCT"
#define endl '\n'
#define sz() size()
using namespace std;
int T, a[nmax], n,m, l[nmax], r[nmax] , cnt(0) , b[nmax];
stack <int> v;
struct hd
{
    int l, r , id;
} d[nmax] , h[nmax];
bool cmp(hd a, hd b)
{
    return (a.r - a.l) > (b.r - a.l);
}
void make()
{
    while(v.size() != 0)
        v.pop();
    for(int i = 1; i <= n; i++)
    {
        while(v.size() != 0 && a[v.top()] >= a[i])
            v.pop();
        if(v.size() != 0)
            d[i].l = v.top() + 1;
        else
            d[i].l = 1;
        v.push(i);
    }
    while(v.size() != 0)
        v.pop();
    for(int i = n; i >= 1; i--)
    {
        while(v.size() != 0 && a[v.top()] >= a[i])
            v.pop();
        if(v.size() != 0)
            d[i].r = v.top() - 1;
        else
            d[i].r = n;
        v.push(i);
    }
}
void sub1()
{
    for(int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int l, r , k;
            cin >> l >> r >> k;
            for(int i = l; i <= r; i++)
            {
                a[i] += k;
            }
            make();
        }
        else
        {
            cnt = 0;
            int l , r , ans(0);
            cin >> l >> r;
            for(int i = l; i <= r; i++)
            {
                h[++cnt] = d[i];
                h[cnt].id = i;
            }
            for(int i = 1; i <= n; i++)
            {
                if(i >= l && i <= r)
                    b[i] = a[i];
                else
                    b[i] = 0;
            }
            sort(h + 1, h + 1 + cnt, cmp);
            //cout << l << " " << r << endl;
            //for(int i = 1; i <= cnt; i ++)
            //    cout << h[i].l << " " << h[i].r << " " << h[i].id << endl;
            //cout << endl;
            for(int i = 1; i <= cnt ; i++)
            {
                int da = h[i].id;
                if(b[da] > 0 && h[i].l != 0 && h[i].r != 0)
                {
                    for(int j = max(h[i].l,l) ; j <= min(h[i].r,r); j++)
                    {
                        if(j != da)
                          b[j] -= b[da];
                    }
                    //cout << max(h[i].l,l) << " " << min(h[i].r,r) << endl;
                    ans += b[da];
                    b[da] = 0;
                }
            }
            cout << ans << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(DANGCUTO".inp","r",stdin);
    freopen(DANGCUTO".out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        make();
        if(n <= 1000 && m <= 1000)
        {
            sub1();
        }
    }
    return 0;
}
