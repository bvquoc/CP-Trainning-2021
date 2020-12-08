#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define maxn
#define ll long long
#define Ntu "oddcoin"
#define int long long

using namespace std;

int x,t;
multiset<int> s;
multiset<int>::iterator it;

int f[100005];
int z[]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};

void solve1()
{
    fto(i,0,t) f[i]=1e9;
    f[t]=0;
    queue<int> q;
    q.push(t);
    int u,v;
    while(q.size())
    {
        u=q.front();q.pop();
        fto(i,0,14)
        {
            if (z[i]>u) break;
            v=u-z[i];
            if (f[v]>f[u]+1)
            {
                f[v]=f[u]+1;
                if (!v) {cout << f[v] << '\n';return;}
                q.push(v);
            }
        }
        v=u-x;
        if (v<0) continue;
        if (f[v]>f[u]+1)
        {
            f[v]=f[u]+1;
            if (!v) {cout << f[v] << '\n';return;}
            q.push(v);
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    freopen (Ntu".inp","r",stdin);
    freopen (Ntu".out","w",stdout);
    int tes;
    cin >> tes;
    s.insert(1);s.insert(3);s.insert(5);
    s.insert(10);s.insert(30);s.insert(50);
    s.insert(100);s.insert(300);s.insert(500);
    s.insert(1000);s.insert(3000);s.insert(5000);
    s.insert(10000);s.insert(30000);s.insert(50000);
    ll rs=0,rs2,z,T;
    int v;
    while (tes--)
    {
        cin >> x >> t;z=t;T=t;
        if (x<=100000 && t<=100000) {solve1();continue;}
        s.insert(x);
        rs=rs2=0;
        while (t>0)
        {
            it=s.lower_bound(t);
            if (it==s.end()) --it;
            v=*it;
            if (v>t) {--it;v=*it;}
            rs+=t/v;
            t=t-(t/v)*v;
        }
        if (x<=500)
        {
            cout << rs << '\n';
            it=s.lower_bound(x);
            s.erase(it);
            continue;
        }
        for(int i=2; i*x<=T; ++i) s.insert(i*x);
        while (z>0)
        {
            it=s.lower_bound(z);
            if (it==s.end()) --it;
            v=*it;
            if (v>z) {--it;v=*it;}
            if (v%x==0) rs2+=v/x;
            else rs2+=z/v;
            z=z-(z/v)*v;
        }
        cout << min(rs2,rs) << '\n';
        for(int i=1; i*x<=T; ++i)
        {
            it=s.lower_bound(i*x);
            s.erase(it);
        }
    }
    return 0;
}
