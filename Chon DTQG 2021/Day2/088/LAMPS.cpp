#include <bits/stdc++.h>

using namespace std;

int n, t;
int l[3005];
int res=-1;
int u[3005];
int re[3005];
vector <int> a[3005];
void check() {
    for (int i=1; i<=n; i++)
        if (l[i]==0)
            return;
    res=0;
    for (int i=1; i<=n; i++) {
        re[i]=u[i];
        if (re[i]==1) res++;
    }
}
void Try(int i) {
    for (int j=0; j<=1; j++)
        if (res==-1) {
            l[i]=(l[i]+j)%2;
            u[i]=j;
            if (j==1) {
                for (int k=0; k<a[i].size(); k++)
                    l[a[i][k]]=(l[a[i][k]]+j)%2;
            }
            if (i==n) {
                check();
            } else
                Try(i+1);
            l[i]=(l[i]+j)%2;
            if (j==1) {
                for (int k=0; k<a[i].size(); k++)
                    l[a[i][k]]=(l[a[i][k]]+j)%2;
            }
        }
}
int main() {
    freopen("LAMPS.INP","r",stdin);
    freopen("LAMPS.OUT","w",stdout);
    scanf("%d%d", &n, &t);
    for (int i=1, x, y; i<=n; i++) {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int j=1; j<=n; j++)
        scanf("%d", &l[j]);
    Try(1);
    if (res==-1) {
        printf("%d", res);
        return 0;
    }
    printf("%d ", res);
    for (int i=1; i<=n; i++)
        if (re[i]==1)
            printf("%d ", i);
    return 0;
}
