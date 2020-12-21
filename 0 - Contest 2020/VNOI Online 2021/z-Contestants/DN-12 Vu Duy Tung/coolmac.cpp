#include<bits/stdc++.h>
#define mino "coolmac"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define INC(i,a,b) for(int i=a; i<=b; i++)
#define DEC(i,a,b) for(int i=a; i>=b; i--)
#define REP(i,a,b) for(int i=a; i<b; i++)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e9

const int N = 1e5 + 5;

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;


int m, n;

struct ao
{
    int l, r;
} a[N];

bool ss(ao A, ao B)
{
    return A.r > B.r;
}

int main()
{
    freopen(mino".inp","r",stdin);
    freopen(mino".out","w",stdout);

    turbo

    cin >> m;

    INC(i,1,m) cin >> a[i].l >> a[i].r;

    int t = 100000;
    cin >> n;
    INC(i,1,n)
    {
        int x; cin >> x;
        t = min(t, x);
    }

    sort(a+1, a+m+1, ss);

    int cur = 100000;

    int i = 1, res = 0;
    while( cur > t )
    {
        int mi = oo;
        while( i <= m && a[i].r >= cur )
        {
            mi = min(mi, a[i].l);
            i++;
        }
        if( mi >= cur )
        {
            cout << "-1";
            return 0;
        }
        res++;
        cur = mi;
    }

    cout << res;

}
