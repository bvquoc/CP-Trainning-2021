#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000005;
struct query
{
    int t;
    char a,b;
};
int cha[maxN + 30],i,N,con[maxN + 30],t,n,u,v;
char a,b;
query Q[10005];
string anss,ans;
void init()
{
    for (i = 1; i <= maxN + 27; i++)
    {
        cha[i] = -1;
    }
}
int getroot(int u)
{
    if (cha[u] < 0) return u;
    cha[u] = getroot(cha[u]);
    return cha[u];
}
void solve()
{
    init();
    int t;
    char a,b;
    int N = 0;
    int u,v;
    for (int i = 1; i <= n; i++)
    {
        t = Q[i].t;
        if (t == 1)
        {
            N++;
            a = Q[i].a;
            u = maxN + a - 'a';
            if (con[u] == 0)
            {
                con[u] = N;
                cha[N] = u;
                cha[u]--;
            } else {
                cha[N] = con[u];
                cha[u]--;
            }
        } else {
            a = Q[i].a;
            b = Q[i].b;
            u = maxN + a - 'a';
            v = maxN + b - 'a';
            if (a == b || con[u] == 0) continue;
            if (con[v] == 0)
            {
                con[v] = con[u];
                cha[con[u]] = v;
                cha[v] += cha[u] + 1;
                cha[u] = -1;

                con[u] = 0;
            } else {
                cha[con[u]] = con[v];
                cha[v] += cha[u] + 1;
                cha[u] = - 1;
                con[u] = 0;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        u = getroot(i);
        anss += (char)(u - maxN + 'a');
    }
}
void trau()
{
    for (int i = 1; i <= n; i++)
    {
        int t = Q[i].t;
        char a = Q[i].a;
        char b = Q[i].b;
        if (t == 1)
        {
            ans+=a;
        } else {
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] == a) ans[i] = b;
            }
        }
    }
}
void reset()
{
    for (int i = 1; i <= n; i++)
    {
        Q[i].t = 0;
        Q[i].a -= Q[i].a;
        Q[i].b -= Q[i].b;
    }
    for (int i = 1; i <= maxN + 27; i++)
    {
        con[i] = 0;
    }
}
void gentest()
{
    n = rand() % 100 + 1;
    for (int i = 1; i <= n; i++)
    {
        Q[i].t = rand() % 2 + 1;
        if (Q[i].t == 1)
        {
            Q[i].a = rand() % 26 + 'a';
            Q[i].b -= Q[i].b;
        } else {
            Q[i].a = rand() % 27 + 'a';
            Q[i].b = rand() % 27 + 'a';
        }
    }
}
void checker()
{
    for(int i = 1; i <= 1000; i++)
    {
        reset();
        gentest();
        ans = "";
        anss = "";
        cout << n << endl;
        for (int j = 1; j <= n; j ++)
        {
            if (Q[j].t == 2) cout << Q[j].t << " " << Q[j].a << " " << Q[j].b << endl;
            else cout << Q[j].t << " " << Q[j].a << endl;
        }
        trau();
        solve();
        cout << "ans = " << ans << endl;
        cout << "out = " << anss << endl;
        if (ans == anss)
        {
            cout << "TEST " <<i <<" OK !!" << endl;
        } else {
            cout << "WA !!!" << endl;
            break;
        }
    }
}
int main()
{
    srand(time(NULL));
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    init();
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d",&t);
        if (t == 1)
        {
            cin >> a;
            N++;
            u = maxN + a - 'a';
            if (con[u] == 0)
            {
                con[u] = N;
                cha[N] = u;
                cha[u]--;
            } else {
                cha[N] = con[u];
                cha[u]--;
            }
        } else {
            cin >> a >> b;
            u = maxN + a - 'a';
            v = maxN + b - 'a';
            if (a == b || con[u] == 0) continue;
            if (con[v] == 0)
            {
                con[v] = con[u];
                cha[con[u]] = v;
                cha[v] += cha[u] + 1;
                cha[u] = -1;

                con[u] = 0;
            } else {
                cha[con[u]] = con[v];
                cha[v] += cha[u] + 1;
                cha[u] = - 1;
                con[u] = 0;
            }
        }
    }
    for (i = 1; i <= N; i++)
    {
        u = getroot(i);
        cout << (char)(u - maxN + 'a');
    }
    //checker();
    return 0;
}
