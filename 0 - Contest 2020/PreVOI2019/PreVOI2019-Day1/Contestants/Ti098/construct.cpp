#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ins insert
#define era erase
#define inf 1000000009
#define N 1000009

using namespace std;

set < int > S;
set < int > :: iterator itd, itc, it;
int a[N], h[N];
int n, m, type, k, l, r, t;

int change(int l, int r)
{
    for(int i=l; i<=r; ++i)
        h[i] = a[i];

    int ans = 0, res, vt, vtd, vtc;

    while(S.size())
    {
        it = S.begin();
        S.era(it);
    }
    S.ins(l -1); S.ins(r +1);

    while(S.size() != (r - l) +3)
    {
        vt = n; res = inf;
        for(int i=l; i<=r; ++i)
            if(h[i] < res && h[i] != 0)
        {
            res = h[i];
            vt = i;
        }
        itd = S.lower_bound(vt);
        itd--; vtd = (*itd) +1;
        itc = S.upper_bound(vt);
        vtc = (*itc) -1;
        //cout << vtd << ' ' << vtc << '\n';
        for(int i=vtd; i<=vtc; ++i)
        {
            h[i]-= res;
            if(h[i] == 0)S.ins(i);
        }
        ans+= res;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    #endif //ONLINE_JUDGE
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=1; i<=n; ++i)
            cin >> a[i];
        for(int i=1; i<=m; ++i)
        {
            cin >> type;
            if(type == 1)
            {
                cin >> l >> r >> k;
                for(int x=l; x<=r; ++x)
                    a[x]+= k;
            }
            else
            {
                cin >> l >> r;
                cout << change(l ,r) << '\n';
            }
        }
    }
    return 0;
}
