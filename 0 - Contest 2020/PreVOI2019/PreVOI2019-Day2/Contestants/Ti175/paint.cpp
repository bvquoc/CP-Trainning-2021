#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define fid(i,a,b) for(int i=a;i>=b;i--)
#define maxn 1000005
#define ll long long
#define pii pair<int, int>
#define TTT "PAINT"
using namespace std;
int n, k = 0;
char a[maxn];
void sub1()
{
    int s;
    char x, y;
    while(n--)
    {
        cin >> s;
        if(s == 1)
        {
            cin >> x;
            a[++k] = x;
        }
        else
        {
            cin >> x >> y;
            fi(i, 1, k)
            if(a[i] == x) a[i] = y;
        }
    }
    fi(i, 1, k) cout << a[i];
}
int b[30];
vector<int> g[maxn];
char c[maxn];
void DFS(int u, int i)
{
    if(u == 0 || u > k) return;
    c[u] = char ('a' + i);
    for(auto &v: g[u])
        DFS(v, i);
}
void sub2()
{
    int s;
    char x, y;
    fi(i, 1, n)
    {
        cin >> s;
        if(s == 1)
        {
            k++;
            cin >> x;
            g[k].push_back(b[x - 'a']);
            b[x - 'a'] = k;
        }
        else
        {
            cin >> x >> y;
            if(x != y)
            {
                if(b[y - 'a'] == 0) b[y - 'a'] = b[x - 'a'];
                else g[b[y - 'a']].push_back(b[x - 'a']);
                b[x - 'a'] = 0;
            }
        }
    }
    fi(i, 0, 25) DFS(b[i], i);
    fi(i, 1, k) cout << c[i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(TTT".inp","r",stdin);
    freopen(TTT".out","w",stdout);
    cin >> n;
    if (n<=10000) sub1();
    else sub2();
}
