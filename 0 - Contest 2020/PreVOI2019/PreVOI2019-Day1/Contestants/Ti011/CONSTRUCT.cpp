#include <iostream>
#include <fstream>
#include <string.h>

#define task "CONSTRUCT"
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

ifstream fi(task".inp");
ofstream fo(task".out");

typedef long long int lli;
typedef pair<int, int> II;

const int maxn = 1002;
const int maxm = 50001;

int t;
int n, m;
int a[maxn], b[maxn];
int c, l, r, k;

inline int ReadInt()
{
    char c;
    while (c = fi.get(), c < '0' || c > '9');
    int x = c - '0';
    while (c = fi.get(), c >= '0' && c <= '9')
        x = x*10 + c - '0';
    return x;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    fo.put(x % 10 + '0');
}

void WritelnInt(int x)
{
    WriteInt(x);
    fo.put('\n');
}

int main()
{
    n = ReadInt();
    m = ReadInt();
    for (int i = 1; i <= n; i++)
        a[i] = ReadInt();
    for (int i = 1; i <= m; i++)
    {
        c = ReadInt();
        l = ReadInt();
        r = ReadInt();
        if (c == 2)
        {
            reset(b);
            for (int i = l; i <= r; i++)
                b[i] = a[i];
            int res = 0;
            while (true)
            {
                int index = l;
                int MIN = 1e9;
                for (int i = l; i <= r; i++)
                    if (b[i] != 0)
                        MIN = min(MIN, b[i]);
                while (b[index] == 0 && index <= r)
                    index++;
                if (index > r)
                    break;
                b[index]-=MIN;
                int cnt = 0, len = 1;
                for (int i = index+1; i <= r+1; i++)
                    if (b[i] != 0)
                    {
                        len++;
                        b[i]-=MIN;
                    }
                    else
                    {
                        if (len > 0)
                            cnt++;
                        len = 0;
                    }
                res += cnt*MIN;
            }
            WritelnInt(res);
        }
        else
        {
            k = ReadInt();
            for (int i = l; i <= r; i++)
                a[i] += k;
        }
    }
}
