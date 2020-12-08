//----------Just Me & You---------
#include <bits/stdc++.h>
#include <bitset>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define oo 1000000007
#define Mod 1000000007
#define ll long long
#define pii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define sz(x) int(x.size())
#define forr(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define Lozer "fixstr"
#define mn 1005

using namespace std;

string ss;
int n,a[mn],s[mn],m;
int luu[mn][mn];

int QueS1(int l,int r)
{
    int ans=0;
    forr(i,l-1,r)
    {
        s[i]=0;
    }
    forr(i,l,r)
    {
        s[i]=s[i-1]+a[i];
        if(s[i]<0)
        {
            s[i]++;
            ans++;
        }
    }
    ans+=s[r];
    return ans;
}

void Sub1()
{
    forr(j,1,m)
    {
        char type;
        cin>>type;
        if(type=='C')
        {
            int vt;
            cin>>vt;
            a[vt]*=-1;
        }
        if(type=='Q')
        {
            int l,r;
            cin>>l>>r;
            cout<<QueS1(l,r)<<'\n';
        }
        if(type=='U')
        {
            int vt;
            cin>>vt;
            forr(i,1,n)
            {
                a[i]=luu[vt-1][i];
            }
        }
        forr(i,1,n)
        {
            luu[j][i]=a[i];
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(Lozer".inp", "r", stdin);
    freopen(Lozer".out", "w", stdout);
    cin>>ss;
    n=ss.length();
    ss=' '+ss;
    forr(i,1,n)
    {
        if(ss[i]=='(')
        {
            a[i]=1;
        }
        else
        {
            a[i]=-1;
        }
    }
    cin>>m;
    if(n<=1000 && m<=1000)
    {
        Sub1();
        return 0;
    }
    return 0;
}
