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
#define Lozer "paint"
#define mn 1000005

using namespace std;

int n;
char mau[mn],key[mn],a[mn];
queue<int> q[30];

struct In4
{
    int type;
    char a,b,c;
}tv[mn];

void Sub1()
{
    int cur=0;
    while(n--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            char c;
            cin>>c;
            mau[++cur]=c;
        }
        else
        {
            char a,b;
            cin>>a>>b;
            forr(i,1,cur)
            {
                if(mau[i]==a)
                    mau[i]=b;
            }
        }
    }
    forr(i,1,cur)
    {
        cout<<mau[i];
    }
    cout<<'\n';
}

void Sub2()
{
    int cur=0;
    while(n--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            char c;
            cin>>c;
            mau[++cur]=c;
            q[c-'a'].push(cur);
        }
        else
        {
            char a,b;
            cin>>a>>b;
            while(q[a-'a'].size())
            {
                int u=q[a-'a'].front();
                q[a-'a'].pop();
                mau[u]=b;
                q[b-'a'].push(u);
            }
        }
    }
    forr(i,1,cur)
    {
        cout<<mau[i];
    }
}

void Sub3()
{
    int cur=0;
    forr(i,1,n)
    {
        cin>>tv[i].type;
        if(tv[i].type==1)
        {
            cin>>tv[i].c;
            cur++;
        }
        else
        {
            cin>>tv[i].a>>tv[i].b;
        }
    }
    int m=cur;
    forr(i,0,25)
    {
        key[i]=char(i+'a');
    }
    ford(i,n,1)
    {
        int type=tv[i].type;
        if(type==1)
        {
            char c=tv[i].c;
            a[cur]=key[c-'a'];
            cur--;
        }
        else
        {
            if(type==2)
            {
                char a=tv[i].a;
                char b=tv[i].b;
                key[a-'a']=key[b-'a'];
            }
        }
    }
    forr(i,1,m)
    {
        cout<<a[i];
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(Lozer".inp", "r", stdin);
    freopen(Lozer".out", "w", stdout);
    cin>>n;
    if(n<=10000)
    {
        Sub1();
        return 0;
    }
    Sub3();
    return 0;
}
