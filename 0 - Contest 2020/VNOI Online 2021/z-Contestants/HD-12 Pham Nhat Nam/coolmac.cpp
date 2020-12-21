#include <bits/stdc++.h>
#define file "coolmac."
using namespace std;
#define pb push_back
#define x first
#define y second
#define ll long long
const int oo = 1e9 + 9;
const ll inf = 1e18 + 18;
const int max6 = 1e6 + 6;
const int modx = 1e9 + 7;
const int mody = 997;
const int base = 137;
typedef pair <int,int> ii;
//////////////////////////
typedef pair<int,int> ii;

ii a[100005];
int q[100005];
int lazy[100005];

int L,R,n,m;

void qpush(int x)
{
    while (L <= R && q[R] < x)
        R--;
    q[++R] = x;
}

void qpop(int x)
{
    if (q[L] == x)
        L++;
}

//////////////////////////
main()
{
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    scanf("%d",&m);

    for (int i = 1; i <= m; ++i)
        scanf("%d %d",&a[i].x,&a[i].y);

    sort(a+1,a+m+1);

    scanf("%d",&n);

    int l = 100000;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d",&x);

        l = min(l,x);
    }

    // check

    for (int i = 1; i <= m; ++i)
        lazy[a[i].x]++,lazy[a[i].y+1]--;
    for (int i = 1; i <= 100000; ++i)
    {
        lazy[i] += lazy[i-1];
        if (i >= l && lazy[i] == 0)
        {
            printf("-1");
            return 0;
        }
    }

    // check = ok
    int j = 0;
    int res = 0;

    L = 1,R = 0;

    while (l <= 100000)
    {
        while (j < m && a[j+1].x <= l)
            j++,qpush(a[j].y);

        int nl = q[L];
        qpop(nl);
        l = nl+1;
        res++;
    }

    printf("%d",res);
}

