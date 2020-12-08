#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 5;

int f[N][N];
char s[N];

char g[N][N];

int n;

int main()
{
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);

    scanf("%s",(s+1));

    int m = strlen(s+1);

    scanf("%d", &n);

    for(int k = 1; k <= n; ++k)
    {
        char x;
        cin >> x;

        if(x == 'C')
        {
            int y;
            scanf("%d\n", &y);

            if(s[y] == ')') s[y] = '(';
            else if(s[y] == '(') s[y] = ')';

            for(int j = 1; j <= m; ++j) g[k][j] = s[j];
        }

        if(x == 'Q')
        {
            int y, z;
            scanf("%d %d\n", &y, &z);

            f[0][0] = 0;

            for(int i = m; i >= 1; --i)
                for(int j = i ; j <= m; ++j)
            {
                f[i][j] = j - i + 1;
                if(j == i+1 && s[i] == '(' && s[j] == ')') f[i][j] = 0;
                else if(s[i] == '(' &&  s[j] == ')') f[i][j] = f[i+1][j-1];

                f[i][j] = min(f[i][j], min(f[i+1][j] +1, f[i][j-1] + 1));

                for(int l = i+1; l <= j-1;  ++l) f[i][j] = min(f[i][j], f[i][l] + f[l][j]);
            }

            printf("%d\n", f[y][z]);
            for(int j = 1; j <= m; ++j) g[k][j] = s[j];
        }

        if(x == 'U')
        {
            int y;
            scanf("%d\n", &y);

            for(int j = 1; j <= m; ++j)
                s[j] = g[y-1][j];

            for(int j = 1; j <= m; ++j) g[k][j] = s[j];
        }
    }
}
