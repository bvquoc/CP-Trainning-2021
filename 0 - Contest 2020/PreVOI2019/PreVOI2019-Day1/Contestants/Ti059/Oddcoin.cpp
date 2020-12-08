#include <bits/stdc++.h>
#define int1 long long
using namespace std;
int1 n,a[100]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000},dem=14,sl;
int1 dem1;
int1 x,y;
int1 s[100];
void up()
{
    int1 y1=y;
    int1 kq=0;
    for(int i=dem1;i>=0;i--)
        if(s[i]==1)
        {
            int s1;
            s1=y1/a[i];
            kq+=s1;
            y1-=s1*a[i];
        }
    if(kq!=0 && y1==0)
        sl=min(kq,sl);
}
void dq(int u)
{
    for(int i=0;i<=1;i++)
    {
        s[u]=i;
        if(u==dem1 || a[u]>=y) up();
            else dq(u+1);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    cin >> n;
    while(n-->0)
    {
        cin >> x >> y;
        dem++;
        a[dem]=x;
        sort(a,a+dem+1);
        dem1=lower_bound(a,a+dem+1,y)-a;
        sl=1000000000;
        dq(0);
        cout << sl << endl;
    }
    return 0;
}
