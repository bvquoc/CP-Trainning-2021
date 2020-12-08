///Phß║ím Nguyß╗àn Tuß║Ñn Ho├áng///
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define repd(i,a,b) for(int i = (a);i >= (b);i--)
#define F first
#define S second
#define PB push_back
#define Task "oddcoin"
using namespace std;
//template <class T> inline read(T &a){a = 0;char c;bool nega = 0;while(!isdigit(c = getchar()) && c != '-');if(c == '-') nega = 1,c = getchar();a = c - 48;while(isdigit(c = getchar()))a = a * 10 + c - 48;if(nega) a = -a;}
//template <class T> inline writep(T a){if(a > 9) writep(a / 10);putchar(a % 10 + 48);}
//template <class T> inline write(T a){if(a < 0) putchar('-'),a = -a;writep(a);putchar(' ');}
//template <class T> inline writeln(T a){write(a);putchar('\n');}
int coin[] = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,0};

int get(int x)
{
    int sl = 0;
    repd(i,14,0) sl += x / coin[i],x %= coin[i];
    return sl;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    int q;
    cin >> q;
    while(q--)
    {
        int x,t;
        cin >> x >> t;
        coin[15] = x;
        if(x <= 1e5)
        {
            vector<int> f(t+1,1e9);
            f[0] = 0;
            rep(i,1,t)
                rep(j,0,15) if(i >= coin[j])
                    f[i] = min(f[i],f[i-coin[j]] + 1);
            cout << f[t] << '\n';
        }
        else
        {
            int ans = 1e9;
            rep(i,0,100000)
            {
                if(t / x < i) break;
                ans = min(ans,get(t - x * i) + i);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
