#include<bits/stdc++.h>

using namespace std;

vector<int> c = {50000,30000,10000,5000,3000,1000,500,300,100,50,30,10,5,3,1};

int work()  {
    int x;  cin >> x;
    int t;  cin >> t;

    int ans = t;
    int cnt = 0;

    for(int i = t ; i >= 0 ; i -= x, ++cnt) {
        if (cnt > 5e4)
            break;
        int a = i;
        int C = 0;
        for(int z : c)
            C += a / z,
            a %= z;
        ans = min(ans,C + cnt);
    }
    return  ans;
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef combi
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    #endif // combi

    int itest;
    cin >> itest;

    while (itest--)
        cout << work() << "\n";
}
/*
4
4700 53
4700 9400
4700 9401
4700 30000
*/

