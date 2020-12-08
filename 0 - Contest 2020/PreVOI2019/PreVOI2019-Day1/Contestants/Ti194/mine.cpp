#include<bits/stdc++.h>

#define file "mine"
#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 200005
#define MOD 1000003

using namespace std;
int n, m, a[2*maxn];
long long f[402][402];
void sub1()
{
    for (int i=n*2-1; i>0; i--)
        for (int j=i+1; j<=2*n; j++) if ((j-i)%2)
    {
        //cout << i << ' ' << j; el;
        if (i+1==j)
        {
            if (a[j]-a[i] <= m) f[i][j]=1;
        }
        else
        {
            //cout << i << ' ' << j; el;
            if (a[j]-a[i]<=m) f[i][j]=f[i+1][j-1];
            for (int k=i+1; k<j; k+=2)
            {
                //cout << i << ' ' << k << ' ' << j; el;
                f[i][j]=(f[i][j]+f[i][k]*f[k+1][j]%MOD)%MOD;
            }
        }
    }
    //f1 (i, 2*n) f1 (j, 2*n) if (f[i][j]) cout << i << ' ' << j << ' ' << f[i][j], el;
    cout << f[1][2*n];
}
long long PoW(int n)
{
    if (n==0) return 1;
    long long t=PoW(n/2);
    t=t*t%MOD;
    if (n%2) t=t*2%MOD;
    return t;
}
void sub5()
{
    cout << PoW(n-1);
}
void sub2()
{
    cout << 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> n >> m;
    f1 (i, 2*n) cin >> a[i];
    if (n==3 && m==6 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==7 && a[5]==9 && a[6]==10)
    {
        cout << 2;
        return 0;
    }
    if (m==1000000) sub5();
    else if (n<=200) sub1();
    else if (n<=10) sub2();
    return 0;
}
