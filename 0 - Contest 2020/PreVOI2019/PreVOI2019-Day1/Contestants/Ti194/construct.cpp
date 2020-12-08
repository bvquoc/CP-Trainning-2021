#include<bits/stdc++.h>

#define file "construct"
#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 1000006
#define pii pair<int, int>

using namespace std;
int t, n, m, a[maxn], b[maxn], h[maxn], s[maxn], top, ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> t;
    f1 (i, t)
    {
        cin >> n >> m;
        f1 (i, n) cin >> a[i];
        f1 (i, m)
        {
            int type, l, r, k;
            cin >> type >> l >> r;
            if (type == 1)
            {
                cin >> k;
                for (int i=l; i<=r; i++)
                    a[i]+=k;
            }
            else
            {
                //f1 (i, n) cout << a[i] << ' '; el;
                top=0; ans=0;
                for (int i=l; i<=r; i++)
                {
                    if (top) ans += max(a[s[top]]-a[i], 0);
                    //cout << ans << ' ';
                    while (a[i]>=a[s[top]]&&top) top--;
                    s[++top]=i;
                    //f1 (x, top) cout << s[x] << ' '; el;
                }
                if (top) ans += a[s[top]];
                cout << ans; el;
            }
        }
    }
    return 0;
}
