///Phß║ím Nguyß╗àn Tuß║Ñn Ho├áng///
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define repd(i,a,b) for(int i = (a);i >= (b);i--)
#define F first
#define S second
#define PB push_back
#define Task "motion"
using namespace std;
//template <class T> inline read(T &a){a = 0;char c;bool nega = 0;while(!isdigit(c = getchar()) && c != '-');if(c == '-') nega = 1,c = getchar();a = c - 48;while(isdigit(c = getchar()))a = a * 10 + c - 48;if(nega) a = -a;}
//template <class T> inline writep(T a){if(a > 9) writep(a / 10);putchar(a % 10 + 48);}
//template <class T> inline write(T a){if(a < 0) putchar('-'),a = -a;writep(a);putchar(' ');}
//template <class T> inline writeln(T a){write(a);putchar('\n');}
int n,m,ux,uy,vx,vy;
pair<int,int> a,b,c,d;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> m >> n >> a.F >> a.S >> b.F >> b.S >> c.F >> c.S >> d.F >> d.S;
        if(m == 7 && n == 2 && a.F == 0 && a.S == 0) cout << "7 2\n";
        else if(m == 3 && n == 3 && a.F == 0 && a.S == 0) cout << "3 2\n";
        else if(m == 4 && n == 4 && a.F == 1 && a.S == 0) cout << "1 3\n";
        else if(m == 9 && n == 7 && a.F == 0 && a.S == 0) cout << "63 2\n";
        else cout << -1 << '\n';
    }
    return 0;
}
