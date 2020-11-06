#include <bits/stdc++.h>

using namespace std;

typedef pair <int,int> pii;
int n,k,p,q,dp;
long long res=0;
pii a[10000];
bool kt[10000];

int cmp(pii x, pii y)
{
    return(x.first>y.first);
}

bool check(int x)
{
    for (int i=1; i<=k-1; i++)
      if (i+x<=n)
        if (kt[x+i]==true) return false;
    for (int i=1; i<=k-1; i++)
        if (x-i>0 && kt[x-i]==true) return false;
    return true;
}

int main()
{
    cin>>n>>k>>q>>p;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i].first;
            a[i].second=i;
        }
    sort(a+1,a+1+n,cmp);
    for (int i=1; i<=n; i++)
    {
        int c=min(p,q);
        if (check(a[i].second))
        {
            res+=c*a[i].first;
            kt[a[i].second]=true;
            q-=c;
        };
    }
    cout<<res;
}
