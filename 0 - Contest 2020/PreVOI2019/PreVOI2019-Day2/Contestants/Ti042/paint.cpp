#include<bits/stdc++.h>

using namespace std;

const int   N   = 1e6 + 1;

int p[26];
int t[N];
int a[N], b[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef combi
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    #endif // combi

    iota(p,p + 26,0);

    int q;  cin >> q;

    for(int i = 1 ; i <= q ; ++i)   {
        cin >> t[i];
        char x, y;
        cin >> x;
        a[i] = x - 'a';

        if (t[i] ^ 1)   {
            cin >> y;
            b[i] = y - 'a';
        }
    }
    stack<int>  st;

    for(int i = q ; i >= 1 ; --i)   {
        if (t[i] == 1)  st.push(p[a[i]]);
        if (t[i] == 2)  p[a[i]] = p[b[i]];
    }

    while (st.size())   {
        int x = st.top();
        st.pop();
        cout << (char)('a' + x);
    }
}
/*
10
1 c
1 b
1 a
1 c
1 d
2 a b
1 c
1 a
1 b
2 b d
*/
