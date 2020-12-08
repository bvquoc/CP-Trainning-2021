#include <bits/stdc++.h>

using namespace std;

char _c; int _q;

int readint()
{
    _c=getchar();
    while (_c < '0' || _c > '9')
        _c = getchar();
    _q = 0;
    while (_c >= '0' && _c <= '9')
    {
        _q = 10 * _q + _c - '0';
        _c = getchar();
    }
    return _q;
}

char readchar()
{
    _c=getchar();
    while (_c < 'a' || _c > 'z')
        _c = getchar();
    putchar(_c);
    return _c;
}

int n;

#define N 1000001
string s;
struct TQ
{
    int t; char u,v;
} q[N];

void enter()
{
    scanf ("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf ("%d %c", &q[i].t, &q[i].u);
        if (q[i].t == 2)
            scanf (" %c", &q[i].v);
    }
}

void try1()
{
    int t; char u,v; int pos = 0;
    s.resize(n+1);
    for (int i=0; i<n; i++)
    {
        t = q[i].t; u = q[i].u;
        if (t == 1)
        {
            s[pos++] = u;
        }
        else
        {
            //v = readchar();
            v = q[i].v;
            for (int i=0; i<pos; i++)
            {
                if (s[i] == u)
                    s[i] = v;
            }
        }
    }
    s.erase(pos, n+1);
}

map<char, char> mm;

char gmm (char x, char o)
{

    if (x == mm[x]) return x;
    return mm[x] = gmm(mm[x], o);
}

void mt (char u, char v)
{
    mm[u] = v;
}

struct TF
{
    char v; int w;
};

vector<TF> g[128];
int b[128][128];
char dfs (char u, int minw)
{
    int to = u, mw = n*2;
    for (int v = 'a'; v <= 'z' ; v++)
    {
        if (b[u][v] > minw)
        {
            if (b[u][v] < mw)
            {
                mw = b[u][v];
                to = v;
            }
        }
    }
    if (mw == n*2)
        return u;
    return dfs(to, mw);
}

void try2()
{
    int pos = 0;
    for (char i = 'a'; i<='z'; i++)
    for (char j = 'a'; j<='z'; j++)
       b[i][j] = -1;
    for (int i=0; i<n; i++)
    {
        if (q[i].t == 1)
        {
            pos++;
        }
    }
    int j=pos-1;
    s.resize(pos);
    for (int i=n-1; i>=0; i--)
    {
        if (q[i].t == 1)
        {
            s[j--] = dfs(q[i].u, i);
        }
        else
        {
            if (q[i].u == q[i].v) continue;
            b[q[i].u][q[i].v] = i;
        }
    }
}


void print()
{
    cout << s;
}

void driver()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    enter();
    try1();
    print();
}
/*
void test()
{
    mt19937 rd(time(0));
    for (int ttest=1; ttest <= 100000; ttest++)
    {
        cerr << "TEST " << ttest << " : " << endl;
        n = rd()%40 + 1;
        for (int i=0; i<n; i++)
        {
            q[i].t = ((rd() % 100) < 20) + 1;
            q[i].u = rd() % 8 + 'a';
            q[i].v = rd() % 8 + 'a';
        }

        s = "";
        try1();
        string s1 = s;
        s = "";
        cerr << " running .. ";
        auto st = chrono::high_resolution_clock::now();
        try2();
        auto se = chrono::high_resolution_clock::now();
        string s2 = s;
        cerr << " time = " << (se - st).count() / 1e6 << "ms.\n";
        if (s1==s2)
        {
            cerr << "OK " << endl;
        }
        else
        {
            cerr << "WA \n";

            cerr << "s1 = " << s1 << endl;
            cerr << "s2 = " << s2 << endl;
            cerr << n << endl;
            for (int i=0; i<n; i++)
            {
                cerr << q[i].t << " " << q[i].u;
                if (q[i].t == 2) cerr << " " << q[i].v;
                cerr << endl;
            }
            cerr << endl;break;
        }
    }
}

void ptest()
{

}*/

int main()
{
    ios_base::sync_with_stdio(0);
    driver();
    return 0;
}
