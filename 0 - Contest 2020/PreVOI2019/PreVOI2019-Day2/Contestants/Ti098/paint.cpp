#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ins insert
#define era erase
#define pcc pair < char, char >
#define N 1000009

using namespace std;

pcc a[N];
char ch[N], x, y, noi[1000], c;
int T[N], n, type;
string res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    #endif //ONLINE_JUDGE
    cin >> n;
    res = " ";
    for(int i=1; i<=n; ++i)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> c;
            ch[i] = c;
        }
        else
        {
            cin >> x >> y;
            a[i] = {x, y};
        }
        T[i] = type;
    }

    for(char k = 'a'; k<='z'; ++k)
        noi[k] = k;

    for(int i=n; i>=1; --i)
    {
        if(T[i] == 2)
        {
            noi[a[i].F] = noi[a[i].S];
        }
        else
        {
            res = noi[ch[i]] + res;
        }
    }
    cout << res;
    return 0;
}
