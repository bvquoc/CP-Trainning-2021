#include<bits/stdc++.h>
#define name "GIFT11"
#define ios  ios_base::sync_with_stdio(false); cin.tie(0);
#define pii pair<int , int >
#define ll long long
using namespace std;
const ll mod=998244353;
int t , a[11],s=0,f[11][2002],mx=0;
string st[11][2001];
int cb(int i , int  j)
{
    int le =0, chan=0;
    for(int k=1;k<=st[i][j].size();k++)
    {   int l=st[i][j].size()-k;
        if(k%2==1)
        le+=(st[i][j][l]-'0');
    else
        chan+=(st[i][j][l]-'0');
    }
    return (le-chan);
}
void enter()
{
    cin>> t;
    for(int i=1;i<=t;i++)
    {
        cin>> a[i];
        mx=max(a[i],mx);
        s+=a[i];
        for(int j=1;j<=a[i];j++)
            {cin>> st[i][j];
                f[i][j]=cb(i,j);}
    }
}

void sub1()
{
    for(int i=1;i<=t;i++)
    {
        int sz=a[i];
        int b[sz+1]; for(int j=1;j<=sz;j++) b[j]=sz+1-j;
        ll res=0;
        do{
            int cnt=f[i][b[1]];
            int  m=(st[i][b[1]].size());
            for(int j=2;j<=sz;j++)
                {
                    if(m%2==0) {cnt+=f[i][b[j]]; m+=(st[i][b[j]].size());}
                    else  {cnt-=f[i][b[j]];  m+=(st[i][b[j]].size());}
                }
             if(cnt%11==0) res++;


        }while(prev_permutation(b+1, b+sz+1));
        res%=mod;
         cout<<res<<endl;
    }

}
void sub2()
{
    for(int i=1;i<=t;i++)
    {
        int cnt=0;

        for(int j=1;j<=a[i];j++)
        cnt+=f[i][j];
        if(cnt%11==0)
        {
             ll res=1;
            for(int k=a[i];k>0;k--)
                res=(res*k)%mod;
                 cout<<res<<endl;

        }

    }
}
int main()
{
     freopen(name".INP","r",stdin);
   freopen(name".OUT","w",stdout);
        enter();
    if(s<=50)
    {   if(mx<=10)
        sub1();
        else sub2();
    }
   else
    sub2();
    return 0;
}
