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
#define Lozer "construct"
#define mn 100005

using namespace std;

int a[mn],n,m;

int Que(int l,int r)
{
    if(l>r) return 0;
    if(l==r)
    {
        return a[l];
    }
    int ans=0;
    int minn=oo;
    forr(i,l,r)
    {
        minn=min(minn,a[i]);
    }
    int pre=l;
    forr(i,l,r)
    {
        ans+=1;
        if(a[i]==minn)
        {
            ans+=Que(pre+1,i-1)-minn;
            pre=a[i];
        }
    }
    ans+=Que(pre+1,r);
    return ans;
}

void Solve()
{
    cin>>n>>m;
    forr(i,1,n)
    {
        cin>>a[i];
    }
    while(m--)
    {
        int type;
        cin>>type;
        if(type==2)
        {
            int l,r;
            cin>>l>>r;
            cout<<Que(l,r);
        }
        else
        {
            int l,r,k;
            cin>>l>>r>>k;
            forr(i,l,r)
            {
                a[i]+=k;
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(Lozer".inp", "r", stdin);
    freopen(Lozer".out", "w", stdout);
    int test;
    cin>>test;
    while(test--)
    {
        Solve();
    }
    return 0;
}
