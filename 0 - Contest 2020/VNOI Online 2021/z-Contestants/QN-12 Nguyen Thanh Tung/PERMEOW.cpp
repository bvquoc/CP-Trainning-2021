#include <bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define frd(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second
#define maxn 300100
#define Bit(x,i) ((x>>i)&1)
#define Turnoff(t,k) (t^(1<<(k)))
using namespace std;
int n;
int a[maxn],b[maxn],tree[maxn];
long long ans = 0, mod = 1e9 + 7;
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    cin>>n;
    fr(i,1,n) cin>>a[i];
    fr(i,1,n) cin>>b[i];
}
void update(int x)
{
    while (x <= n)
    {
        tree[x]++;
        x += x & (-x);
    }
}
int get(int x)
{
    int temp = 0;
    while (x > 0)
    {
        temp += tree[x];
        x -= x & (-x);
    }
    return temp;
}
void sub()
{
    fr(i,1,n)
    {
        ans = (ans + i - 1 - get(a[i] - 1)) % mod;
        update(a[i]);
    }
    cout<<ans;
}
int main()
{
    inp();
    sub();
    return 0;
}
