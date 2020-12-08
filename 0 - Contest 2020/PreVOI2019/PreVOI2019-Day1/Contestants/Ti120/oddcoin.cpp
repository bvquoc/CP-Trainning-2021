#include <bits/stdc++.h>
#define ll long long
#define hqm "oddcoin"
using namespace std;
int n, m ;
ll a[30];

void xuli(){
    ll x,t;
    cin >> x >> t;
    ll res=1e9;
    for(int i=0; i<=10; ++i){
        ll t1=t-x*i;
        if(t1<0)break;
        long long ans=i;
        for(int j=m; j>0; --j)
        ans+=t1/a[j],t1%=a[j];
        res=min(res,ans);
    }
    ll cnt=x/t;
    for(int i=0; i<=10 && cnt>=0; ++i, --cnt){
        ll t1=t-x*cnt;
        long long ans=cnt;
        for(int j=m; j>0; --j)ans+=t1/a[j],t1%=a[j];
        res=min(res,ans);
    }
    cout << res <<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(hqm".inp", "r", stdin);
    freopen(hqm".out", "w", stdout);
    int t=1;
    for(int i=0; i<=4; ++i){
        a[++m]=1*t;
        a[++m]=3*t;
        a[++m]=5*t;
        t*=10;
    }
    sort(a+1,a+m+1);
    //for(int i=1; i<=m; ++i) cout << a[i] <<endl;
    int q;
    cin >> q;
    while(q--)xuli();
    return 0;
}
