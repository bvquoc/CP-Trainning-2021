#include <bits/stdc++.h>

using namespace std;
const int maxN =2e5 + 1;
long long n, a[maxN], b[maxN];

int main()
{
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
    freopen("PERMEOW.inp", "r", stdin);
    //freopen("PERMEOW.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >>a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    long long res = 0;
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        for(j; j <= n; j++)
            if(a[j] == i) break;
        while(j != i){
            swap(a[j], a[j - 1]);
            j--;
            res++;
        }
    }
    cout<<res;
}
