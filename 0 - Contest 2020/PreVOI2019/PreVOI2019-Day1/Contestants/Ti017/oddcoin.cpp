#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,x,t;
int a[22],n=15;
int tinh(int s)
{
    //cerr<<s<<'\n';
    if(s==0)return 0;
    int tmp=2e9+1;
    for(int i=1;i<=n;i++)
        if(s>=a[i])
    {
        tmp=min(tmp,s/a[i]+tinh(s%a[i]));
    }
    return tmp;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    cin>>q;
    a[1]=1;a[2]=3;a[3]=5;
    for(int i=4;i<=15;i++)a[i]=a[i-3]*10;
    while(q--)
    {
        cin>>x>>t;
        int l=upper_bound(a+1,a+n+1,x)-a;
        for(int i=n;i>=l;i--)a[i+1]=a[i];
        a[l]=x;
        n++;
        cout<<tinh(t)<<'\n';
        n--;
        for(int i=l;i<=n;i++)a[i]=a[i+1];
    }
    return 0;
}
