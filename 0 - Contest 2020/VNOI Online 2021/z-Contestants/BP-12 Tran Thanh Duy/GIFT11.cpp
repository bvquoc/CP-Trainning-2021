#include<bits/stdc++.h>
using namespace std;
ifstream fi("GIFT11.inp");
ofstream fo("GIFT11.out");
const int nmax=2e3+5;
const int mode=998244353;
int t,n,a[nmax],kq;
struct II
{
    int chan,le;
    II()
    {
        chan=0;
        le=0;
    }
};
II C[nmax];
II tinh(int n)
{
    II tong;
    int sl=0;
    while(n>0)
    {
        ++sl;
        if(sl%2==1) tong.le+=n%10;
        else tong.chan+=n%10;
        n=n/10;
    }
    return tong;
}
void np(int i,int chenh_lech)
{
    if(i>n)
    {
        if(chenh_lech%11==0) ++kq;
        kq=kq%mode;
        return;
    }
    for(int j=0;j<=1;++j)
    {
        if(j==0)
        {
            np(i+1,chenh_lech);
        }
        if(j==1)
        {
            np(i+1,chenh_lech+abs(C[i].chan-C[i].le));
        }
    }
}
int main()
{
    fi>>t;
    for(int i=1;i<=t;++i)
    {
        kq=0;
        fi>>n;
        for(int j=1;j<=n;++j) fi>>a[j];
        for(int j=1;j<=n;++j)
        {
            C[j]=tinh(a[j]);
        }
        np(1,0);
        fo<<kq-1<<"\n";
    }
}
