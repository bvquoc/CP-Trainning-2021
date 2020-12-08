/// !! Killian !! ///

#include <bits/stdc++.h>
#define Killian "PAINT"
#define MOD 1000000007
#define endl "\n"
#define pii pair <int,int>
using namespace std;
map <char,int> sz;
map <char,int> p;
map <char,char> cnt;
int n,j=1;
int turn[1000005];
char f[1000005];
void Init()
{
    for (char i='a'; i<='z'; i++)
        p[i]=(char)i;
}
int Find(char u)
{
    if (p[u]==u)
        return u;
    return p[u]=Find(p[u]);
}
void Group (char u,char v)
{
    if (u==v)
        return;
    sz[v]+=sz[u];
    p[u]=v;
    sz[u]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    Init();
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            char c;
            cin>>c;
            sz[c]++;
            f[j]=c;
            turn[j]=i;
            j++;
        }
        else
        {
            char a,b;
            cin>>a>>b;
            Group(a,b);
            cnt[a]=i;
        }
    }
    for (int i=1; i<=j-1; i++)
    {
        if (cnt[(char)f[i]]>0 && cnt[(char)f[i]]>=turn[i])
            cout<<(char)Find(f[i]);
        else
            cout<<(char)f[i];
    }
}
