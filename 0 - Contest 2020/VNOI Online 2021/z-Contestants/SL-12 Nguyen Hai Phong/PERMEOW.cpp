///PERMEOW
#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
const int N = 200005;
const int mod = 1000000007;
int numN, a[N], b[N], c[N], d[N], p[N];

int main()
{
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
    scanf("%d",&numN);
    for(int i = 1; i <= numN; ++i)
        scanf("%d",&a[i]), c[i] = a[i];
    for(int i = 1; i <= numN; ++i)
        scanf("%d",&b[i]);
    std::sort(a + 1, a + 1 + numN);
    long long ans = 0;
    for(int i = 1; i <= numN; ++i)
    {
        int y = i;
        if(a[i] == c[i]) continue;
        for(int j = i + 1; j <= numN; ++j)
            if(a[i] == c[j])
            {
                y = j;
                break;
            }
        ans += 1LL*y-1;
        if(ans >= mod) ans -= mod;
        for(int j = y; j > 1; --j) std::swap(c[j], c[j-1]);
    }
    ans += ans;
    if(ans >= mod) ans -= mod;
    printf("%lli",ans);
//    if(n <= 2000) sub123();
//    else sub4();
    return 0;
}
