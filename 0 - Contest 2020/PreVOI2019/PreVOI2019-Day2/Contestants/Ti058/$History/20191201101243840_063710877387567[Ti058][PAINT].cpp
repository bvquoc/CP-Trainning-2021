#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 5;

char cl[N];
int n;

int main()
{
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);

    scanf("%d", &n);

    int sl = 0;

    for(int i = 1; i <= n; ++i)
    {
        int u;
        scanf("%d ", &u);

        if(u == 1)
        {
            ++sl;
            char ch;
            scanf("%c\n", &ch);
            cl[sl] = ch;
        }
        else if(u == 2)
        {
            char x, y;
            scanf("%c %c\n", &x, &y);

            for(int j = 1; j <= sl; ++j)
            {
                if(cl[j] == x) cl[j] = y;
            }
        }
    }
    for(int i = 1; i <= sl; ++i) cout << cl[i];
}
