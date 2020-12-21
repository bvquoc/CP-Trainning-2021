#define fou(i, a, b) for (i = a; i <= b; i++)
#define fod(i, a, b) for (i = a; i >= b; i--)
#define pb push_back

#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

long long int tong;
long int n, a[1000], b[1000], c[2];

void tinh1()
{
    long int dem = 0, i, t, tinh = 0;
    c[1] = 0;
    c[0] = 0;
    fod(i, n, 1)
    {
        t = b[a[i]];
        while (t != 0)
        {
            dem++;
            c[dem % 2] = c[dem % 2] + t % 10;
            t = t / 10;
        }
    }
    if ((c[1] - c[0]) % 11 == 0)
        tong = (tong + 1) % 998244353998244353;
}

bool kiemtra()
{
    bool kt = true;
    long int i;
    fou(i, 1, n) if (i != a[n - i + 1])
    {
        kt = false;
        break;
    }
    return kt;
}

void hoanvi()
{
    long int i, min1, j, t, k;
    tong = 0;
    fou(i, 1, n)
        a[i] = i;
    tinh1();
    while (kiemtra() == false)
    {
        i = n;
        while (a[i] < a[i - 1])
            i--;
        min1 = 100;
        fou(j, i, n) if (min1 > a[j] && a[j] > a[i - 1])
        {
            min1 = a[j];
            t = j;
        }
        swap(a[i - 1], a[t]);
        fou(j, i, n - 1)
            fou(k, j + 1, n) if (a[j] > a[k]) swap(a[j], a[k]);
        tinh1();
    }
    cout << tong << "\n";
}

int main()
{
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);
    long int i, t, j;
    cin >> t;
    fou(i, 1, t)
    {
        cin >> n;
        fou(j, 1, n)
                cin >>
            b[j];
        hoanvi();
    }
}