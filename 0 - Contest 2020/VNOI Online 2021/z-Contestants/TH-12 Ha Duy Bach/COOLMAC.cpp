#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define name "COOLMAC"
#define se second
using namespace std;
const int N =1e5+100;

ii a[N];
int L,R;
int n,m;

namespace sub2
{
    bool kt[N];
    int f[N],res;
    bool cmp(const ii a,const ii b)
    {
        if (a.fi==b.fi) return a.se>b.se;
        else return a.fi<b.fi;
    }

    bool check(int i)
    {
        return a[i].fi<=L && L<=a[i].se;
    }

    void solve()
    {
        res=n+10;
        sort(a+1,a+n+1,cmp);
        for (int i=1; i<=n; i++)
        {
            f[i]=1; kt[i]=check(i);
            if (!kt[i])
            {
                for (int j=i-1; j>0; j--)
                {
                    if (kt[j] && (!kt[i] || f[j]+1<f[i]) && a[i].fi<=a[j].se )
                    {
                        f[i]=f[j]+1;
                        kt[i]=1;
                    }
                }
            }
            if (kt[i] && a[i].se==R)
            {
                res=min(res,f[i]);
            }
        }

        if (res!=n+10) cout<<res;
        else cout<<-1;
        cout<<'\n';
    }
}

namespace sub3
{
    bool check(int i)
    {
        return a[i].fi<=L && L<=a[i].se;
    }

    bool cmp(const ii a,const ii b)
    {
        if (a.se==b.se) return a.fi>b.fi;
        else return a.se>b.se;
    }

    void solve()
    {
        int res=0;
        sort(a+1,a+n+1,cmp);

        int i=1;

        if (a[i].se!=R)
        {
            cout<<-1; return ;
        }
        if (check(i))
        {
            cout<<1; return ;
        }
        res=1;
        int l1=a[i].fi, j=i;

        while (i<n)
        {
            int Min=1e5,k=1;
            while (j<n && a[j+1].se>=l1)
            {
                ++j;
                if (check(j) )
                {
                    cout<<res+1; return ;
                }
                if (a[j].fi<Min)
                {
                    Min=a[j].fi;
                    k=j;
                }
            }

            l1=min(l1,a[k].fi);

            if (j==i)
            {
                cout<<-1; return ;
            }
            res++;
            i=j;
        }

        cout<<res;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(name".inp","r"))
    {
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].fi>>a[i].se;
    }
    cin>>m;
    R=L=1e5;
    for (int i=1; i<=m ;i++)
    {
        int z;
        cin>>z;
        L=min(L,z);
    }
    if (n<=1e4)
        sub2::solve();
    else
        sub3::solve();
}
