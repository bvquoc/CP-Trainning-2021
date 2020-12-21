#include <bits/stdc++.h>
using namespace std;
const int N=2005;
const int mod=998244353;
int n;
long long res;
bool used[N];
string s[N];
void inp()
{
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>s[i],used[i]=0;
}
string S;
int first;
void check()
{
    int tmp=0;
    for(int i=0; i<S.size(); ++i)
        if((i&1)) tmp+=S[i]-'0';
        else tmp-=S[i]-'0';
    if(!tmp)
        ++res;
    S=s[first];
}
void tri(int pos)
{
    if(pos==n+1)
    {
        check();
        return;
    }
    for(int i=1;i<=n;++i)
    if(!used[i])
    {

        if (pos==1)
        {
            first=i;
            S="";
        }
        used[i]=1;
        S+=s[i];
        tri(pos+1);
        used[i]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {

        inp();
        res=0;
        if(n<=10)
        {
            tri(1);
            cout<<res%mod<<'\n';
            continue;
        }
    }
    return 0;
}
