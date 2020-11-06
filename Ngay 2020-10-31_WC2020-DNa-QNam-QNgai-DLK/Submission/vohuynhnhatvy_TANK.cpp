#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n,M;
long long sum[N];

bool kt(int l)
{
    for (int i=1;i<=n-l;i++)
        if (sum[i+l-1]-sum[i-1]<M) return false;
    return true;
}
int main()
{
//    #ifndef ONLINE_JUDGE
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
//    #endif // ONLINE_JUDGE
    cin>>M>>n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum[i] = sum[i-1]+a;
    }
    int l=1,r=n,mid;
    while (true)
    {
        mid=(l+r)/2;
       // cout<<mid<<" ";
        if (l==mid || r==mid) break;
        if (kt(mid))
            r=mid;
        else
            l=mid;
    }

   for (mid=l;mid<=r;mid++)
    {
        if (!kt(mid)) continue;
        cout<<mid;
        return 0;
    }

}

