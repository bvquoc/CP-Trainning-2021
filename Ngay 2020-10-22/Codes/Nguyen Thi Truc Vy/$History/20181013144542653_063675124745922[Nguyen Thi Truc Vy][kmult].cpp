#include <bits/stdc++.h>

using namespace std;
int k,n,a[1000],dau[1000],dem=0;

void sinh(int x, int &dem)
{
    for (int i=0; i<=1; i++)
    {
        if (dem==1) continue;
        dau[x]=i;
        if (x==(n-1))
        {
            int t=a[1];
            for (int j=1; j<=n-1; j++)
            {
                if (dau[j]==0) t-=a[j+1];
                else t+=a[j+1];
            }
            if (t%k==0)
            {
                dem++;
                cout << 1 << endl;
                for (int p=1; p<=n-1; p++)
                {
                    if (dau[p]==0) cout << '-';
                    else cout << '+';
                }
            }
        }
        else sinh(x+1,dem);
    }
}

int main()
{
    freopen( "kmult.inp", "r", stdin);
    freopen( "kmult.out", "w", stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    sinh(1,dem);
    if (dem==0) cout << 0;
    return 0;
}
