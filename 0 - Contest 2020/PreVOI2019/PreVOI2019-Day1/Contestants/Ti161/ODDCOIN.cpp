#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define fi first
#define se second
#define pii pair<int,int>
#define getbit(i,x) ((x>>i)&1)

const int maxn=1e6+5;
int q;
int x,t,cnt,res=2e9,X[20];
int a[]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int b[20],F[maxn];
vector<int> A;

main()
{
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    forinc(i,1,15) A.push_back(a[i]);
    cin>>q;
    while(q--)
    {
        cnt=0;
        cin>>x>>t;
        res=2e9;
        A.push_back(x);
        sort(A.begin(),A.end());
        forinc(i,0,t) F[i]=1e9;
        for(auto &v:A) {
            b[++cnt]=v;
            F[v]=1;
        }
        F[0]=0;
        forinc(i,4,t)
        {
            forinc(k,0,i)
            {
                F[i]=min(F[i],F[k]+F[i-k]);
            }
        }
        cout<<F[t]<<"\n";
    }
}
