#include <bits/stdc++.h>
using namespace std;

const int maxN=500005;
int n,res=0;
int a[maxN],b[maxN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin >>n;
    for (int i=1;i<=n;i++) cin >>a[i];
    for (int i=1;i<=n;i++) cin >>b[i];

    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (a[i]<a[j])
            {
                res++;
                swap(a[i],a[j]);
            }

    cout <<res;
    return 0;
}
