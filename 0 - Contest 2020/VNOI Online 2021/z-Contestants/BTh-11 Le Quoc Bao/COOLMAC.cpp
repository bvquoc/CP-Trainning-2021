#include <bits/stdc++.h>
using namespace std;

typedef pair <long long,long long> pii;
const long long maxN=1e5+10;

long long m,n,l=1,r,res=1;
long long a[maxN],f[maxN];
bool ok=false;
pii bao[maxN];

long long bs(long long l, long long r, long long val)
{
    long long mid,ans=0;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (bao[mid].first>val) r=mid-1;
        else if (bao[mid].first<val && bao[mid].second<val) l=mid+1;
        else if (bao[mid].first<=val && bao[mid].second>=val)
        {
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin >>m;
    for (long long i=1;i<=m;i++) cin >>bao[i].first>>bao[i].second;
    cin >>n;
    for (long long i=1;i<=n;i++) cin >>a[i];
    sort(bao+1,bao+m+1);
    sort(a+1,a+n+1);       reverse(a+1,a+n+1);
    for (long long i=1;i<=m;i++) f[i]=1;


    for (long long i=m;i>=1;i--)
        if (bao[i].first<=a[1] && bao[i].second==100000)
        {
            r=i;
            ok=true;
        }

    if (!ok)
    {
        cout <<-1;
        return 0;
    }

    priority_queue <long long,vector<long long>,greater<long long>> pq;
    pq.push(bao[r].first);
    for (long long i=2;i<=n;i++)
    {
        r=bs(l,r,a[i]);
        if (r==0)
        {
            cout <<-1;
            return 0;
        }
        if (f[r]==1)
        {
            res++;
            f[r]=0;
        }
    }
    cout <<res;
    return 0;
}
