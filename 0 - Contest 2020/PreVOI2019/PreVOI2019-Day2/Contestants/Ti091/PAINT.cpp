#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define st first
#define nd second
#define int long long
#define mid (l+r)/2
using namespace std;
const int N=1e6+4;
int n,k;
char a[N];
vector<int> g[N];
main()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    cin >> n;
    while(n--)
    {
        int ch;
        char c,z;
        cin >> ch >> c;
        if (ch==1)
        {
            a[++k]=c;
            g[c-'a'+1].push_back(k);
        }
        else
        {
            cin >> z;
            if (z==c) continue;
            for(auto v:g[c-'a'+1])
            {
                a[v]=z;
                g[z-'a'+1].push_back(v);
            }
            g[c-'a'+1].clear();
        }
    }
    forinc(i,1,k) cout << a[i];
}
