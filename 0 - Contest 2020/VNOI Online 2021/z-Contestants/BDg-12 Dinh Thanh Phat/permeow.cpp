#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
int b[maxn];
int n;
typedef long long ll;
const ll mod = 1e9 + 7;
void add(ll &u,ll v)
{
    u += v;
    u %= mod;
}
void enter()
{
    cin>>n;
    _for(i,1,n+1)
        cin>>a[i];
    _for(i,1,n+1)
        cin>>b[i];
}
int bit[maxn];
void update(int i,int val)
{
    for(; i<=n; i+=(i&(-i)))
        bit[i] += val;
}
int _get(int i)
{
    int sum = 0 ;
    for(; i>0; i-=(i&(-i)))
        sum += bit[i];
    return sum;
}

bool issub1()
{
    _for(i,1,n+1)
        if (a[i] != b[i])  return false;
    return true;
}

void _count(vector<int> &id, ll & ans)
{
    _for(i,1,n+1)
        bit[i] = 0;
    for(auto i:id)
    {
        add(ans, _get(n) - _get(i));
        update(i, 1);
    }
}
void trau()
{
    vector<int> id;
    _for(i,1,n+1)
        id.push_back(i);
    ll ans =0 ;
    do
    {
        _count(id, ans);
    }
    while(next_permutation(id.begin(), id.end()));
    cout<<ans;
}



void sub1()
{

    int sum = 0;
    _for(i,1,n+1)
    {
        sum += (_get(n) - _get(a[i]));
        update(a[i], 1);
    }
    cout<<sum;
}



bool issub2()
{
    _for(i,1,n+1)
    {
        if (a[i] != i) return false;
        if (b[i] != n - i +1) return false;
    }
    return true;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    enter();
    if (issub1()) sub1();
    else if (issub2()) trau();
    return 0;
}
