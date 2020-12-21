#include <bits/stdc++.h>
#define maxn 10005

using namespace std;

int x[maxn];
int y[maxn];
string info[maxn];
long long L[maxn];
int n, m;
int k[5];

bool ok2(int X,int Y)
{
    for(int i=1; i<=m; ++i)
    {
        if(info[i] == "GCD")
        {
            if(__gcd(X,Y) == L[i]) continue;
            else return false;
        }
        else
        {
            if((X * Y)/ __gcd(X,Y) == L[i]) continue;
            else return false;
        }
    }
    return true;
}

bool tmn2()
{
    for(int i=1; i<=200; ++i)
        for(int j=1; j<=200; ++j)
        {
            if(ok2(i, j))
            {
                return true;
            }
        }
    return false;
}

bool ok3()
{
    for(int i=1; i<=m; ++i)
    {
        if(info[i] == "GCD")
        {
            long long h = __gcd(k[x[i]], k[y[i]]);
            if(h == L[i]) continue;
            else return false;
        }
        else
        {
            long long h = 1ll * (k[x[i]] * k[y[i]]) / __gcd(k[x[i]], k[y[i]]);
            if(h == L[i]) continue;
            else return false;
        }
    }
    return true;
}

bool tmn3()
{
    for(int i=1; i<=200; ++i)
    for(int j=1; j<=200; ++j)
    for(int kh=1; kh<=200; ++kh)
    {
        k[1] = i;
        k[2] = j;
        k[3] = kh;
        if(ok3()) return true;
    }
    return false;
}

void subtask1()
{
    if(n == 1) cout<<"N";

    if(n == 2)
    {
        if(tmn2()) cout<<"Y";
        else cout<<"N";
    }

    if(n == 3)
    {
        if(tmn3()) cout<<"Y";
        else cout<<"N";
    }
}
int main()
{
    freopen("GCDLCM.inp", "r", stdin);
    freopen("GCDLCM.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q, t;
    cin>>Q>>t;
    for(int k=1; k<=t; ++k)
    {
        scanf("%d %d", &n, &m);
        long long maxl = 0;
        for(int i=1; i<=m; ++i)
        {
            cin>>info[i]>>x[i]>>y[i]>>L[i];
            maxl = max(maxl, L[i]);
        }

        if(n <= 3 && maxl <= 100) subtask1();
        else cout<<"Y";
    }
}
