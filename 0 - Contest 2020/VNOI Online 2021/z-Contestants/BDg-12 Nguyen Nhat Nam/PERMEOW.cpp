#include <bits/stdc++.h>

using namespace std;

#define lint long long
#define ld long double
#define pii pair<int, int>
#define TASK "PERMEOW"
mt19937 rd;

const int N = 200002, oo = 1000000007;
int a[N], b[N], n;

void enter()
{
    cin >> n;
    for (int i=1; i<=n; ++i) 
        cin >> a[i];
    for (int i=1; i<=n; ++i) 
        cin >> b[i];
}

int x[N];

int getFX() 
{
    int ret =0 ;
    for (int i=1; i<=n; ++i) 
    for (int j=i+1; j<=n; ++j) 
    {
        ret += x[i] > x[j];
    }
    return ret;
}

int sub1() 
{
    copy(a+1, a+n+1, x+1);
    int cur = 0, sum = 0, same,i;
    do 
    {
        cur = getFX();
        sum = (sum + cur ) % oo;
        same = 1;
        for (i=1; i<=n; ++i) 
            same &= x[i] == b[i];
        if (same) break;
    } while (next_permutation(x+1, x+n+1));
    return sum;
}

bool checksub2() 
{
    for (int i=1; i<=n; ++i) 
    {
        if (a[i] != i) 
            return false;
        if (b[i] != n - i + 1) 
            return false;
    }
    return true;
}

int pw (int a, int b) 
{
    if (b == 0) 
        return 1;
    int c = pw(a, b/2);
    c = c * (lint)c % oo;
    if (b % 2 == 1) 
        c = c * (lint) a % oo;
    return c;
}

int sub2() 
{
    lint ret = 1;
    for (int i=1; i<=n; ++i) 
        ret = ret * i % oo;
    ret = ret * n % oo * (n - 1) % oo  * pw(4, oo - 2) % oo;
    return ret;
}

int target[N];

struct BIT 
{
    int n;
    vector<int> f;
    BIT (int n) : n(n)
    {
        f.assign(n + 1, 0);
    }
    void update (int p, int w) 
    {
        for (;p <= n; p += p & -p) 
            f[p] += w;
    }
    int get(int p) 
    {
        int ret = 0;
        for (;p;p-=p&-p) 
            ret += f[p];
        return ret;
    }
};

int f[N][2];
int fact[N];

void buildTargetA() 
{
    BIT bit(n);
    for (int i=1; i<=n; ++i) 
        bit.update(i, 1);
    for (int i=1; i<=n; ++i) 
    {
        target[i] = bit.get(a[i]);
        bit.update(a[i], -1);
    }
}

void buildTargetB() 
{
    next_permutation(b+1, b+n+1);
    BIT bit(n);
    for (int i=1; i<=n; ++i) 
        bit.update(i, 1);
    for (int i=1; i<=n; ++i) 
    {
        target[i] = bit.get(b[i]);
        bit.update(b[i], -1);
    }
    prev_permutation(b+1, b+n+1);
}


lint sub3Target() 
{
    for (int i=1; i<=n+1; ++i) 
        f[i][0] = f[i][1] = -1;
    lint ret = 0;
    for (int i=1, j=n-1, multiplier, b1, b2 = 0, acount; i<n; ++i, --j) 
    {
        acount = target[i] - 1;
        b1 = (lint) j *(j - 1)/2 % oo;
        if (acount) 
        {
            multiplier = ((lint)acount * b1 % oo + (lint)acount * (acount - 1) % oo + b2 * (lint)acount) % oo;
            ret = (ret + (lint) multiplier * (lint)(fact[j]) % oo) % oo;
            b2 += acount*2;
            b2 %= oo;
        }
    }
    ret = ret * pw(2, oo - 2) % oo;
    return ret;
}

lint sub3() 
{
    for (int i=n; i>=0; --i) 
    {
        a[i+1] = a[i] + 1;
        b[i+1] = b[i] + 1;
    }
    ++n;
    fact[0] =1;
    for (int i=1; i<=n; ++i) 
    {
        fact[i] = fact[i-1] * (lint)i % oo;
    }
    buildTargetB();
    lint rb = sub3Target();
    buildTargetA();
    lint ra = sub3Target();
    return ((rb - ra) % oo + oo) % oo;
}

int rnd(int x) 
{
    return rd() % x;
}

bool testgen() 
{
    n = rd() % 5 + 4;
    for (int i=1; i<=n; ++i)
        a[i] = b[i] = i;
    random_shuffle(a+1, a+n+1, rnd);
    random_shuffle(b+1, b+n+1, rnd);
    int cmp = 0;
    for (int i=1; i<=n; ++i) 
    {
        if (a[i] > b[i]) 
        {
            cmp = -1; break;
        }
        else if (a[i] < b[i]) 
        {
            cmp = 1; break;
        }
    }
    if (cmp == -1) 
        for (int i=1; i<=n; ++i) 
            swap(a[i], b[i]);
    for (int i=1; i<=n; ++i) 
    {
        if (b[i] != n - i + 1) 
            return true;
    }
    return false;
}

void printtest() 
{
    cerr << n << '\n';
    for (int i=1; i<=n; ++i) cerr << a[i] << ' '; cerr << '\n';
    for (int i=1; i<=n; ++i) cerr << b[i] << ' '; cerr << '\n';
}

void checker() 
{
    int T = 20000;
    for (int t = 1; t <= T; ++t) 
    {
        cerr << "TEST " <<t <<'\n';
        while (!testgen());
        //printtest();
        auto x = sub1(); 
        auto y = sub3();
        //cerr << "expected = " << x << " , found = " << y << '\n';
        if (x != y) 
        {
            printtest();
            cerr << "expected = " << x << " , found = " << y << '\n';
            cerr << "WA!"; break;
        }
        else 
        {
            cerr << "OK!"; 
        }
    }
}

bool checksub1() 
{
    for (int i=1; i<=n; ++i) 
    {
        if (a[i] != b[i]) 
            return false;
    }
    return true;
}

void driver()
{
    freopen (TASK".inp", "r", stdin);
    freopen (TASK".out", "w", stdout);
    enter();
    if (checksub2()) 
        cout << sub2();
    else if (checksub1())
        cout << sub1();
    else 
        cout << sub3();
}

int main()
{
    rd.seed(chrono::high_resolution_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(0);
    driver();
    return 0;
}
