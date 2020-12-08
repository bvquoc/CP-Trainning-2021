#include <bits/stdc++.h>
#define fr(i,x,y) for(int i = x; i <= y; i++)
#define frd(i,x,y) for(int i = x; i >= y; i--)
using namespace std;
int T;
int n,m;
int a[100100],b[100100];
long long ans = 0;
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    cin>>T;
}
void solve(int L,int R)
{
    ans = 0;
    b[0] = 0; b[R-L+2] = 0;
    fr(i,L,R) b[i-L+1] = a[i];
    int j = 1,k;
    while (true)
    {
        int mmin = 1e9;
        while (b[j] == 0 && j <= R-L+1) j++;
        if (j > R-L+1) break;
        k = j;
        while (b[k] != 0)
        {
            mmin = min(mmin,b[k]);
            k++;
        }
        fr(i,j,k-1) b[i] -= mmin;
        ans += mmin;
    }
    cout<<ans<<'\n';
}
void sub1()
{
    fr(t,1,T)
    {
        cin>>n>>m;
        fr(i,1,n)
            cin>>a[i];
        fr(i,1,m)
        {
            int tv;
            int L,R,k;
            cin>>tv;
            if (tv == 1)
            {
                cin>>L>>R>>k;
                fr(j,L,R) a[j] += k;
            }
            else
                {
                    cin>>L>>R;
                    solve(L,R);
                }
        }
    }
}
int main()
{
    inp();
    sub1();
    return 0;
}
