#include <bits/stdc++.h>
using namespace std;
const int max6 = 1e6 + 6;
const int oo = 1e9 + 9;
const int max3 = 1e3 + 3;

int it[4*max6],dt[4*max6];
int a[max6],s[max6],id[max6],be[max6],en[max6];
int arr[max3][max3];
int tmp[max6];
char ch[max6],type[max6];
int n,m,sl = 0;

void update(int r,int k,int l,int u,int v,int delta)
{
    if (k > v || u > l)
        return;
    if (u <= k && l <= v)
    {
        dt[r] += delta;
        return;
    }

    int g = (k + l) / 2;

    dt[2*r] += dt[r];
    dt[2*r+1] += dt[r];
    dt[r] = 0;

    update(2*r,k,g,u,v,delta);
    update(2*r+1,g+1,l,u,v,delta);

    it[r] = min(it[2*r] + dt[2*r],it[2*r+1] + dt[2*r+1]);
}

int get(int r,int k,int l,int u,int v)
{
    if (k > v || l < u)
        return oo;
    if (u <= k && l <= v)
        return it[r] + dt[r];

    dt[2*r] += dt[r];
    dt[2*r+1] += dt[r];
    dt[r] = 0;

    int g = (k + l) / 2;

    int tl = get(2*r,k,g,u,v);
    int tr = get(2*r+1,g+1,l,u,v);

    it[r] = min(it[2*r] + dt[2*r],it[2*r+1] + dt[2*r+1]);
    return min(tl,tr);
}
int main()
{
#define file "fixstr."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    scanf("%s",ch+1);
    n = strlen(ch+1);
    for (int i = 1; i <= n; ++i)
        a[i] = (ch[i] == '(') ? 1 : -1,s[i] = s[i-1] + a[i];
    scanf("%d\n",&m);
    bool existu = false;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%c ",&type[i]);
        if (type[i] == 'U')
            existu = true;
        if (type[i] == 'U' || type[i] == 'C')
            scanf("%d",&id[i]);
        else
            scanf("%d %d",&be[i],&en[i]);
        scanf("\n");
    }
    update(1,1,n,1,n,0);
    for (int i = 1; i <= n; ++i)
        update(1,1,n,i,i,s[i]);
    for (int i = 1; i <= m; ++i)
    {
        if (type[i] == 'C')
        {
            int old = a[id[i]];
            a[id[i]] = -a[id[i]];
            int bonus = a[id[i]] - old;
            if (existu)
            {
                for (int j = 1; j <= n; ++j)
                    arr[i][j] = get(1,1,n,j,j);
                tmp[++sl] = i;
            }
            update(1,1,n,id[i],n,bonus);
        }
        else if (type[i] == 'Q')
        {
            int id1 = be[i],id2 = en[i],res = 0;
            ///
            int bonus = 0;
            if (id1 > 1)
                bonus = get(1,1,n,id1-1,id1-1);
            int gmin = get(1,1,n,id1,id2) - bonus;
            int var = get(1,1,n,id2,id2) - bonus;
            if (gmin > 0)
                res = res + var;
            else
            {
                if (var == gmin)
                    res = res + abs(gmin);
                else
                    res = res + 2 * abs(gmin) + var;
            }
            printf("%d\n",res);
        }
        else if(type[i] == 'U')
        {
            int pos = tmp[upper_bound(tmp+1,tmp+sl+1,id[i]) - tmp - 1];
            for (int j = 1; j <= n; ++j)
                arr[i][j] = get(1,1,n,j,j);
            for (int j = 1; j <= 4*n; ++j)
                it[j] = dt[j] = 0;
            for (int j = 1; j <= n; ++j)
                update(1,1,n,j,j,arr[pos][j]);
            tmp[++sl] = i;
        }
        scanf("\n");
    }
}
