#include <bits/stdc++.h>

#define _u(i,a,b) for(int i=(a);i<=(b);++i)
#define _d(i,a,b) for(int i=(a);i>=(b);--i)
#define FIO() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FI(task) freopen(task".inp","r",stdin);
#define FO(task) freopen(task".out","w",stdout);
#define fillchar(a, x) memset(a, x, sizeof(a))
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define endl "\n"

using namespace std;

const int N = 2e3+7;
const ll M = 1ll*1e6+3;

void write(){}
template<typename T, typename ...Ts>
void write(const T &first, const Ts &...rest){
    cout << first << ' ';
    write(rest...);
}
template<typename ...Ts>
void writeln(const Ts &... rest){
    write(rest...);
    cout << endl;
}

int readint(){
    int num(0); char c; bool neg(0);
    for(c=getchar();c<'0'||c>'9';c=getchar()) neg|=c=='-';
    for(;c>='0'&&c<='9';c=getchar()) num=num*10+c-48;
    return neg?-num:num;
}

void print(ll num){if(num>9)print(num/10);putchar(num%10+48);}

void ADD(int &a, int b){
    a += b;
    if(a > M) a-=M;
}

int n, m;
int a[N*2];
int f[N][N];

#define task "mine"

int main(){
    FIO();
    FI(task);
    #ifndef HOHO
        FO(task);
    #endif // HOHO

    cin >> n >> m;
    _u(i,1,n+n) cin >> a[i];
    f[1][1] = (a[2] - a[1] <= m);
    _u(i,1,n) _u(j,max(2, i),n){
        int s = (i-1) * 2 + 1;
        int t = (j - i)*2 + s + 1;
        if(a[t] - a[s] > m) continue;

        if(i == j)
            _u(k,1,i-1) ADD(f[i][j], f[k][i-1]);
        else
            ADD(f[i][j], f[i][j-1]);

    }
    int res(0);
    _u(i,1,n) ADD(res, f[i][n]);
    cout << res;
    return 0;
}
