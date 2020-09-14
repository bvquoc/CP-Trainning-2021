#include <bits/stdc++.h>
#define int long long

using namespace std;

int x1, y1, u1, v1;
int x2, y2, u2, v2;
int32_t main()
{
    freopen("DIENTICH.INP","r",stdin);
    freopen("DIENTICH.OUT","w",stdout);
    scanf("%lld%lld%lld%lld", &x1, &y1, &u1, &v1);
    scanf("%lld%lld%lld%lld", &x2, &y2, &u2, &v2);
    if (x1>u1) swap(x1,u1);
    if (y1>v1) swap(y1,v1);
    if (x2>u2) swap(x2,u2);
    if (y2>v2) swap(y2,v2);
    //printf("%lld %lld %lld %lld\n", x1, y1, u1, v1);
    //printf("%lld %lld %lld %lld", x2, y2, u2, v2);
    //return 0;
    //u1=u1-x1;
    //u2=u2-x2;
    //v1=v1-y1;
    //v2=v2-y2;
    int res = (abs(min(u1,u2) - max(x1,x2))) * (abs(min(v1,v2) - max(y1,y2)));
    printf("%lld", res);
    return 0;
}
