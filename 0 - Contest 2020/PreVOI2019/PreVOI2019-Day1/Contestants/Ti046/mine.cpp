#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define name "mine"
#define ll long long
#define maxn 200005
#define maxm 1000006
#define mod 1000003

using namespace std;

int n,m,a[2*maxn],b[4005][4005],c[maxn],d[4005][4005];
bool xd1[4005][4005],xd2[4005][4005];

int solve1(int x,int y)
{
    if(x>y)
    {
        return 1;
    }
    if(xd1[x][y]==1)
    {
        return b[x][y];
    }
    xd1[x][y]=1;
    if(x+1==y)
    {
        if(a[y]-a[x]<=m)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    for(int i=x;i<y;i+=2)
    {
        if(a[y]-a[i]<=m)
        {
            b[x][y]+=solve1(i+1,y-1)*solve1(x,i-1);
            b[x][y]%=mod;
        }
    }
    return b[x][y];
}

void sub1()
{
    c[0]=c[1]=1;
    f(i,2,n)
    {
        f(j,1,i)
        {
            c[i]+=c[i-j]*c[j-1];
            c[i]=c[i]%mod;
        }
    }
    cout<<c[n];
}
void sub2()
{
    cout<<solve1(1,2*n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);

    cin>>n>>m;
    f(i,1,2*n)
    {
        cin>>a[i];
    }
    if(m>=a[2*n])
    {
        sub1();
    }
    else
    {
        sub2();
    }



}
