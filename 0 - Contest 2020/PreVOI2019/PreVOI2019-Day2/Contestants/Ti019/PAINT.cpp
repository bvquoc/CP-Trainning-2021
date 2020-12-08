#include<bits/stdc++.h>

#define maxn 1000005

using namespace std;
typedef long long ll;

int n;

char a[maxn];

int type[maxn];

char ch[maxn], ch1[maxn];
char d[500];

int main(){
    #define TASK "PAINT"
    freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    scanf("%d", &n);

    for (int i = 'a'; i <= 'z'; ++i)
        d[i] = i;

    for (int i = 0; i < n; ++i){
        scanf("%d%s", &type[i], ch + i);
        if (type[i] == 2) scanf("%s", ch1 + i);
    }

    int _n = 0;
    for (int i = n - 1; i >= 0; --i)
        if (type[i] == 2)
            d[ch[i]] = d[ch1[i]];
        else
            a[_n++] = d[ch[i]];

    reverse(a, a + _n);

    cout << a;
    return 0;
}
