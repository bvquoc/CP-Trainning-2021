#include <bits/stdc++.h>

using namespace std;
int n,m,k,a[100007],ma[5007][5007];
bool check[100007];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++)
    {
        char x;
        cin >> x;
        a[i]=x-'0';
    }
    int x=0,y=0;
    if (m==0&&k==0)
    {
        int i=1,l=0,r=0;
        while (i<=n)
        {
            if (a[i]==1)
            {
                l=i,r=i;
                ++i;
                while (a[i]==1)
                {
                    r++;
                    ++i;
                }
                if ((r-l+1)==(y-x+1))
                {
                    if (l<=x)
                    {
                        x=l;
                        y=r;
                    }
                }
                if ((r-l+1)>(y-x+1))
                {
                    x=l;
                    y=r;
                }
            }
            ++i;
        }
        cout << x << " " << y;
        return 0;
    }
    if (m==0)
    {
        for (int i=1;i<=n;i++)
            for (int j=i;j<=n;j++)
                if (a[j]==0)
                    ma[i][j]=ma[i][j-1]+1;
                else
                    ma[i][j]=ma[i][j-1];
        for (int i=1;i<=n;i++)
            for (int j=i;j<=n;j++)
                if (ma[i][j]<=k)
                {
                    if ((j-i+1)>(y-x+1))
                    {
                        x=i;
                        y=j;
                        continue;
                    }
                    if ((j-i+1)==(y-x+1))
                    {
                        if (i<x)
                        {
                            x=i;
                            y=j;
                        }
                    }
                }
        cout << x << " " << y;
        return 0;
    }
    cout << -1;
    return 0;
}
