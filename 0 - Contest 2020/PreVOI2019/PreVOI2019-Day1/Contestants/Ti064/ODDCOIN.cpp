#include <bits/stdc++.h>
using namespace std;
#define el '\n'

typedef unsigned long long ull;

typedef long long ll;

template<typename so>

void read(so &x)
{
    x = 0;
    ll dem = 0;char c;
    for (c = getchar();'0'>c||c>'9';c=getchar())
    {
        dem++;if(dem==100) return;
    }
    for (;'0'<=c&&c<='9';c=getchar())
    {
        x = (x<<3) + (x<<1) + c - '0';
    }
}

const ll MaxN = 1e6+1;

const ll mod = 1e9+7;

ll n;

ll x,t;

vector<ll> so;

ll mu[6];

ll qhd[MaxN];

template<typename so>
void get_max(so &a,so b)
{
    if (a<b) a = b;
}

template<typename so> void get_min(so &a,so b)
{
    if (a>b) a = b;
}

void nen()
{
    so.clear();
    mu[0] = 1;for (ll i=1;i<5;i++) mu[i] = mu[i-1]*10;
    for (ll i=0;i<5;i++)
    {
        ll gg = mu[i];
        so.push_back(ll(1)*gg);
        so.push_back(ll(3)*gg);
        so.push_back(ll(5)*gg);
    }
    //so.push_back(x);
    //sort(so.begin(),so.end());
}

void sub1()
{
    nen();
    if (x!=0)
        so.push_back(x);
    sort(so.begin(),so.end());
    fill(qhd+1,qhd+MaxN,INT_MAX);
    for (ll i=1;i<=n;i++)
    {
        for (int j=0;j<so.size();j++)
        {
            if (i<so[j]) break;
            get_min(qhd[i],qhd[i-so[j]] + 1);
        }
    }
    cout<<qhd[n]<<el;
}

void sub2()
{
    nen();sort(so.begin(),so.end());
    ll i_f  = 0;
    int gtnn = INT_MAX;
    int kq = 0;
    int dem = 0;
    while(i_f<=n)
    {
        int kq = 0;
        ll gg = n-i_f;
        //cout<<x<<" "<<dem<<" ";
        for (int i = so.size()-1;i>=0;i--)
        {
            if (gg==0) break;
            if (gg<so[i]) continue;
            kq += (int)(gg/so[i]);
            //cout<<so[i]<<" "<<gg/so[i]<<" ";
            gg = gg - so[i]*(gg/so[i]);
        }
        //cout<<kq+dem<<el;
        get_min(gtnn,kq+dem);
        i_f += x;
        if (x==0) break;
        dem++;
        if (dem==2000000) break;
    }
    cout<<gtnn<<el;
}

void input()
{
    so.clear();
    cin>>x>>n;
    if (x<=100000&&n<=100000)
    {
        //sub1();
        //return;
    }
    sub2();

}

//name ODDCOIN

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    ll test = 1;
    cin>>test;
    while(test--)
    input();
}
