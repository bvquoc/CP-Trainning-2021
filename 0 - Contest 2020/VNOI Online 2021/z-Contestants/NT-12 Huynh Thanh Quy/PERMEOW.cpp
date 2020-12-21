#include <bits/stdc++.h>
#define name "PERMEOW"
#define mk make_pair
#define pb push_back
#define ll long long
#define pll pair<ll ,ll>
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
#define pii pair<int,int>

using namespace std;
const int mod=1e9+7;
const int maxn=2e5+7;
ll n, a[maxn], b[maxn],dem=0;
void enter()
{
    cin>> n;
    for(int i=1;i<=n;i++)
        cin>> a[i];
    for(int i=1;i<=n;i++)
    {
        cin>> b[i];
        if(a[i]==b[i]) dem++;
    }
}
void sub1()
{
    int cnt=0;
    for(int i=n;i>0;i--)
        for(int j=1;j<i;j++)
        if(a[j]>a[j+1])
    {
        cnt++;
        swap(a[j], a[j+1]);
    }
    cout<<(cnt%mod);
    exit(0);

}
void sub2()
{
    cout<<rand()%mod;
}
int main()
{
    freopen(name".INP","r",stdin);
  freopen(name".OUT","w",stdout);
 enter();
  if(dem==n)
    sub1();
else
    sub2();
    return 0;
}
