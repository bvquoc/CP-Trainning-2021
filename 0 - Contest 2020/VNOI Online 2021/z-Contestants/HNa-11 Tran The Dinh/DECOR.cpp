#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
const int N=5e5+7;
int n,m,k;
char a[N];
void inp()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
}
void sub1()
{
    int L,res=0,dem=1,resL,resR;
    for(int i=1;i<=n;++i)
    {
        if(a[i]=='1' && a[i-1]=='1') ++dem;
        else
        {
            if(a[i]=='1')
            {
                L=i;
                dem=1;
            }
            else dem=0;
        }
        if(dem>res)
        {
            resR=i;
            resL=L;
            res=dem;
        }
    }
    cout<<resL<<' '<<resR;
}
int dem[N];
void sub2()
{
    int tmp=k,L,R,res=0,resR,resL;
    queue<int> q;
    dem[0]=0;
    for(int i=1;i<=n;++i)
    {
        dem[i]=dem[i-1];
        if(a[i]=='0')
        {
            if(!tmp)
            {
                dem[i]-=dem[q.front()];
                a[q.front()]='0';
                q.pop();
                a[i]='1';
                q.push(i);
            }
            else
            {
                q.push(i);
                --tmp;
                a[i]='1';
            }
        }
        if(a[i]=='1' && a[i-1]=='1') ++dem[i];
        else
        {
            if(a[i]=='1')
            {
                L=i;
                dem[i]=1;
            }
            else dem[i]=0;
        }
        if(dem[i]>res)
        {
            resR=i;
            resL=L;
            res=dem[i];
        }
    }
    cout<<resL<<' '<<resR<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    inp();
    if(m==0 && k==0)
    {
        sub1();
        return 0;
    }
    sub2();
    return 0;
}
