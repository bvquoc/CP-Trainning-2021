#include<iostream>
#include<stack>
#include<cstdio>
#define ll long long
#define maxN 10000001
using namespace std;
ll L[maxN],R[maxN];
ll a[maxN],n;
void Enter()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}

stack<int> s1,s2;
void Solve()
{
    for(int i=1;i<=n;i++)
    {
        while(!s1.empty()&&a[s1.top()]>=a[i])
            s1.pop();
        if(s1.empty())
            L[i]=0;
        else
            L[i]=s1.top();
        s1.push(i);
    }

    for(int i=n;i>=1;i--)
    {
        while(!s2.empty()&&a[s2.top()]>=a[i])
            s2.pop();
        if(s2.empty())
            R[i]=n+1;
        else
            R[i]=s2.top();
        s2.push(i);
    }
    ll res(0);

    for(int i=1;i<=n;i++)
    {
        if(a[i]<=R[i]-L[i]-1)
            res=max(res,a[i]);
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SHOPSIGN.inp","r",stdin);
    freopen("SHOPSIGN.out","w",stdout);

    Enter();
    Solve();
}
