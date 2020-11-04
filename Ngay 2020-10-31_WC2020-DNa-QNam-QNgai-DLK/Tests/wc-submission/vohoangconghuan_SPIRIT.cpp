#include<bits/stdc++.h>

using namespace std;

long long a,b,c;
int main()
{
//    #ifndef ONLINE_JUDGE
//    freopen("SPIRIT.inp","r",stdin);
//    freopen("SPIRIT.out","w",stdout);
//    #endif // ONLINE_JUDGE
    cin >> a >> b >> c;
    long long tmp = c;
    c = (a / c) * c + c * (a % c != 0);
    long long d = 0;
    while (a<b)
    {
        long long target = min(b, c - 1);
        d += (target - a) / 2 + (target - a) % 2;
        c += tmp;
        a = target;
    }
    cout<<d;
}
