#include <bits/stdc++.h>

using namespace std;

#define lint long long
#define ld long double
#define pii pair<int, int>
#define TASK "gift11"
mt19937 rd;

const int N = 2000, oo = 998244353;
int n;
int a[N];

void enter()
{
    cin >> n;
    for (int i=0; i<n; ++i) 
        cin >> a[i];
}

int sub1() 
{
    sort(a, a+n);
    vector<int > p ;
    for (int i=0; i<n; ++i) 
        p.push_back(i);
    int ans = 0, i, sum;
    do 
    {
        stringstream ss;
        for (i=0; i<n; ++i) 
        {
            ss << a[p[i]];
        }
        ss >> sum;
        ans += sum % 11 == 0;
    } while (next_permutation(p.begin(), p.end()));
    return ans;
}

const int P10[11] = {0, 10, 100, 1000 ,10000 ,100000, 1000000, 10000000, 100000000, 1000000000, 1000000001};

int sub2() 
{
    for (int i=0; i<n; ++i) 
    {
        bool ok = false;
        for (int j = 1; j <= 9; j += 2) 
        {
            if (P10[j] <= a[i] && a[i] < P10[j+1])
                ok = true;
        }
        if (!ok) 
            return -1;
    }
    int sumalternate = 0;
    stringstream ss;
    for (int i=0; i<n; ++i) 
    {
        ss << a[i];
    }
    string s; ss >> s;
    int k = 1;
    for (char c : s) 
    {
        sumalternate += (c - '0') * k;
        k = -k;
    }
    int ret = 0;
    if (sumalternate % 11 == 0) 
    {
        ret = 1;
        for (int i=1; i<=n; ++i) 
            ret = (lint)ret * i % oo;
    }
    else 
        ret = 0;
    return ret;
}

void driver()
{
    freopen (TASK".inp", "r", stdin);
    freopen (TASK".out", "w", stdout);
    int T; cin >> T;
    for (int z,t=1; t<=T; ++t) 
    {
        enter();
        z = sub2();
        if (z != -1) 
            cout << z << endl;
        else 
            cout << sub1() << endl;
    }
}

int main()
{
    rd.seed(chrono::high_resolution_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(0);
    driver();
    return 0;
}
