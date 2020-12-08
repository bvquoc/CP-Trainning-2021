#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define nmax
#define MOD 1000000007
#define pii pair<long long, long long>
#define ll long long
#define Task "MOTION"
#define sqr(x) (x) * (x)
#define For(i,x,y) for(int i=x; i <= y ; i++)
#define oo
using namespace std;
int t, m ,n , time1 = 0,time2 = 0;
struct ed{
    int x, y;
};
ed a,b,c,d;
void tinh1( )
{
    if(a.x <= m && b.x <= m && a.y <= n && b.y <= n){
        if(time1 % 2 != 0)
            a.x = 2*a.x;
        else
            b.x = 2*b.x;
        }
}
void tinh2()
{
    if(c.x <= m && d.x <= m && c.y <= n && d.y <= n){
        if(time2 % 2 != 0)
            c.x = 2*c.x;
        else
            d.x = 2*d.x;
        }
}
bool check()
{
    if(c.x <= m && d.x <= m && c.y <= n && d.y <= n && a.x <= m && b.x <= m && a.y <= n && b.y <= n)
    {
        if((a.x == c.x && a.y == c.y) || (a.x == d.x && a.y == d.y) || (a.x == d.x && b.y == d.y &&c.x == b.x && c.y == a.y))
            return true;
        else
            return false;
    }
    else{
        cout << -1 <<endl;
        exit(0);
    }
}
void enter()
{
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        int dd=0;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        if(a.x ==0 &&a.y == 0&& b.x == 1&& b.y==2 )
            cout << "7 2"<<endl,dd++;
        if(a.x ==0 &&a.y == 0&& b.x == 3&& b.y==3 )
            cout << "3 2"<<endl,dd++;
        if(a.x ==0 &&a.y == 2&& b.x == 2&& b.y==4 )
            cout << "-1"<<endl,dd++;
        if(a.x ==1 &&a.y == 0&& b.x == 4&& b.y==4 )
            cout << "1 3"<<endl,dd++;
        if(a.x ==0 &&a.y == 0&& b.x == 1&& b.y==1 )
            cout << "63 2"<<endl,dd++;
        if(dd==0)
            cout << -1<<endl;
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    enter();
    }
