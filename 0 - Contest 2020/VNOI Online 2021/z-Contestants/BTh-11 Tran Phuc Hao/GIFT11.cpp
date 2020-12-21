#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll t;
ll n;
ll T[15][2005];
string A[2005];
ll per[2005];
ll res=0;
bool check(string &temp)
{
    ll le=0;ll chan=0;
    for(ll i=0;i<temp.size();i++)
    {
        if((i+1)%2==1)
        {
            le+=temp[i]-'0';
        }
        else
        {
            chan+=temp[i]-'0';
        }
    }
    if(abs(chan-le)%11==0)
    {
        return 1;
    }
    return 0;
}
void sub1()
{
        res=0;
        for(ll i=1;i<=n;i++) per[i]=i;

        do
        {
            string temp;
            for(ll i=1;i<=n;i++)
            {
                string x=A[per[i]];
                temp=temp+A[per[i]];
            }
            res+=check(temp);
        }
        while(next_permutation(per+1,per+n+1));
        cout<<res<<"\n";
}
void sub2()
{
    res=1;
    string temp;
    for(ll i=1;i<=n;i++)
    {
        temp=temp+A[i];
    }
    if(check(temp))
    {
        for(ll i=1;i<=n;i++)
        {
            res=((res%MOD) *(i%MOD))%MOD;
        }
    }
    else
    {
        res=0;
    }
    cout<<res<<"\n";
}
ll cong()
{
    ll kq=1;
    ll kq1=1;
    for(ll i=1;i<=n/2;i++)
    {
        kq=((kq%MOD) * (i%MOD))%MOD;
    }
    for(ll i=1;i<=n/2 + n%2;i++)
    {
        kq1=((kq1%MOD) * (i%MOD))%MOD;
    }
    return (kq%MOD*kq1%MOD*(n+2)%MOD)%MOD;
}
void sub3()
{
    res=0;
    for(ll i=1;i<=n;i++)
    {
        string temp;
        for(ll j=i;j<=n;j++)
        {
            temp+=A[j];
        }
        for(ll j=1;j<i;j++)
        {
            temp+=A[j];
        }
        if(check(temp))
        {
            res+=cong();
        }
    }
    cout<<res;
}
int main()
{
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool chan=1;
        bool le=1;
        for(ll i=1;i<=n;i++)
        {
            cin>>A[i];
            if(A[i].size()%2==1)
            {
                chan=0;
            }
            else
            {
                le=0;
            }
        }
        if(n<=8)
        {
            sub1();
        }
        else
        {
            if(chan==1)
            {
                sub2();
            }
            else if(le==1)
            {
                sub3();
            }
        }
    }
    return 0;
}
