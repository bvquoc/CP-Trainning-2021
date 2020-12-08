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

int x,t;

void enter()
{
    cin >> x >> t;
}

#define N2 100001
#define oo 1000000000
int f[N2];

set<int> C = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};

int sub2()
{
    for (int i = 0; i<=t; i++)
    {
        f[i] = oo;
    }
    f[0] = 0;
    C.insert(x);
    for (int c:C)
    {
        for (int i=c; i<=t; i++)
        {
            f[i] = min(f[i], f[i-c] + 1);
        }
    }
    C.erase(x);
    return f[t];
}

#define N3 50000001
int p[N3];
const int d[10] = {0,1,2,1,2,1,2,3,2,3};

void init3()
{
    for (int i=1,j; i<=10000; i++)
    {
        j = i;
        while (j)
        {
            p[i] += d[j % 10];
            j /= 10;
        }
    }
    int mm = 10000;
    for (int i=10001,x=1,y=1; i<=N3; i++)
    {
        p[i] = p[x] + p[y];
        y++;
        if (y == mm)
        {
            x++; y=0;
        }
    }
}

int sub3()
{
    int r = N3,e;
    for (int i=0,j=t; j>=0;i++,j-=x)
    {
        e = p[j] + i;
        //cerr << "(i=" << i << ")*t   p[j] = " << e << endl;
        r = min(r, e);
    }
    //cerr << endl;
    return r;
}

int sub4()
{

}

void driver()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    int T; cin >> T;
    bool ib = 1;
    init3();
    while (T--)
    {
        enter();
        if (x < N2 && t < N2)
        {
            cout << sub2() << endl;
        }
        else
        {
            cout << sub3() << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    driver();
    return 0;
}
