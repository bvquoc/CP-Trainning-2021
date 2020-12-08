#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i = a; i <= b; ++i)
#define fordec(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define nmax 1000005
#define pb push_back
#define task "oddcoin"
#define endl '\n'
#define reset(x) memset(x,0,sizeof(x))
#define MOD 1000000007
#define mp make_pair
using namespace std;
int q, t, x, a[20], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>q;
    while(q--){
        a[1]=1; a[2]=3; a[3]=5; a[4]=10; a[5]=30; a[6]=50; a[7]=100; a[8]=300; a[9]=500; a[10]=1000; a[11]=300; a[12]=5000; a[13]=10000;
        a[14]=30000; a[15]=50000;
        ans=MOD;
        cin>>x>>t;
        a[16]=x;
        sort(a+1,a+16+1);
    for(int i=1;a[i]<=t&&i<=16;i++){
        int tg=t, res=0;
        for(int j=i;j>=1;j--) if(tg>=a[j]){res+=tg/a[j]; tg=tg%a[j];}
        ans=min(ans,res);
       }
       cout<<ans<<'\n';
    }
    return 0;
}
