#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second
const ll inf = 1e18 + 18;
const int oo = 1e9 + 9;
const int max6 = 1e6 + 6;
const int modx = 1e9 + 7;
const int mody = 997;
const int base = 137;
//////////////////////////
void debug(vector<int> a)
{
    for (auto & v : a)
        cerr<<v<<" ";
    cerr<<"\n";
}
//////////////////////////

char a[505];
char b[505];
char c[505];

int n,m,k;

bool checkSub(int x)
{
    if (x == 1)
        return max({n,m,k}) == 1;

    if (x == 2)
    {
        for (int i = 2; i <= k; ++i)
            if (c[i] != c[i-1])
                return false;
        return true;
    }

    return true;
}

void sub1()
{
    if (a[1] == c[1] || b[1] == c[1])
    {
        printf("TRETRAU");
        return;
    }

    printf("%s",a+1);
    if (a[1] != b[1])
        printf("%s",b+1);
}

char res[100005];
int f[505][505][505];

void buff()
{
    // f[i][j][k] : i tk day 1, j tk day 2, k tk day 3
    array<int,3> pre[n+2][m+2][k+2];

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int x = 0; x <= k; ++x)
                f[i][j][x] = oo;

    f[0][0][0] = 0;

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int x = 0; x < k; ++x)
            {
                if (i+1 <= n && j+1 <= m && a[i+1] == b[j+1])
                {
                    int o = (x + 1 <= k && c[x+1] == a[i+1]);
                    f[i+1][j+1][x+o] = min(f[i+1][j+1][x+o],f[i][j][x]+1);
                    if (f[i+1][j+1][x+o] == f[i][j][x]+1)
                        pre[i+1][j+1][x+o] = {i,j,x};
                    continue;
                }

                if (i+1 <= n)
                {
                    int o = (x+1 <= k && c[x+1] == a[i+1]);
                    f[i+1][j][x+o] = min(f[i+1][j][x+o],f[i][j][x]+1);
                    if (f[i+1][j][x+o] == f[i][j][x]+1)
                        pre[i+1][j][x+o] = {i,j,x};
                }

                if (j+1 <= m)
                {
                    int o = (x+1 <= k && c[x+1] == b[j+1]);
                    f[i][j+1][x+o] = min(f[i][j+1][x+o],f[i][j][x]+1);
                    if (f[i][j+1][x+o] == f[i][j][x]+1)
                        pre[i][j+1][x+o] = {i,j,x};
                }

                if (i+1 <= n && j+1 <= m && a[i+1] == b[j+1])
                {
                    int o = (x > 0 && c[x+1] == a[i+1]);
                    f[i+1][j+1][x+o] = min(f[i+1][j+1][x+o],f[i][j][x]+1);
                    if (f[i+1][j+1][x+o] == f[i][j][x]+1)
                        pre[i+1][j+1][x+o] = {i,j,x};
                }
            }

    int res = oo;
    int pos = 0;
    for (int x = 0; x < k; ++x)
        if (f[n][m][x] < res)
            res = f[n][m][x],pos = x;

//    while (i || j || x)
//    {
//        array<int,3> pe = pre[i][j][x];
//
//    }

    if (res != oo)
        printf("%d\n",res);
    else
        printf("TRETRAU");
}

//////////////////////////
main()
{
#define file "xcklt."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    scanf("%s",a+1);
    scanf("%s",b+1);
    scanf("%s",c+1);

    n = strlen(a+1),m = strlen(b+1),k = strlen(c+1);

    if (checkSub(1))
        sub1();
    else
        buff();
}

