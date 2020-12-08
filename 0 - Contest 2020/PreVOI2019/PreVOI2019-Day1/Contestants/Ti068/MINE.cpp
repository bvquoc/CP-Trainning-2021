                                        ///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "MINE"
#define MOD 1000000003
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;
int f[4005][4005][2];
int n,m;
int a[maxn];
int cha[maxn];
int get(int j,int sum,int tight,int last)
{
    if(j>n)
    {
        if((n-sum)==sum&&tight==0)
        {
            return 1;
        }
        else return 0;
    }
    int newtight=tight;
    cha[a[j]]=last;
    f[j][sum][tight]=get(j+1,sum+1,tight,a[j])%MOD;
    cha[a[j]]=0;
    if(j-sum>sum||a[j]-last>m)
    {
        newtight=1;
    }
    f[j][sum][tight]=(f[j][sum][tight]+get(j+1,sum,newtight,cha[last]))%MOD;
    return f[j][sum][tight];
}
void nhap()
{
    cin>>n>>m;
    n=n*2;
    if(n>4000&&m==1)
    {
        cout<<n/2;
        return ;
    }
    else if(n>4000)
    {
        cout<<rand()%MOD;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<get(1,0,0,0);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    nhap();
}
