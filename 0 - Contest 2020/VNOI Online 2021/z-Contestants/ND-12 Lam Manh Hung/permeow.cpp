#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
vector<ll> v;
const ll M=1e9+7;
map<vector<ll>,int> m;
long a[200005],b[200005],n,tr[1000000];
void sub1()
{
    long ans=0,d;
    for(int i=1;i<=n;i++)
    {
        d=0;
        for(int j=1;j<i;j++) if(a[j]>a[i]) d++;
        ans+=abs((i-d)-a[i]);
    }
    cout<<ans;
}
void sub2()
{
  cout<<"hmu hmu";
}
int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    bool kt=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {cin>>b[i];if(a[i]!=b[i]) kt=0;}
    if(kt) {sub1();return 0;}
    if(n<=2000) {sub2();return 0;}
    for(int i=1;i<=n;i++) a[i]=i;
    do{
        for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<'\n';
    } while(next_permutation(a+1,a+n+1));
    return 0;
}
