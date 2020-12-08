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

#define N 2001
int n,a[N],m;

void enter()
{
    scanf ("%d%d", &n, &m);
    for (int i=1; i<=2*n; i++)
        scanf ("%d", &a[i]);
}
#define mod 1000003
#define lint long long

vector<lint> x;

lint sub2()
{
    x.assign (n+1, 0);
    x[0] = x[1] = 1;
    for (int i=2; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            x[i] += x[j-1] * x[i-j];
            if (x[i] > mod)
                x[i] %= mod;
        }
    }
    return x[n];
}

lint f[N][N];

lint sub3()
{
    for (int i=1; i<=n*2+1; i++)
    for (int j=1; j<=n*2+1; j++)
        f[i][j] = 0;
    for (int i=1; i<=n*2+1; i++)
    {
        f[i][i-1] = 1;
        f[i][i+1] = (a[i+1] - a[i] <= m);
    }
    for (int l=4; l<=2*n; l+=2)
    {
        for (int i=1,j=l; j<=n*2; i++,j++)
        {
            for (int k=i+1; k<=j; k+=2)
            {
                if ((a[k] - a[i] <= m))
                {
                    f[i][j] += f[i+1][k-1] * f[k+1][j];
                    if (f[i][j] >= mod)
                        f[i][j] %= mod;
                }
                else break;
            }
        }
    }
    return f[1][n*2] % mod;
}

lint sub4()
{
    for (int i=1; i<=n*2+1; i++)
    for (int j=1; j<=n*2+1; j++)
        f[i][j] = 0;
    for (int i=1; i<=n*2+1; i++)
    {
        f[i][i-1] = 1;
        f[i][i+1] = (a[i+1] - a[i] <= m);
    }
    for (int l=4; l<=2*n; l+=2)
    {
        for (int i=1,j=l; j<=n*2; i++,j++)
        {
            for (int k=i+1; k<=j; k+=2)
            {
                if ((a[k] - a[i] <= m))
                {
                    f[i][j] += f[i+1][k-1] * f[k+1][j];
                    if (f[i][j] >= mod)
                        f[i][j] %= mod;
                }
            }
        }
    }
    return f[1][n*2] % mod;
}


int b[110],r1=0;

int ch()
{
    stack<int> s;
    for (int i=1; i<=n*2; i++)
    {
        if (b[i])
        {
            if (s.empty())
                return 0;
            int t = s.top();
            s.pop();
            if (a[i] - t > m)
                return 0;
        }
        else
        {
            s.push(a[i]);
        }
    }
    return !!s.empty();
}

void rec(int i, int d = 0)
{
    if (i > n*2)
    {
        int e = ch();
        r1 += e;
    }
    else
    {
        if ((d + 1) <= (2* n - i + 1))
        {
            b[i] = 0;
            rec(i+1, d + 1);
        }
        if (d - 1 >= 0)
        {
            b[i] = 1;
            rec(i+1, d - 1);
        }
    }
}
int sub1()
{
    r1 = 0;
    rec(1,0);
    return r1;
}

void driver()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    enter();
    if (m == 1000000)
        cout << sub2();
    else
    {
        sub2();
        cout << sub3();
    }
}

void test()
{
    mt19937 rd(time(0));
    for (int t=1; t<=3000; t++)
    {
        n = rd()%10 + 1;
        m = rd()%15 + 1;
        set<int> s;
        while (s.size() < 2*n)
        {
            s.insert(rd()%30+1);
        }
        int i = 1;
        for (auto ii: s)
            a[i++] = ii;
        cerr << "TEST #" << t << ": " << endl;
        cerr << n << " " << m << endl;
        for (int i=1; i<=2*n; i++)
            cerr << a[i] << " ";
        cerr << endl;
        lint s1 = sub1();
        lint s3 = sub3();
        cerr << "s1 = " << s1 << endl << "s3 = " << s3 << endl;
        if (s1 == s3 )
        {
            cerr << " OK !" << endl;
        }
        else
        {
            cerr << " WA !" << endl; break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    driver();
    return 0;
}
