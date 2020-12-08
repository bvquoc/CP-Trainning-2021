#include <bits/stdc++.h>

using namespace std;

int n , m;
int p[15], a[1000000], x[15], nho[15], sl;

/*void xuly()
{
    for(int i = 1; i <= m; ++i)
        p[i] = a[x[i]], cerr << a[x[i]] << " ";

    cerr << '\n';

    int i = 2;
    int t = 0;
    while(i <=m)
    {
        if(p[i] < p[i-1] || p[i] > p[i-1] + m){t = 1; break;}
        i += 2;
    }

    if(t == 0) sl++;
}
void thu(int k)
{
    if(k > m){xuly(); return;}
    for(int i = 1; i <= m; ++i)
    {
        if(nho[i] == 0)
        {
            nho[i] = 1;
            x[k] = i;
            thu(k+1);
            nho[i] = 0;
        }
    }
}*/
int main()
{
    freopen("Mine.inp","r",stdin);
    freopen("Mine.out","w",stdout);

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);

    /*sl = 0;
    thu(1);*/
    printf("%d", n - 1);
}
