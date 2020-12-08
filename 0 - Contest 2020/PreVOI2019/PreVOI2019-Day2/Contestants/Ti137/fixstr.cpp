#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int n, m, b[1000005], b1[1000006], dd[1000005], k[1000005], f[1000005], s[1000005];
char a[1000005];
typedef pair<int, int> II;
typedef pair<int, II> III;
III lenh[1000005];

void tinh1(int u)
{
    b[u] = -b[u];
}

void tinh2(int u, int v)
{
    for(int j = u; j <= v; ++j) f[j] = k[j] = 0;
    int sn = 0;
    for(int j = u; j <= v; ++j)
    if(b[j] == 1) s[++sn] = j;
    else if(sn > 0) k[j] = s[sn--];
    int fmax = 0;
    for(int j = u; j <= v; ++j)
    if(b[j] == 1) f[j] = 0;
    else if(k[j]) {
        f[j] = f[k[j] - 1] + j - k[j] + 1;
        fmax = max(fmax, f[j]);
    }
    //cout<<v<<" "<<u<<" "<<fmax<<endl;
    int dem = v - u + 1 - fmax;
    printf("%d\n", dem);

}

void tinh3(int u)
{
    for(int i = 1; i <= n; ++i) b[i] = b1[i];
    for(int i = 1; i < u; ++i)
    {
        int type = lenh[i].fi, u = lenh[i].se.fi;
        if(type == 1) tinh1(u);
        else if(type == 3) tinh3(u);
    }
}

void sub1()
{
    for(int i = 1; i <= n; ++i) if(a[i] == '(') b1[i] = b[i] = 1;
                                else b1[i] = b[i] = -1;
    for(int i = 1; i <= m; ++i)
    {
        int type = lenh[i].fi, u = lenh[i].se.fi, v = lenh[i].se.se;
        if(type == 1)
        {
            tinh1(u);
        }
        else if(type == 2)
        {
            tinh2(u, v);
        }
        else{
            tinh3(u);
        }
       // for(int j = 1; j <= n; ++j) cout<<b[j]<<" ";
        //cout<<endl;
    }
}

int main()
{
    freopen("fixstr.inp", "r", stdin);
    freopen("fixstr.out", "w", stdout);
    scanf("%s", a + 1);
    n = strlen(a + 1);
    scanf("%d", &m);
    char type;
    int u, v;
    bool ok = true;
    for(int i = 1; i <= m; ++i)
    {
        scanf(" %c ", &type);
        if(type == 'C')
        {
            scanf("%d", &u);
            lenh[i] = III(1, II(u, 0));
        }
        else if(type == 'Q')
        {
            scanf("%d %d", &u, &v);
            lenh[i] = III(2, II(u, v));
        }
        else{
            scanf("%d", &u);
            lenh[i] = III(3, II(u, v));
            ok = false;
        }
    }
    sub1();
}
