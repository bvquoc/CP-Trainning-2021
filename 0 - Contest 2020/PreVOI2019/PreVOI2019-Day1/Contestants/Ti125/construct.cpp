#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mn=1e5+8;
const int oo=1e9;
int n,m,T;
int a[mn];
template<class T>
inline void read(T &x)
{
    x=0;
    char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))
        x=x*10+c-'0',
        c=getchar();
}
//---------------------------------
int tinh(int l,int r,int val)
{
    if(l>r)return 0;
    if(l==r)
        return a[l]-val;
    int res=0;
    int x=oo;
    for(int i=l;i<=r;i++)
        x=min(x,a[i]);
    int tr=l;
    for(int i=l;i<=r;i++)
    if(a[i]==x)
    {
        res=res+tinh(tr,i-1,x);
        tr=i+1;
    }
    res=res+tinh(tr,r,x)+x-val;
    return res;
}

void sub1()
{
    read(n);
    read(m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    while(m--)
    {
        int x;
        read(x);
        if(x==1)
        {
            int l,r,k;
            read(l);
            read(r);
            read(k);
            for(int i=l;i<=r;i++)
                a[i]+=k;
        }
        else
        {
            int l,r;
            read(l);
            read(r);
            cout<<tinh(l,r,0)<<'\n';
        }
    }
}
//-------------------------
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    read(T);
    while(T--)
    {
        sub1();
    }
}
