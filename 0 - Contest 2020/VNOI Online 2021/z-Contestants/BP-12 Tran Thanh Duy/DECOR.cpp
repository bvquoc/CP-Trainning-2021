#include<bits/stdc++.h>
using namespace std;
ifstream fi("DECOR.inp");
ofstream fo("DECOR.out");
typedef pair<int,int>II;
#define ff first
#define ss second
#define mp make_pair
const int nmax=5e5+5;
int n,m,k,kq,a[nmax],sum[nmax];
II C[nmax];
string s;
void sub1()
{
    int sl=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]==1) ++sl;
        if(a[i]==0)
        {
            kq=max(kq,sl);
            sl=0;
        }
    }
    kq=max(kq,sl);
    fo<<kq;
}
void sub2()
{
    for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];

}
int main()
{
    fi>>n>>m>>k;
    fi>>s;
    for(int i=0;i<=n-1;++i) a[i+1]=s[i]-'0';
    for(int i=1;i<=m;++i)
    {
        fi>>C[i].ff>>C[i].ss;
    }
    sub1();
}
