#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ins insert
#define era erase

using namespace std;

string tt[100009], s;
int x, k, y, m;
char type, doi[300];

int tinh(int l, int r)
{
    int ans = 0, d = 0;
    for(int i=l; i<=r; ++i)
    {
        if(s[i] == '(')
            d++;
        else d--;
        //cout << s[i];
        if(d < 0)
            ans+= abs(d), d = 0;
    }
    return ans + d;
}

void sub_1()
{
    doi['('] = ')'; doi[')'] = '(';
    tt[0] = s;
    for(int i=1; i<=m; ++i)
    {
        cin >> type;
        if(type == 'C')
        {
            cin >> x;
            s[x] = doi[s[x]];
        }
        if(type == 'U')
        {
            cin >> k;
            s = tt[k -1];
        }
        tt[i] = s;
        if(type == 'Q')
        {
            cin >> x >> y;
            cout << tinh(x, y) << '\n';
        }
    }
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    #endif //ONLINE_JUDGE
    cin >> s;
    s = ' ' + s;
    cin >> m;
    if(m <= 1000)
        sub_1();
    sub_1();
    return 0;
}
