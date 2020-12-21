#include <bits/stdc++.h>
#define ll long long
#define nmax 2010
#define eb emplace_back
#define pb push_back

const ll oo=998244353;
using namespace std;
int test,n,sl,tong,a[nmax],b[nmax],c[nmax];
ll res,gt[nmax],f[nmax][nmax][11];
int dcs(int x)
{
    int ans=0;
    while (x>0)
    {
        ans++; x/=10;
    }
    return ans;
}
int cal(int x)
{
    vector<int> vt; int ans=0;
    while (x>0)
    {
        vt.pb(x%10);
        x/=10;
    }
    reverse(vt.begin(),vt.end());
    for (int e=0;e<(int)vt.size();e++)
        if (e%2==0) ans+=vt[e];
    else ans-=vt[e];
    return ans;
}
void sub1()
{
    vector<int> vt; res=0;
    for (int i=1;i<=n;i++) vt.pb(i);
    sort(vt.begin(),vt.end());
    do
    {
        int du=0; bool dau=1;
        for (int i=0;i<n;i++)
        {
            int x=a[vt[i]];
            if (dau) du=(du+cal(x)+99)%11;
            else du=(du-cal(x)+99)%11;
            if (dcs(x)%2==1) dau^=1;
        }
        if (du==0) res=(res+1)%oo;
    }
    while (next_permutation(vt.begin(),vt.end()));
    cout<<res<<'\n';
}
void sub2()
{
    if (tong%11>0) cout<<0<<'\n';
    else
    {
        res=1;
        for (int i=1;i<=n;i++) res=res*i%oo;
        cout<<res<<'\n';
    }
}
void sub3()
{
    for (int i=0;i<=n;i++) f[i][0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=sl;j++)
            for (int du=0;du<11;du++)
            {
                int dum=(du-b[i]+99)%11;
                f[i][j][du]=(f[i-1][j][du]+f[i-1][j-1][dum])%oo;
            }

    res=0;
    for (int du=0;du<11;du++)
    {
        ll tam=0;
        if ((2*du-tong)%11==0)
        {
            tam=f[n][sl][du];
            tam=(tam*gt[sl])%oo;
            tam=(tam*gt[n-sl])%oo;
        }
        res=(res+tam)%oo;
    }
    cout<<res<<'\n';
}
bool kt2()
{
    for (int i=1;i<=n;i++)
        if (c[i]%2==1) return 0;
    return 1;
}
bool kt3()
{
    for (int i=1;i<=n;i++)
        if (c[i]%2==0) return 0;
    return 1;
}
void sinh()
{
    ofstream out("gift11.inp");
    out<<1<<'\n';
    n=rand()%8+1; out<<n<<'\n';
    for (int i=1;i<=n;i++)
    {
        int sl=rand()%4+1; sl=sl*2;
        for (int j=1;j<=sl;j++)
        {
            int so;
            if (j>1) so=rand()%10;
            else so=rand()%9+1;
            out<<so;
        }
        out<<" ";
    }
    out.close();
}
int main()
{
    srand(time(NULL));
    //sinh();
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    gt[0]=1;
    for (int i=1;i<=2000;i++) gt[i]=gt[i-1]*i%oo;
    cin>>test;
    while (test--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];

        sl=ceil(1.0*n/2); tong=0;
        for (int i=1;i<=n;i++)
        {
            int x=a[i];
            c[i]=dcs(x); b[i]=cal(x);
            tong=(tong+b[i]+99)%11;
        }
        if (n<=8)
        {
            sub1();
            continue;
        }
        if (kt2())
        {
            sub2();
            continue;
        }
        if (kt3())
        {
            sub3();
            continue;
        }
    }
    return 0;
}
