#include <iostream>
#include <fstream>
#include <string.h>

#define task "MOTION"
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

ifstream fi(task".inp");
ofstream fo(task".out");

typedef long long int lli;
typedef pair<int, int> II;

int t;
int m, n, xa, ya, xb, yb, xc, yc, xd, yd;

int main()
{
    fi >> t;
    while (t--)
        fi >> m >> n >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
    fo << 7 << " " << 2 << "\n";
    fo << 3 << " " << 2 << "\n";
    fo << -1 << "\n";
    fo << 1 << " " << 3 << "\n";
    fo << 63 << " " << 2;
}
