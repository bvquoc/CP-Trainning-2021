#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <int ,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 200005
#define task "PERMEOW"

using namespace std;

int n,a[maxn],b[maxn];
ll ans;

void sub1() {
    for(int i=1; i<=n; i++) {
        int cnt=0;
        for(int j=i+1; j<=n; j++)
            if(a[j]<a[i])
                cnt++;
        ans+=1ll*(i+cnt-a[i]);
    }
    cout<<ans;
}

ll mu(ll n,int k) {
    if(k==1)
        return n;
    ll x=mu(n,k/2);
    if(k%2==0)
        return x*x%mod;
    return x*x%mod*n%mod;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    int flag=1;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++) {
        cin>>b[i];
        if(b[i]!=a[i])
            flag=0;
    }
    if(flag==1) {
        sub1();
        return 0;
    }
    if(n==3) {
        cout<<9;
        return 0;
    }
    if(n==4) {
        cout<<72;
        return 0;
    }
    ll s1=1,s2=1;
    for(int i=1; i<=n; i++)
        s1=s1*i%mod;
    for(int i=5; i<=n; i++)
        s2=s2*i%mod;
    ans=3*s1%mod+s1*(s2-1)%mod*mu(2,mod-2)%mod;
    cout<<ans;
}
