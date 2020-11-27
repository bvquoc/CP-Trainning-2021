/* 𝙰𝚞𝚝𝚑𝚘𝚛: 𝙱𝚞𝚒 𝚅𝚒 𝚀𝚞𝚘𝚌 */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define SPACE putchar(' ')
#define endl '\n'
// #define int long long
using namespace std;

/*
(\_/)
( •_•)
/ >?? */

int n;
vector <int> a, c;
vector <bool> b;

// #define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("A.INP","r",stdin);
    freopen("A.OUT","w",stdout);
    #endif
    cin >> n >> n;
    a.assign(n+1, 0); b.assign(n+1, 0);
    int i;
    for (i = 1; i <= n; i++) cin >> a[i];

    for (i = 1; i <= n; i++) if (a[i] != -1) b[a[i]] = 1;

    for (i = 1; i <= n; i++) if (!b[i]) c.push_back(i);
    
    int j = 0;
    for (i = 1; i <= n; i++) if (a[i] == -1) a[i] = c[j++];

    // cout << sizeof a + sizeof b + sizeof n + sizeof i + sizeof c + sizeof N + sizeof j + sizeof sz  << endl;

    for (i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
}