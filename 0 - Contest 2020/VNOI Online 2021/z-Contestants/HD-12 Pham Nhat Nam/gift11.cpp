#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second
const ll inf = 1e18 + 18;
const int oo = 1e9 + 9;
const int max6 = 1e6 + 6;
const int modx = 1e9 + 7;
const int mody = 997;
const int base = 137;
//////////////////////////
void debug(vector<int> a)
{
    for (auto & v : a)
        cerr<<v<<" ";
    cerr<<"\n";
}
//////////////////////////

const int mod = 998244353;

int p[15];

int a[2005];
int x[2005];
int y[2005];

int n,t;


void buff()
{
    for (int i = 1; i <= n; ++i)
        p[i] = i;

    int res = 0;
    do
    {
        int sum = 0;
        int id = 1;
        for (int i = 1; i <= n; ++i)
        {
            int x = a[p[i]];
            while (x)
            {
                int dig = x%10;
                x /= 10;
                if (id)
                    sum = (sum+dig)%11;
                else
                    sum = (sum-dig+11)%11;
                id = 1-id;
            }
        }

        res += (sum == 0);
    }
    while (next_permutation(p+1,p+n+1));

    printf("%d\n",res);
}

bool checkSub(int id)
{
    if (id == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            int x = a[i];
            int cnt = 0;
            while (x > 0)
                x /= 10,cnt++;
            if (cnt%2)
                return false;
        }
        return true;
    }

    if (id == 2)
    {
        for (int i = 1; i <= n; ++i)
        {
            int x = a[i];
            int cnt = 0;
            while (x > 0)
                x /= 10,cnt++;
            if (cnt%2 == 0)
                return false;
        }

        return true;
    }

    return false;
}

void sub1()
{
    //
    int sum = 0;
    int id = 1;
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i];
        while (x > 0)
        {
            int dig = x%10;
            x /= 10;
            if (id)
                sum = (sum+dig)%11;
            else
                sum = (sum+11-dig)%11;
            id = 1-id;
        }
    }

    int res = 1;
    for (int i = 1; i <= n; ++i)
        res = 1ll*res*i%mod;

    if (sum)
        res = 0;
    printf("%d\n",res);
}

void sub2()
{
    buff();
}

//////////////////////////
main()
{
#define file "gift11."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    scanf("%d",&t);

    while (t -- )
    {
        scanf("%d",&n);
        int sum = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d",&a[i]);

        if (checkSub(1))
            sub1();
        else if (checkSub(2))
            sub2();
        else buff();
    }
}


