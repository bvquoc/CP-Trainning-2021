#include<bits/stdc++.h>
#define l first
#define r second
const int N=2003;
int q,n,b[N],a[N];
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    cin>>q;
    while (q--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) {cin>>a[i];b[i]=i;}
        int res=0;
        bool ok=0;
        do
        {
            int sum=0;
            int k=1;
            for (int i=1;i<=n;i++)
            {
                sum+=a[b[i]]*k;
                k*=10;
            }
            if (sum%11==0) ok=1,res=(res+1)%998244353;
        }
        while (next_permutation(b+1,b+n+1));
        cout<<res<<"\n";
    }
}
