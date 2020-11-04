#include <bits/stdc++.h>
using namespace std;

int k, dem = -1;

int main() {
    scanf("%d", &k);
    if (k < 0) while(k < 0) dem = dem + 2, k = k + dem;
    //cout << k;
    while(k != (int)sqrt(k) * (int)sqrt(k))
        dem = dem + 2, k = k + dem;
    printf("%d", (int)sqrt(k));
    return 0;
}
