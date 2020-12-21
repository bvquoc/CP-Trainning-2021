#include <bits/stdc++.h>

const int N = 1e5 + 5, mod = 1e9 + 7;
const int lim = 1e5;
#define X first
#define Y second
#define fo(i,j,k) for(int i = j; i <= k; ++i)
#define of(i,j,k) for(int i = j; i >= k; --i)
#define PB push_back
#define all(a) (a).begin(),(a).end()
#define reset(a,val) fill(a+1,a+sizeof(a),val)
#define task "COOLMAC"

using namespace std;

typedef pair <int,int> ii;
typedef pair <ii,int> iii;
typedef long long ll;

struct protective_gear
{
    int l,r;
    bool operator < (const protective_gear &o) const
    {
        if(r == o.r) return l < o.l;
        return r < o.r;
    }
}progear[N];

struct data
{
    int x,y;
};

set <int> s;
iii a[2*N];
deque <data> dq;
int m,n,temperature[N], dem = 0;
int max_tem = 0, id = 0, min1 = mod;

void read()
{
    cin >> m;
    fo(i,1,m)
    {
        cin >> progear[i].l >> progear[i].r;
        max_tem = max(max_tem,progear[i].r);
        max_tem = max(max_tem,progear[i].l);
    }
    cin >> n;
    fo(i,1,n)
    {
        cin >> temperature[i];
        min1 = min(min1,temperature[i]);
    }
    if(max_tem < lim)
    {
        cout << -1;
        exit(0);
    }
}

void solve()
{
    sort(temperature+1,temperature+n+1);
    sort(progear+1,progear+m+1);

    /// fo(i,1,m) cout << progear[i].l << " " << progear[i].r << endl;

    fo(i,1,m)
        if(progear[i].l <= min1) id = i;
        else break;
    if(id == 0)
    {
        cout << -1;
        exit(0);
    }

    fo(i,id,m)
    {
        if(!dq.empty() && progear[i].r == dq.back().y) continue;
        /// cout << progear[i].l << " " << progear[i].r << endl << endl;
        while(!dq.empty())
        {
            int x = dq.back().x;
            int y = dq.back().y;
            dq.pop_back();

            if(progear[i].l > y)
            {
                /// cout << 1 << endl;
                dq.push_back({x,y});
                break;
            }

            if(progear[i].l <= x)
            {
                /// cout << 2 << endl;
                while(!dq.empty() && progear[i].l <= dq.back().x)
                    dq.pop_back();
                break;
            }

            if(progear[i].l > x && progear[i].l <= y)
            {
                /// cout << 3 << endl;
                dq.push_back({x,y});
                /// cout << x << " " << y << endl;
                while(dq.size() > 1)
                {
                    x = dq.back().x;
                    y = dq.back().y;

                    dq.pop_back();

                    if(progear[i].l > dq.back().y || progear[i].r == y)
                    {
                        dq.push_back({x,y});
                        break;
                    }
                }
                break;
            }
        }

        dq.push_back({progear[i].l,progear[i].r});
        /// cout << dq.size() << '\n';
    }

    /// cout << dq[0].x << " " << dq[0].y << endl;
    for(int i = 1; i < dq.size(); ++i)
    {
        /// cout << dq[i].x << " " << dq[i].y << endl;
        if(dq[i].x > dq[i-1].y)
        {
            cout << -1;
            exit(0);
        }
    }
    cout << dq.size();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    read();
    solve();

    return 0;
}
