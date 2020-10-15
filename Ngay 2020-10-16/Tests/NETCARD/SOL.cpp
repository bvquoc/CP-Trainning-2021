#include <bits/stdc++.h>

#define maxn 1000000
using namespace std;

struct X
{
  int i, j, v;
};

int n, k, i, a[maxn];
X d[maxn];
bool lf(const X x, const X y)
{
    return x.v > y.v;
}
void Enter()
{
    cin >> n >> k;

    for (i = 0; i < k; i++)
    {
        cin >> d[i].i >> d[i].j >> d[i].v;

    }

}
void Solve()
{
    sort(d, d + k, lf);
    for (i = 1; i <= n; i++) a[i] = 2;
    for (i = 0; i < k; i++)
    {
        if (d[i].v == 1)
           a[d[i].i] = a[d[i].j] = 1;
        else
        {
            if (a[d[i].i] == 1) a[d[i].j] = 0;
            if (a[d[i].j] == 1) a[d[i].i] = 0;
        }
    }
}
void Print()
{
    for (i = 1; i <= n; i++) cout << a[i] << ' ';
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("NETCARD.INP", "r", stdin);
  freopen("NETCARD.OUT", "w", stdout);
  Enter();
  Solve();
  Print();
}
