#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long a[2002],b[2002],d,n;

int main()
{
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    for (int i = 1;i <= n;i++)
        cin >> b[i];
    for (int i = 1;i <= n;i++)
    {
        int vt;
        for (int j = 1;j <= n;j++)
            if (a[j] == i)
            {
                vt = j;break;
            }
        while (a[vt] < a[vt - 1] && vt > 1)
        {
            swap(a[vt],a[vt - 1]);vt--;d++;
        }
    }
    cout << d % mod;
}
