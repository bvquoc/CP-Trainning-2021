#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Ford(i,a,b) for(int i = a; i >= b; --i)
#define maxN 100005
#define ll long long
#define fi first
#define se second
#define Bit(x, i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, a[maxN], b[maxN], t;
void Test(int l, int r)
{
    For(i,l,r)b[i] = a[i];
    int ans = 0;
    while(true)
    {
        bool ok = false;
        int i = l;
        for(; i <= r; i++)
            if(b[i] != 0)
            {
                ok = true;
                int L = i, R = i, minh = 1e9;
                while(R <= r && b[R] != 0)
                {
                    minh = min(minh, b[R]);
                    R++;
                }
                R--;
                For(vt,L,R)b[vt] -= minh;
                i = R;
                ans += minh;
            }
        if(!ok)break;
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("Construct.inp", "r", stdin);
    freopen("Construct.out", "w", stdout);
    fast_read;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        For(i,1,n)cin>>a[i];
        while(m--)
        {
            int x, l, r, k = 0;
            cin>>x;
            if(x == 1)
            {
                cin>>l>>r>>k;
                For(i,l,r)a[i] += k;
            }
            else
            {
                cin>>l>>r;
                Test(l, r);
            }
        }
    }
}
