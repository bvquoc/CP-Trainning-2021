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
#define DANGCUTO "PAINT"
#define endl '\n'
#define sz() size()

using namespace std;
string kq;
int n , root[30][nmax];
int get_root(int u ,int k)
{
    return (root[u][k] == 0) ? u : (root[u][k] = get_root(root[u][k],k));
}
void sub1()
{
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            char t ;
            cin >> t;
            kq = kq + t;
        }
        else
        {
            char a , b;
            cin >> a >> b;
            for(int i = 0; i < kq.sz(); i ++)
            {
                if(kq[i] == a)
                {
                    kq[i] = b;
                }
            }
        }
    }
    cout << kq;
}
struct haidang
{
    int type;
    char a , b;
}s[nmax];
int len[nmax];
void sub2()
{
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i].type;
        len[i] = len[i - 1];
        if(s[i].type == 1)
        {
            cin >> s[i].a;
            len[i] ++;
        }
        else
            cin >> s[i].a >> s[i].b;
    }
    for(int i = n; i >= 1; i--)
    {
        for(int j = 1; j <= 26; j++)
            root[j][i] = root[j][i + 1];
        if(s[i].type == 2)
        {
            int a = s[i].a - 'a' + 1 , b = s[i].b - 'a'+ 1;
            int p = get_root(a , i) , q = get_root(b , i);
            if(p != q)
            {
                root[a][i] = q;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(s[i].type == 1)
        {
            cout << (char) (get_root(s[i].a - 'a' + 1 , i) +'a' - 1);
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
    cin >> n;
    if(n <= 10000)
        sub1();
     else
        sub2();
    return 0;
}
