#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define name "motion"
#define ll long long
#define maxn 102

using namespace std;

int t,m,n,xa,ya,xb,yb,xc,yc,xd,yd;
ll res1,res2,ti;
bool xdd[maxn][maxn][maxn][maxn],kt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);

    cin>>t;
    while(t!=0)
    {
        t--;
        cin>>m>>n>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
        kt=0;
        ti=0;
        if(kt==0)
        {
            cout<<-1;
        }
        else
        {
            cout<<res1<<" "<<res2;
        }
        cout<<'\n';
    }
}
