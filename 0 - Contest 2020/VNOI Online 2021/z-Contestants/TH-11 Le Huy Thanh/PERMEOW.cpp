#include <bits/stdc++.h>

using namespace std;

#define task "PERMEOW"
#define file freopen(task".inp","r",stdin),freopen(task".out","w",stdout);
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define FOR(i,a,b) for(ll i=a; i<=b; i++)
#define DFOR(i,a,b) for(ll i=b; i>=a; i--)
#define ii pair<int,int>
#define X first
#define Y second
#define ll long long
#define pb push_back

#define BUG(x) {cout << #x << " = " << x << '\n';}
#define PR(x,a,b) {cout << #x << " = " ; FOR(i,a,b) cout << x[i] << ' '; cout << '\n';}

#define MOD 1000000007
#define MAXN 1000111

int n;
int a[MAXN];
int b[MAXN];

void read()
{
    cin >> n;
    FOR(i,1,n)
        cin >> a[i];
    FOR(i,1,n)
        cin >> b[i];
}

namespace sub1
{
    bool check()
    {
        FOR(i,1,n)
            if(a[i]!=b[i])
                return false;
        return true;
    }
    void solve()
    {
        int cnt = 0;
        FOR(i,1,n)
            FOR(j,i+1,n)
            {
                if(a[i]>a[j])
                {
                    cnt++;
                    swap(a[i],a[j]);
                }
            }
        cout << cnt;
    }
}

void solve()
{
    if(sub1::check())
    {
        sub1::solve();
        return;
    }
}

int main()
{
    file;
    faster;

    read();
    solve();

    return 0;
}
