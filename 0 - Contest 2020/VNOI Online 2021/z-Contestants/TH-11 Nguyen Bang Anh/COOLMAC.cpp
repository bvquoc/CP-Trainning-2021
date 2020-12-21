#include <bits/stdc++.h>
using namespace std;

#define ii pair<long long,long long>
#define oo 1000000000
#define MAXN 100001
#define ll long long
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define PR(x,a,b) {cout<<#x<<' '; for(long long i=a;i<=b;i++) cout<<x[i]<<' '; cout<<'\n'; }
#define all(x) x.begin(),x.end()
#define pb push_back
#define taskname "COOLMAC"
#define fi first
#define se second

long long m,n;
ii p[MAXN];
long long t[MAXN];

void read()
{
    cin>>m;
    FOR(i,1,m) cin>>p[i].fi>>p[i].se;
    cin>>n;
    FOR(j,1,n) cin>>t[j];
}

long long Min=oo;

void init()
{
    FOR(i,1,n) Min=min(Min, t[i]);
    sort(p+1,p+m+1);
}

long long kq=0;
long long tam;
long long tam2;
long long Max;

void solve()
{
    tam=Min;
    Max=0;
//    FOR(i,1,m) cout<<p[i].fi<<' '<<p[i].se<<"  ";
//    cout<<'\n';
    p[m+1].fi=oo;
    p[m+1].se=oo;
    FOR(i,1,m+1)
    {
        if(p[i].fi<=tam)
        {
//            cout<<tam<<' '<<i<<'\n';
            if(p[i].se>=tam)
            {
                if(Max<p[i].se)
                {
                    Max=p[i].se;
                    tam2=i;
//                    cout<<tam<<' '<<tam2<<'\n';
                }
            }
        }
        else
        {
            if(i!=m+1) i--;
//            cout<<"YES"<<' ';
//            cout<<i<<' '<<tam<<' '<<p[tam2].se<<'\n';
            if(tam==p[tam2].se)
            {
                tam2=-oo;
                return;
            }
            tam=p[tam2].se;
            Max=0;
            kq++;
            if(tam==100000) return;
        }
    }
}

void write()
{
    if(tam2==-oo) cout<<-1;
    else cout<<kq;
}

int main()
{
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    read();
    init();
    solve();
    write();
    return 0;
}
