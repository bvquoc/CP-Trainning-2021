//Hi =)) I'm T.A
#include <bits/stdc++.h>
#define nmax 1000002
#define f first
#define s second
#define pb push_back
#define pa pair<int,int>
#define ll long long
#define ld long double
#define reset(a,x) memset(a,x,sizeof(a))
#define task "paint"
using namespace std;

int n;
map<int,char>dd;
map<char,char> d;
vector<int>ans[nmax];

void xl2(char a, char b)
{
    for(int i=1; i<=n; i++)
    {
        if(!dd[i])
            break;
        if(dd[i]==a)
            dd[i]=b;
    }
}

void sub1()
{
    int cnt(0);
    for(int i=1; i<=n; i++)
    {
        int t;
        char a,b;
        cin>>t;
        if(t==1)
        {
            cin>>a;
            dd[++cnt]=a;
        }
        else
        {
            cin>>a>>b;
            xl2(a,b);
        }
    }
    for(int i=1; i<=n; i++)
        if(!dd[i])
            break;
        else
            cout<<dd[i];
}

void xl(char a, char b)
{
    int k=(int)a;
    int l=(int)b;
    for(auto v:ans[k])
        dd[v]=b,ans[l].pb(v);
}

void sub2()
{
    int cnt(0);
    for(int i=1; i<=n; i++)
    {
        int t;
        char a,b;
        cin>>t;
        if(t==1)
        {
            cin>>a;
            dd[++cnt]=a;
            int k=(int)a;
            ans[k].pb(cnt);
        }
        else
        {
            cin>>a>>b;
            if(a==b)
                continue;
            xl(a,b);
        }
    }
    for(int i=1; i<=n; i++)
        if(!dd[i])
            break;
        else
            cout<<dd[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    if(n<=1e4)
        sub1();
    else
        sub2();
    return 0;
}
