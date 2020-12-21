#define fou(i, a, b) for (i = a; i <= b; i++)
#define fod(i, a, b) for (i = a; i >= b; i--)
#define pb push_back

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>

using namespace std;

vector<long int> u(100000), v(100000);

void qsot1(long int l, long int r)
{
    long int i, j, x, y;
    i = l;
    j = r;
    x = v[(l + r) / 2];
    do
    {
        while (v[i] > x)
            i++;
        while (x > v[j])
            j--;
        if (!(i > j))
        {
            swap(u[i], u[j]);
            swap(v[i], v[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j)
        qsot1(l, j);
    if (i < r)
        qsot1(i, r);
}
int main()
{
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
    long int x, y, n, i, dem, dau, min1, m, min2;
    cin >> n;
    fou(i, 1, n)
    {
        cin >> u[i] >> v[i];
    }
    cin >> m;
    min1 = 100000;
    fou(i, 1, m)
    {
        cin >> x;
        if (x < min1)
            min1 = x;
    }
    qsot1(1, n);
    dem = 0;
    dau = 100000;
    i = 1;
    v[0] = -1;
    while (dau > min1)
    {
        min2 = 100001;
        while (v[i] >= dau)
        {
            min2 = min(min2, u[i]);
            i++;
        }
        dau = min2;
        dem++;
        if (min2 == 100001)
        {
            dem = -1;
            break;
        }
    }
    cout << dem;
    return 0;
}