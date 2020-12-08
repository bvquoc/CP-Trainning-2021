#include <bits/stdc++.h>

using namespace std;

char _c; int _q;
#define N 1000101

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
    while (1)
    {
        if (_c >= 'A' && _c <= 'Z')
            return _c;
        _c = getchar();
    }
}

//string s(N, ' ');
char s[N];
int z;
void reads()
{
    _c = getchar();
    while (_c < '(' || _c > ')')
        _c = getchar();
    z = 0;
    while (_c == '(' || _c == ')')
    {
        s[++z] = _c;
        _c = getchar();
    }
}

int n;

struct TNode
{
    int lt_close,rt_open;
    TNode operator + (const TNode &h ) const
    {
        if (lt_close < 0)
            return h;
        if (h.lt_close < 0)
            return *this;
        TNode c;
        c.lt_close = lt_close;
        c.rt_open = h.rt_open;
        if (rt_open < h.lt_close)
        {
            c.lt_close += h.lt_close - rt_open;
        }
        else
        {
            c.rt_open += rt_open - h.lt_close;
        }
        return c;
    }
};

struct IT
{
    TNode f[4*N];

    void update(int id, int l, int r, int p, char c)
    {
        if (r < p || p < l) return;
        if (l==r)
        {
            if (c == '(')
            {
                f[id].lt_close = 0;
                f[id].rt_open = 1;
            }
            else
            {
                f[id].lt_close = 1;
                f[id].rt_open = 0;
            }
        }
        else
        {
            int m = (l+r)/2;
            update(id*2, l, m, p, c);
            update(id*2+1, m+1, r, p, c);
            f[id] = f[id*2] + f[id*2+1];
        }
    }

    TNode get (int id, int l, int r, int u, int v)
    {
        TNode c{-1, -1};
        if (r < u || v < l)
            return c;
        if (u<=l && r<=v)
            return f[id];
        int m = (l+r)/2;
        return get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v);
    }
}it;

void enter()
{
    reads();
    n = readint();
}
#define pii pair<int, int>
vector<pii> ch;

int query2(char t,int u, int v, int id)
{
    int r = 0;
    if (t=='C')
    {
        if (s[u] == '(')
        {
            s[u] = ')';
            it.update(1,1,z,u,')');
        }
        else
        {
            s[u] = '(';
            it.update(1,1,z,u,'(');
        }
        ch.push_back({id, u});
    }
    else if (t == 'Q')
    {
        auto tmp = it.get(1,1,z,u,v);
        r = tmp.lt_close + tmp.rt_open;
    }
    else if (t == 'U')
    {
        for (int j=ch.size()-1; j>=0; j--)
        {
            id = ch[j].first;
            if (id < u)
                break;
            v = ch[j].second;
            if (s[v] == '(')
            {
                s[v] = ')';
                it.update(1,1,z,v,')');
            }
            else
            {
                s[v] = '(';
                it.update(1,1,z,v,'(');
            }
            ch.pop_back();
        }
    }
    return r;
}

void try2()
{
    ch.reserve(n);
    for (int i=1; i<=z; i++)
    {
        it.update(1,1,z,i,s[i]);
    }
    char t; int u,v,r; TNode tmp;
    for (int i=0; i<n; i++)
    {
        t=readchar();
        u=readint();
        if (t == 'Q')
            v = readint();
        r = query2(t,u,v,i+1);
        if (t == 'Q')
            printf ("%d\n", r);
    }
}


void driver()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    enter();
    try2();
}

void test()
{
    for (int ttest=1; ttest <= 100; ttest++)
    {
        cerr << "TEST " << ttest << " : " << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    driver();
    return 0;
}
