#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n, k;
int a[21];
vector <int> b(21,0);
bool check()
{
    int tong = 0;
    for (int i = n; i >= 1; i--)
    {
        if (b[i] == 1)
        {
            tong += a[i];
        }
        else
        {
            tong -= a[i];
        }
    }
    tong += a[0];
    if (tong % k == 0) return true;
    else return false;
}
int main()
{
    freopen("KMULT.inp","r",stdin);
    freopen("KMULT.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    n--;
    int vt = n;
    while(b[0] != 1)
    {
        if (b[vt] == 0)
        {
            b[vt]++;
        }
        else
        {
            int vt2 = vt;
            while(b[vt2] == 1)
            {
                b[vt2] = 0;
                vt2--;
            }
            b[vt2]++;
        }
        if(check())
        {
            cout << 1 << endl;
            for (int i = 1; i <= n; i++)
            {
                if (b[i] == 0)
                {
                    cout << "-";
                }
                else
                {
                    cout << "+";
                }
            }
            return 0;
        }
    }
    cout << "0";
    return 0;
}
