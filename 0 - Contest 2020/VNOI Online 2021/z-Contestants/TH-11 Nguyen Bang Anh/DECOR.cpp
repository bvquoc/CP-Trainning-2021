#include <bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
#define oo 1000000000000000000
#define MAXN 100001
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define PR(x,a,b) { cout<<#x<<' '; for(long long i=a;i<=b;i++) cout<<x[i]<<' '; cout<<'\n'; }
#define taskname "DECOR"
#define pb push_back

int n,m,k;
string s;
int a[MAXN], b[MAXN];

void read()
{
    cin>>n>>m>>k;
    cin>>s;
    FOR(i,1,m)
    {
        cin>>a[i]>>b[i];
    }
}

void init()
{

}

int kq=0;
int kqa,kqb;

void solve()
{
    if(k==0&&m==0)
    {
        int cnt=0;
        int aa, bb;
        FOR(i,0,n-1)
        {
            if(i==0) cnt++;
            else
            {
                if(s[i]==s[i-1])
                {
                    aa=i;
                    cnt++;
                }
                else
                {
                    bb=i-1;
                    if(kq<cnt)
                    {
                        kqa=aa;
                        kqb=bb;
                    }
                    cnt=1;
                }
            }
        }
    }
    else if(m==0)
    {
        FOR(i,1,n)
        {
            FOR(j,1,k)
            {

            }
        }
    }
}

void write()
{
    cout<<kqa<<' '<<kqb;
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
