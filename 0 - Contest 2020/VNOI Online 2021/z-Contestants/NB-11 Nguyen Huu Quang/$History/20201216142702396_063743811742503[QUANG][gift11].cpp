#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
string s[100005];
vector<int> v;
int t,n;
void solve1()
{
        long long res=0;
        v.resize(0,n);
        for(int i=1;i<=n;i++) v.push_back(i);
         while(next_permutation(v.begin(),v.end()))
        {
            string s2="";
            long long tl=0;
            long long tc=0;
            for(auto x:v) s2=s2+s[x];
            int n1=s2.length();
            for(int i=0;i<n1;i++)
            {
                if(i%2==0) tc=tc+(s2[i]-'0');
                else tl=tl+(s2[i]-'0');
            }
            if((tl-tc)%11==0) res=(res+1)%mod;
        }
        cout<<res<<"\n";
}
void solve2()
{
    long long res=1;
    long long tl=0;
    long long tc=0;
    for(int i=1;i<=n;i++)
    {
        string s2=s[i];
        int n1=s2.length();
        for(int j=0;j<n1;j++)
        {
            if(j%2==0)
            {
                int gt=s2[j]-'0';
                tl=tl+gt;
            }
            else
            {
                int gt=s2[j]-'0';
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
    else cout<<0<<"\n";
}
int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    cin>>t;
    while(t>0)
    {
        t--;
        int p=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            int sl=s[i].length();
            if(sl%2==1) p=1;
        }
        if(n<=8)
            solve1();
            else
        if(p==0)
            solve2();
            else solve1();
    }
}
