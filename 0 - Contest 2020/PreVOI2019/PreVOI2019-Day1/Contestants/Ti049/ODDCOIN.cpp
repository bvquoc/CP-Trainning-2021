///EmperorD: @npd.28
#include <bits/stdc++.h>
#define EmperorD "ODDCOIN"
#define ll long long
#define ull unsigned long long
#define el '\n'
#define fi first
#define se second
#define pll pair<long long, long long>
#define pii pair<int,int>
#define piii pair<int,pii>
#define mp make_pair
#define pb push_back
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define forv(a,b) for(auto &a:b)
#define reset(f,x) memset(f,x,sizeof(f))
#define mod 10000007
using namespace std;
const int oo=1e9+7;

int get()
{
    int tmp = 0;
    char x = getchar();
    bool Neg = false;
    while(x == ' ' || x == '\n')
        x = getchar();
    if(x == '-')
        Neg = true, x = getchar();
    while('0' <= x && x <= '9')
        tmp = tmp * 10 + (x - '0'), x = getchar();
    if(Neg)
        return -tmp;
    return tmp;
}
int q,x,t;
int a[20];
int f[20][100009];
void sub1()
{
    int res=oo;
    int temp;
    for (int i1=0;i1<=20;i1++)
        for (int i3=0;i3<=7;i3++)
            for (int i5=0;i5<=4;i5++)
                for (int i10=0;i10<=2;i10++)
                    for (int ix=0;ix<=20;ix++)
    {
        temp=1*i1+3*i3+5*i5+10*i10+x*ix;
        if (temp==t) res=min(res,i1+i3+i5+i10+ix);
    }
    cout <<res<<el;
    return;
}
void solve()
{
    q=get();
    while(q--)
    {
        x=get();
        t=get();
        a[1]=1;
        a[2]=3;
        a[3]=5;
        a[4]=10;
        a[5]=30;
        a[6]=50;
        a[7]=100;
        a[8]=300;
        a[9]=500;
        a[10]=1000;
        a[11]=3000;
        a[12]=5000;
        a[13]=10000;
        a[14]=30000;
        a[15]=50000;
        a[16]=x;
        sort(a+1,a+16+1);
        if (x<=20 && t<=20)
        {
            sub1();
            continue;
        }
        for(int i=1;i<=16;i++)
            for(int j=1;j<=100005;j++) f[i][j]=0;
        for (int j=0;j<=t;j++) f[0][j]=oo;
        for(int i=1;i<=16;i++)
            for (int j=1;j<=t;j++)
        {
            f[i][j]=f[i-1][j];
            if (j%a[i]==0) f[i][j]=j/a[i];
            else f[i][j]=min(f[i][j-j%a[i]]+f[i][j%a[i]],f[i][j]);
        }
        cout <<f[16][t]<<el;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen (EmperorD".inp","r",stdin);
    freopen (EmperorD".out","w",stdout);
    solve();
    return 0;
}
