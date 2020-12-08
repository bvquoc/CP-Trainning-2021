#include <bits/stdc++.h>
using namespace std;
const int max6 = 1e6 + 6;
int a[max6],cl[max6],tmp[max6];
vector <int> g[max6];
int n,sl = 0;

void sub1()
{
    sl = 0;
    while (n -- )
    {
        int type;
        char x;
        scanf("%d %c ",&type,&x);
        if (type == 1)
        {
            cl[++sl] = x - 'a';
            g[x-'a'].push_back(sl);
        }
        else
        {
            char y;
            scanf("%c",&y);
            int cnt = 0;
            for (auto & v : g[x-'a'])
                tmp[++cnt] = v;
            g[x-'a'].clear();
            for (int i = 1; i <= cnt; ++i)
                cl[tmp[i]] = y - 'a',g[y-'a'].push_back(tmp[i]);
        }
        scanf("\n");
    }

    for (int i = 1; i <= sl; ++i)
        printf("%c",cl[i]+'a');
}

void sub2()
{
    sub1();
    /*
    while (n -- )
    {
        int type;
        char x;
        scanf("%d %c ",&type,&x);
        if (type == 1)
        {
            /// Update smth

        }
        else
        {
            char y;
            scanf("%c ",&y);
            /// Get result

        }
        scanf("\n");
    }
    */
}
int main()
{
#define file "paint."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    scanf("%d\n",&n);
    if (n <= 10000)
        sub1();
    else
        sub2();
}
