///Phß║ím Nguyß╗àn Tuß║Ñn Ho├áng///
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define repd(i,a,b) for(int i = (a);i >= (b);i--)
#define F first
#define S second
#define PB push_back
#define Task "construct"
using namespace std;
//template <class T> inline read(T &a){a = 0;char c;bool nega = 0;while(!isdigit(c = getchar()) && c != '-');if(c == '-') nega = 1,c = getchar();a = c - 48;while(isdigit(c = getchar()))a = a * 10 + c - 48;if(nega) a = -a;}
//template <class T> inline writep(T a){if(a > 9) writep(a / 10);putchar(a % 10 + 48);}
//template <class T> inline write(T a){if(a < 0) putchar('-'),a = -a;writep(a);putchar(' ');}
//template <class T> inline writeln(T a){write(a);putchar('\n');}
const int N = 100012;
int n,m;
long long a[N];

long long get(int l,int r,int val)
{
    if(l > r) return 0;
    if(l == r) return a[l] - val;
    int vt = min_element(a+l,a+r+1) - a;
    return get(l,vt - 1,a[vt]) + get(vt + 1,r,a[vt]) + a[vt] - val;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        rep(i,1,n) cin >> a[i];
        while(m--)
        {
            int type;
            cin >> type;
            if(type == 1)
            {
                int l,r,val;
                cin >> l >> r >> val;
                rep(i,l,r) a[i] += val;
            }
            else
            {
                int l,r;
                cin >> l >> r;
                cout << get(l,r,0) << '\n';
            }
        }
    }
    return 0;
}
