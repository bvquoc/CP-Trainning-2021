#include<bits/stdc++.h>
using namespace std;
#define ft first
#define se second
#define iP pair<int,int>
#define iiP pair<int,pair<int,int> >
#define ll long long
#define lP pair<ll,int>
#define db long double
const long long mod=1e6+3;
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-48;
        c=getchar();
    }
}
int n,m;
int times[1000001];
int queue<pair<int,int> > q,q1;
long long d=0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen(".INP","r",stdin);
    freopen(".OUT","w",stdout);
    read(n);
    read(m);
    for(int i=1;i<=n;i++)
        read(times[i]);
    q.push({1,1});
    for(int i=1;i<=n;i++)
    {
        while(q!empty())
        {
            pair<int,int> x=q.top();
            int j=upper_bound(times+1,times+n+1,x.first+m)-times-1;
            if(j> 2*n-x.second+1) {ok=0;break;}
            //d=(d+1)%mod;
            q.push(x.second+1);
            if(j>=x.second+1){
                    d=d+
            }

        }
    }
}

