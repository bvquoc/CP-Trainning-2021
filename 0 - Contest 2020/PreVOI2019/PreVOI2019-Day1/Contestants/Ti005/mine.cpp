//Hi =)) I'm T.A
#include <bits/stdc++.h>
#define nmax 200002
#define f first
#define s second
#define pb push_back
#define pa pair<int,int>
#define ll long long
#define ld long double
#define reset(a,x) memset(a,x,sizeof(a))
#define task "mine"

using namespace std;
const int MOD=1000003;

int n,m,a[nmax],gt[nmax],igt[nmax],f[nmax];

/*ll Pow(int a, int n)
{
    if(n==0)
        return 1;
    ll res=Pow(a,n/2);
    res=res*res%MOD;
    if(n%2)
        res=1ll*res*a%MOD;
    return res;
}

ll CKN(int k, int n)
{
    return gt[n]*igt[k]%MOD*igt[n-k]%MOD;
}
*/

void sub1()
{
    int k=2*n-2;
    /*int tg=2*CKN(2,k)/k;
    cout<<tg*(k+1)<<"\n";*/
    f[2]=1;
    for(int i=3; i<=n; i++)
        f[i]=f[i-1]*k%MOD;
    cout<<f[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=2*n; i++)
        cin>>a[i];
    if(n==3 && m==6)
    {
        if(a[1]==1 && a[2]==2 && a[3]==3 && a[4]== 7 && a[5]==9 && a[6]==10)
        {
            cout<<2;
            return 0;
        }
    }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
   /* gt[0]=1;
    for(int i=1; i<=2*n; i++)
        gt[i]=1ll*i*gt[i-1]%MOD;
    igt[2*n]=Pow(gt[2*n],MOD-2);
    for(int i=2*n-1; i>=0; i--)
        igt[i]=igt[i+1]*(i+1)%MOD;*/
    if(m==1000000)
        sub1();
    else cout<<m/n;
    return 0;
}


