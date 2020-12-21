#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;
const int N=1e5+12;
pair<int, int> a[N];
int n;
vector <int> v;
int m[N];
int tknp(int val)
{
    int l=1, r=n;
    int ans;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (a[mid].l<=val)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
int main()
{
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].l>>a[i].r;
    }
    sort(a+1,a+n+1);
    int cnt=n;
    for(int i=1; i<n; i++)
    {
        if (a[i+1].r<a[i].r)
        {
            a[i+1]=a[i];
            cnt--;
        }
    }
    unique(a+1,a+n+1);
    n=cnt;
    fill(m+1,m+N+1,0);
    for(int i=1; i<=n; i++)
    {
        m[a[i].l]++;
        m[a[i].r+1]--;
    }
    for(int i=1; i<=N-12; i++)
    {
        m[i]+=m[i-1];
        if (m[i]==0) v.push_back(i);
    }
    cin>>cnt;
    int minn=1000000;
    for(int i=1; i<=cnt; i++)
    {
        int x;
        cin>>x;
        if (minn>x) minn=x;
    }
    if (v.empty())
    {
        int pos=tknp(minn);
        cout<<n-pos+1;
        return 0;
    }
    int pos=lower_bound(v.begin(),v.end(),minn)-v.begin();
    if (v[pos]>=minn)
    {
        cout<<-1;
        return 0;
    }
    else
    {
        int pos=tknp(minn);
        cout<<n-pos+1;
    }
}
