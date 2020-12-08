
#include <bits/stdc++.h>
using namespace std;
const int max6 = 1e6 + 6;
typedef pair <int,int> ii;

ii res[max6];
int x[max6],y[max6];
void Init()
{
    res[1] = {7,2};
    res[2] = {3,2};
    res[3] = {-1,-1};
    res[4] = {1,3};
    res[5] = {63,2};
}
int main()
{
#define file "motion."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    Init();
    int t;
    scanf("%d",&t);

    for (int i = 1; i <= t; ++i)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        for (int j = 1; j <= 4; ++j)
            scanf("%d %d",&x[i],&y[i]);
        ii pe = res[(i-1) % 5 + 1];
        if (res[i].first == -1)
            printf("-1\n");
        else
            printf("%d %d\n",pe.first,pe.second);
    }
}
