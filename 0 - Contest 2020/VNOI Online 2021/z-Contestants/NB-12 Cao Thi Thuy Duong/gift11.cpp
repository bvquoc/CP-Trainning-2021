#include <iostream>
#include <bits/stdc++.h>
#define N 2222
using namespace std;
int t,n,m,res,b[N];
vector <int> g;
string x[N];
const long long mod=998244353;
void sub1()
{
    for (int i=1;i<=n;i++) {cin>>x[i];g.push_back(i);};
    do
    {
        int i=1;
     long long c=0,l=0;
    for (auto v:g)
    {
        for (int j=0;j<x[v].length();j++)
        {
            if (i%2==0) c+=x[v][j]-'0';
            else l+=x[v][j]-'0';
            l=l%mod;
            c=c%mod;
            i++;
        }
    }
         if ((l-c)%11==0) res=(res+1)%mod;

    }while (next_permutation(g.begin(),g.end()));
cout<<res;

}

void sub2()
{
    long long c=0,l=0;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for (int j=0;j<s.length();j++)
        {if (j%2==0) l+=s[j]-'0';
        else c+=s[j]-'0';
        l=l%mod;
        c=c%mod;
        }
    }
    if ((l-c)%11!=0) cout<<0;
    else
    {
        res=1;
        for (int i=1;i<=n;i++)
        res=(res*i)%mod;
        cout<<res;
    }

}

int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        if (n<=8) sub1();
        else sub2();

    }
}
