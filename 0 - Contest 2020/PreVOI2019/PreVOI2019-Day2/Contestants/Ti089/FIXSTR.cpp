#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define nmax 100005
#define MOD 1000000007
#define pii pair<long long, long long>
#define ll long long
#define Task "FIXSTR"
#define sqr(x) (x) * (x)
#define For(i,x,y) for(int i=x; i <= y ; i++)
#define oo
using namespace std;
string str;
char s;
int u , v , n;
string tv[nmax];
string dao(int u , string l){
    string tg = l;
    if(tg[u-1] == '(')
        tg[u-1]=')';
    else
        tg[u-1] = '(';
    return tg;
}
string tinh(int i , int j , string l)
{
    int tg = 0 , res = 0;
    For(t , i - 1 , j - 1 )
    {
        if(l[t] == '(')
            tg ++;
        else
            tg -- ;
        if(tg < 0){
            res = res +(0-tg);
            tg = 0;
        }
    }
    if(tg != 0)
        res += tg;
    cout<< res<< endl;
    return l;
}
void enter ()
{
    cin >> str;
    tv[0] = str;
    cin >> n;
    For(i , 1 , n)
    {
        cin >> s;
        if(s == 'C'){
            cin >> u;
            tv[i] = dao(u , tv[i-1]);
        }
        if(s == 'Q'){
            cin >> u >> v;
            tv[i] = tinh(u , v , tv[i-1]);
        }
        if( s == 'U'){
            cin >> u;
            tv[i] = tv[u-1];
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    enter();

    }
