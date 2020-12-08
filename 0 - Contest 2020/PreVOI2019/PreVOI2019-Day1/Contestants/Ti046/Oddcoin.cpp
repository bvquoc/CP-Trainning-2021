#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define name "Oddcoin"
#define ll long long
#define maxn 50000007

using namespace std;

int q,x,t,d[20]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,0};
int solve(int a)
{
    int s=0;
    fd(i,15,1)
    {
        s+=(a/d[i]);
        a=(a%d[i]);
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);

    cin>>q;
    while(q!=0)
    {
        q--;
        cin>>x>>t;
        int res=t/x+solve(t-t/x);
        f(i,0,min(t/x,100000))
        {
            res=min(res,i+solve(t-x*i));
        }
        cout<<res<<'\n';
    }
}
