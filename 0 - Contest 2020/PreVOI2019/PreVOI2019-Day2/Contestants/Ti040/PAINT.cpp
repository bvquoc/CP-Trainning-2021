#include <bits/stdc++.h>

template < typename T > inline void read(T &x)
{
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = x * 10 + c - 48;
}

using namespace std;
#define taskname "PAINT"

int n, N;
int root[255];
int a[1000005];
int b[1000005];
int c[1000005];
int pos[1000005];
priority_queue < int > pos2[255];

inline void delay(int x, int y)
{
    for (int i = 1; i <= N; i++)
        if (b[i] == x)
            b[i] = y;
}

int find(int u)
{
    return ((root[u] == u)? u: root[u] = find(root[u]));
}

inline void delay2()
{
    for (int i = 1; i <= N; i++)
            putchar(b[i]);
}

inline void maket()
{
    freopen (taskname".inp", "w", stdout);
    cout << 20 << '\n';
    srand(time(NULL));
    for (int i = 1; i <= 20; i++)
    {
        int u = rand() % 2 + 1;
        cout << u << " ";
        int x = rand() % 26;
        cout << (char)(x + 'a') << " ";
        if (u == 2)
        {
            x = rand() % 26;
            cout << (char)(x + 'a') << '\n';
        }
        else
            cout << '\n';
    }
}

int main()
{
    #ifdef duyenn
        //maket();
    #endif // duyenn
    if (fopen (taskname".inp", "r"))
    {
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    }
    read(n);
    {
        int id, x, y;
        char ch, ch2;
        for (int i = 0; i < 255; i++)
            pos2[i].push(0);
        for (int i = 1; i <= n; i++)
        {
            read(id);
            ch = getchar();
            while (!isalpha(ch))
                ch = getchar();
            x = (int)ch;
            if (id == 2)
            {
                ch2 = getchar();
                while (!isalpha(ch2))
                    ch2 = getchar();
                y = (int)ch2;
                if (x == y)
                    continue;
                if (pos[x] > 0)
                {
                    int tmp = c[pos[x]];
                    pos[y] = pos[x];
                    c[pos[x]] = y;
                    pos[x] = 0;
                    for (int i = pos[x] - 1; i > 0; i--)
                        if (a[i] == tmp || c[i] == tmp)
                        {
                            c[i] = tmp;
                            pos[tmp] = i;
                            break;
                        }
                }
                if (n <= 10000)
                    delay(x, y);
            }
            else
            {
                a[++N] = x;
                b[N] = x;
                pos[x] = N;
                pos2[x].push(i);
            }
        }
    }
    if (n <= 10000)
    {
        delay2();
        return 0;
        putchar('\n');
    }
    for (int i = 0; i < 255; i++)
        root[i] = i;
    for (int i = N; i >= 1; i--)
    {
        int u = find(a[i]);
        if (c[i] != 0)
        {
            int v = find(c[i]);
            root[a[i]] = v;
            a[i] = v;
        }
        else
            a[i] = u;
    }
    for (int i = 1; i <= N; i++)
            putchar(a[i]);
}
