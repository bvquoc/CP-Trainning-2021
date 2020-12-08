///Phß║ím Nguyß╗àn Tuß║Ñn Ho├áng///
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define repd(i,a,b) for(int i = (a);i >= (b);i--)
#define F first
#define S second
#define PB push_back
#define Task "paint"
using namespace std;
//template <class T> inline read(T &a){a = 0;char c;bool nega = 0;while(!isdigit(c = getchar()) && c != '-');if(c == '-') nega = 1,c = getchar();a = c - 48;while(isdigit(c = getchar()))a = a * 10 + c - 48;if(nega) a = -a;}
//template <class T> inline writep(T a){if(a > 9) writep(a / 10);putchar(a % 10 + 48);}
//template <clas s T> inline write(T a){if(a < 0) putchar('-'),a = -a;writep(a);putchar(' ');}
//template <class T> inline writeln(T a){write(a);putchar('\n');}
const int N = 1000012;
int n,root[27],r[N];

int gr(int u)
{
    return r[u] > 0? r[u] = gr(r[u]) : u;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n;
    int cnt = 0;
    memset(root,-1,sizeof root);
    rep(i,1,n)
    {
        int type;
        char x,y;
        cin >> type >> x;
        x -= 'a';
        if(type == 1)
        {
            cnt++;
            if(root[x] == -1) root[x] = cnt,r[cnt] = -(x);
            else r[cnt] = gr(root[x]);
        }
        else
        {
            cin >> y;
            y -= 'a';
            if(x == y) continue;
            if(root[y] == -1) root[y] = root[x],r[root[x]] = -(y),root[x] = -1;
            else r[root[x]] = gr(root[y]),root[x] = -1;
        }
    }
    rep(i,1,cnt)
    {
        int x = gr(i);
        cout << char(-r[x] + 'a');
    }

    return 0;
}
