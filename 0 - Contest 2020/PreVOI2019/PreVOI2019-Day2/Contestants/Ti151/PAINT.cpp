///----------/// dylanrhodes ///----------///
#include <bits/stdc++.h>
#define reset(x,a) memset (x,a,sizeof(x))
#define task "PAINT"

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1000005;
int n,a[N];
struct query
{
    int k;
    char a,b;
} q[N];

void sub1 ()
{
    for (int i = 1; i <= n; i++)
    {
        if (q[i].k == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[j] == -1)
                {
                    a[j] = q[i].a - 'a';
                    break;
                }
            }
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[j] == q[i].a - 'a')
                {
                    a[j] = q[i].b - 'a';
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1)
            break;
        cout << char(a[i] + 'a');
    }
}

int truy[N],pa[N];
int sym[30];

int Find (int u)
{
    if (pa[u] == u)
        return u;
    return Find(pa[u]);
}

void sub2 ()
{
    int next = 1;
    for (int i = 0; i <= 26; i++)
        sym[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        int col = q[i].a - 'a';
        if (q[i].k == 1)
        {
            if (sym[col] == -1)
            {
                sym[col] = next;
                pa[next] = next;
                truy[next] = col;
            }
            else
            {
                pa[next] = sym[col];
            }
            next++;
        }
        else
        {
            int newc = q[i].b - 'a';
            if (sym[col] == -1)
                continue;
            if (sym[newc] != -1)
            {
                pa[sym[col]] = sym[newc];
                truy[sym[col]] = -1;
                sym[col] = -1;
            }
            else
            {
                sym[newc] = sym[col];
                truy[sym[newc]] = newc;
                sym[col] = -1;
            }
        }
    }
    for (int i = 1; i < next; i++)
        cout << char(truy[Find(i)] + 'a');
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen (task".inp","r",stdin);
    freopen (task".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i].k;
        if (q[i].k == 1)
            cin >> q[i].a;
        else
            cin >> q[i].a >> q[i].b;
    }
    if (n <= 10000)
        sub1();
    else
        sub2();
    return 0;
}
