#include<bits/stdc++.h>
#define INF 101010101000
#define ll long long
using namespace std;
ll n,m,k;
string s;
struct node
{
    ll l;ll r;
};
node A[500005];
void sub1()
{
    ll res=0;
    ll l;ll r;
    ll dem=0;
    ll L;ll R;
    for(ll i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1] && s[i]=='1')
        {
            dem++;
            L=min(L,i);
            if(i==s.size()-2)
            {
                if(res<dem)
                {
                l=L+1;
                r=i+2;
                res=dem;
                }
            }
        }
        else
        {
            if(res<dem)
            {
                l=L+1;
                r=i+1;
                res=dem;
            }
            dem=0;
            L=n+1;
        }
    }
    if(res==0)
    {
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                l=i+1;
                r=i+1;
                break;
            }
        }
    }
    cout<<l<<" "<<r;
}
int main()
{
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    for(ll i=1;i<=m;i++)
    {
        cin>>A[i].l>>A[i].r;
    }
    if(m==0 && k==0)
    {
        sub1();
    }
    if(m==0)
    {
        cout<<1<<" "<<n;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
