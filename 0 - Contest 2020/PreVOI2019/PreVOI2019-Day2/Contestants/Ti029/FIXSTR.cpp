/// NHDanDz
#include <bits/stdc++.h>
#define nmax 1000006
#define MOD 1000000000007
#define F first
#define S second
#define PB push_back
#define reset(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define ll long long
#define DANGCUTO "FIXSTR"
#define endl '\n'
#define sz() size()
using namespace std;
string S , s[1005];
int m , k[1005];
pii it[nmax];
void sub1()
{
    s[0] = S;
    for(int i = 1; i <= m; i++)
    {
        char t;
        cin >> t;
        if(t == 'Q')
        {
            s[i] = s[i - 1];
            reset(k);
            int l , r , ans(0);
            cin >> l >> r;
            for(int j = l - 1; j <= r - 1; j++)
            {
                if(s[i][j] == '(')
                {
                    k[j] = k[j - 1] + 1;
                }
                else
                {
                    k[j] = k[j - 1] - 1;
                }
                if(k[j] < 0)
                {
                    k[j] = 0;
                    ans ++;
                }
            }
            cout << ans + k[r - 1] << endl;
        }
        else if(t == 'C')
        {
            int x;
            cin >> x;
            s[i] = s[i - 1];
            if(s[i][x - 1] == '(')
                s[i][x - 1] = ')';
            else
                s[i][x - 1] = '(';
        }
        else
        {
            int x;
            cin >> x;
            s[i] = s[x - 1];
        }
    }
}
void make(int id, int l ,int r)
{
    if(l == r)
    {
        if(S[l] == '(')
        {
            it[id].F = 1;
            it[id].S = 0;
        }
        else
        {
            it[id].S = 1;
            it[id].F = 0;
        }
        return;
    }
    int mid = (l + r)/2;
    make(id * 2, l ,mid);
    make(id * 2 + 1, mid + 1, r);
    int t1 = min(it[id * 2].F , it[id * 2 + 1].S);
    it[id].F = it[id * 2].F + it[id * 2 + 1].F - t1;
    it[id].S = it[id * 2].S + it[id * 2 + 1].S - t1;
}
void update(int id ,int l,int r ,int u)
{
    if(r < u || l > u)
        return;
    if(l == r && l == u)
    {
       it[id].F = 1 - it[id].F;
       it[id].S = 1 - it[id].S;
       return;
    }
    int mid = (l + r)/2;
    update(id * 2, l , mid , u);
    update(id * 2 + 1 , mid + 1, r ,u);
    int t1 = min(it[id * 2].F , it[id * 2 + 1].S);
    it[id].F = it[id * 2].F + it[id * 2 + 1].F - t1;
    it[id].S = it[id * 2].S + it[id * 2 + 1].S - t1;
}
pii get(int id ,int l ,int r ,int u ,int v)
{
    if(r < u || l > v)
    {
        return {0,0};
    }
    if(l >= u && r <= v)
    {
        return it[id];
    }
    int mid = (l + r)/2;
    pii x = get(id * 2 , l ,mid , u , v) , y = get(id * 2 + 1, mid + 1 , r , u , v);
    int t1 = min(x.F,y.S);
    return {x.F + y.F - t1, y.S + x.S - t1};
}
void sub2()
{
    S = ' ' + S;
    make(1,1,S.sz() - 1);
    for(int i = 1; i <= m; i++)
    {
        char t;
        cin >> t;
        if(t == 'Q')
        {
            int l , r;
            cin >> l >> r;
            pii ans = get(1,1,S.sz() - 1,l,r);
            cout << ans.F + ans.S  << endl;
        }
        else
        {
            int x;
            cin >> x;
            update(1,1,S.sz() - 1,x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(DANGCUTO".inp","r",stdin);
    freopen(DANGCUTO".out","w",stdout);
    cin >> S >> m;
    if(S.sz() <= 1000 && m <= 1000)
        sub1();
    else
        sub2();
    return 0;
}
