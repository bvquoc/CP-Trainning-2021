#include <iostream>
#include <fstream>
#include <algorithm>

#define lim 200005
#define base 1000000007

using namespace std;

long n,tong = 0;
long a[lim],b[lim],c[lim],d[lim];
bool check = false;

bool kiemtra()
{
    for (long i = 1; i <= n; i++)
        if (b[i] != c[i])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);
    cin >> n;
    for (long i = 1; i <= n; i++)
        cin >> a[i], c[i] = a[i];
    for (long i = 1; i <= n; i++)
        cin >> b[i];
    do
    {
        if (kiemtra())
            check = true;
        for (long i = 1; i <= n; i++)
            d[i] = c[i];
        for (long i = 1; i <= n; i++)
            if (d[i] != i)
            {
                long j = i;
                while ((d[j] != j) && (j < n))
                {
                    swap(d[j],d[j+1]);
                    tong = (tong+1)%base;
                    j++;
                }
            }
        if (check)
            break;
    }
    while (next_permutation(c+1,c+n+1));
    cout << tong;
    return 0;
}
