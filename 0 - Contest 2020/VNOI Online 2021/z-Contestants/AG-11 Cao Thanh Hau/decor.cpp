#include<bits/stdc++.h>

using namespace std;

const int N=2*1e5+5;

int n, m, k;
int a[N];

void sub1()
{
    int ans=0, ansl=0;
    int l=1;
    a[n+1]=1;
    for (int r=1;r<=n;r++)
    {
        if (a[r]) continue;

        if (k) k--;
        else
        {
            if (r-l>ans)
            {
                ans=r-l;
                ansl=l;
            }
            while (!k)
            {
                k+=(!a[l]);
                l++;
            }
            k--;
        }
    }

    if (n-l+1>ans)
    {
        ans=n-l+1;
        ansl=l;
    }
    if (!ans) cout<<-1; else
    cout<<ansl<<" "<<ansl+ans-1;
}

void solve()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        a[i]=(c=='1');
    }

    sub1();
}

int main()
{
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    solve();

    return 0;
}
