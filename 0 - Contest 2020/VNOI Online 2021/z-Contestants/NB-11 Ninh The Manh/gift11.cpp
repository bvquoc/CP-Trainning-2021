#include<bits/stdc++.h>
using namespace std;
int t,n;
long long mod=998244353;
string s[100005];
vector<int> g;
void solve1()
{
    long long res=0;
        g.resize(0,n);
        for(int i=1;i<=n;i++)
            {
                g.push_back(i);
            }
        do
        {
            string ss="";
            long long tl=0;
            long long tc=0;
            for(auto x:g)
               ss=ss+s[x];
            int n1=ss.length();
            for(int i=0;i<=n1-1;i++)
            {
                if(i%2==0) tc=tc+(ss[i]-'0');
                else tl=tl+(ss[i]-'0');
            }
            if((tl-tc)%11==0) res=(res+1)%mod;
        }
        while(next_permutation(g.begin(),g.end()));
        cout<<res<<"\n";
}
void solve2()
{
    long long tl=0;
    long long tc=0;
    long long res=1;
    for(int i=1;i<=n;i++)
    {
        string ss=s[i];
        int n1=ss.length();
        for(int j=0;j<=n1-1;j++)
        {
            if(j%2==0)
            {
                int gt=ss[j]-'0';
                tl=tl+gt;
            }
            else
            {
                int gt=ss[j]-'0';
                tc=tc+gt;
            }
        }
    }
    if((tl-tc)%11==0)
    {
        for(int i=1;i<=n;i++)
            res=res*i%mod;
            cout<<res<<"\n";
    }
    else
        cout<<0<<"\n";
}
int main()
{
  freopen("gift11.inp","r",stdin);
  freopen("gift11.out","w",stdout);
    cin>>t;
    while(t>0)
    {
        t--;
        int fl=0;
        long long tl=0;
        long long tc=0;
        long long res=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            int sl=s[i].length();
            if(sl%2==1) fl=1;
        }
        if(n<=8)
            solve1();
        if(fl==0)
            solve2();
    }
}
