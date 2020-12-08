#include <bits/stdc++.h>
#define PII pair<int,int>
#define LL long long
#define F first
#define S second
using namespace std;
const int val[10]={0,1,2,1,2,1,2,3,2,3};
int q,a[12];
int cal(int x)
{
    int res=0,power=2;
    int cnt=0;
    while (x>0) a[++cnt]=x%10,x/=10;
    for (int i=1;i<=cnt;i++)
    {
        if (i<6) res+=val[a[i]];
        else res+=power*a[i],power*=10;
    }
    return res;
}
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    cin>>q;
    while (q--)
    {
        int x,t,res=1e9;
        cin>>x>>t;
        int gh=min(t/x,100000);
        for (int i=0;i<=gh;i++) res=min(res,cal(t-i*x)+i);
        cout<<res<<"\n";
    }
    return 0;
}
