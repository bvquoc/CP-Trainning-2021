#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
#define oo 1000000000
#define MAXN 2001
#define ll long long
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define PR(x,a,b) {cout<<#x<<' '; for(long long i=a;i<=b;i++) cout<<x[i]<<' '; cout<<'\n'; }
#define all(x) x.begin(),x.end()
#define pb push_back
#define taskname "GIFT11"
#define fi first
#define se second
#define base 998244353

int n;
string a[MAXN];

void read()
{
    cin>>n;
    FOR(i,1,n) cin>>a[i];
}

long long kq;
int sChan[MAXN];
int sLe[MAXN];

void init()
{
    kq=0;
    FOR(i,1,n)
    {
        sChan[i]=0;
        sLe[i]=0;
        FOR(j,0,int(a[i].size())-1)
        {
            if((j+1)%2==0) sChan[i]+=a[i][j]-'0';
            else sLe[i]+=a[i][j]-'0';
        }
    }
}

bool check[MAXN];
int luu[9];

void xet()
{
    string digit;
    int chan=0;
    int le=0;
    FOR(i,1,n)
    {
        digit+=a[luu[i]];
    }
    FOR(i,0,int(digit.size())-1)
    {
        if((i+1)%2==0) chan+=digit[i]-'0';
        else le+=digit[i]-'0';
    }
    if((le-chan)%11==0) kq++;
}

void sinh(int idx)
{
    FOR(i,1,n)
    {
        if(check[i]==false)
        {
            check[i]=true;
            luu[idx]=i;
            if(idx==n) xet();
            else sinh(idx+1);
            check[i]=false;
        }
    }
}

void sub2()
{
    int sumChan=0, sumLe=0;
    FOR(i,1,n)
    {
        sumChan+=sChan[i];
        sumLe+=sLe[i];
    }
    if((sumLe-sumChan)%11==0)
    {
        kq=1;
        FOR(i,1,n)
        {
            kq=(kq*i)%base;
        }
    }
    else kq=0;
}

void sub3()
{
    kq=0;
}

void solve()
{
    if(n<=10) sinh(1);
    else
    {
        bool chan,le;
        FOR(i,1,n)
            if(a[i].size()%2) le=true;
            else chan=true;
        if(chan==true&&le==false)
        {
            sub2();
        }
        else if(chan==false&&le==true)
        {
            sub3();
        }
    }
}

void write()
{
    cout<<kq<<'\n';
}

int main()
{
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        //cout<<1<<'\n';
        read();
        init();
        solve();
        write();
    }
    return 0;
}
