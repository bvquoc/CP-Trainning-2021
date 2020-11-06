#include<bits/stdc++.h>

using namespace std;

int n,k,q,p;
pair<int,int> v[10004];
bool cmp(pair<int,int> d, pair<int,int> e)
{
    return d.first>d.second;
}
int main()
{
//    #ifndef ONLINE_JUDGE
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
//    #endif // ONLINE_JUDGE
    cin >> n >> k >> q >> p;
    for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            v[i]={a,i};
        }
    sort (v+1,v+n+1,cmp);
    long long ans = 0;
    int j=v[1].second;
    for (int i = 1; i <= n; i++)
    {
        if (j+k<=v[i].second || j-k<=v[i].second)
        {
        ans+=min(q,p)*v[i].first;
        q-=min(p,q);
        j=i;
        }
    }
    cout<<ans;
}
