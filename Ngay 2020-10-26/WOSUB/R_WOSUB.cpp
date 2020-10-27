#include <bits/stdc++.h>
using namespace std;
const string NAME = "WOSUB";
const int NTEST = 100;


long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + (rand()%1000) * 1LL * (rand()%1000) % (h - l + 1);
}

const int N = 100005;
int n, a[N], S;
int psum[N];

int main() {
    srand(time(NULL));
    freopen("WOSUB.INP","w",stdout);
    n = 100, psum[n+1]; psum[0] = 0;
    cout << n << endl;
    for (int i=1; i<=n; i++) {
        a[i] = abs(Rand(700,800));
        cout << a[i] << ' ';
        psum[i] = psum[i-1] + a[i];
    } cout << endl;
    
    map <int,int> mp;
    for (int l=1; l<=n; l++) for (int r=l; r<=n; r++) {
        int s = psum[r]-psum[l-1];
        mp[s]++;
    }
    int cnt = 0;
    for (map <int,int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        pair <int,int> x = *it;
        if (x.second > cnt) {
            cnt = x.second;
            S = x.first;
        }
    }
    cout << S;
    return 0;
}