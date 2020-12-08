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

const int N = 1e3+7;
const ll M = 1ll*1e9+7;

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

int a[] = {0 ,1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};

int f[20][1000007];

#define task "oddcoin"

int main(){
    FIO();
    FI(task);
    #ifndef HOHO
        FO(task);
    #endif // HOHO

    memset(f, 63, sizeof f);
    _u(i,0,15) f[i][0] = 0;
    _u(t,1,1e6) _u(i,1,15){
        f[i][t] = f[i-1][t];
        if(t >= a[i]) f[i][t] = min(f[i][t], f[i][t-a[i]] + 1);
    }
    int q; cin >> q;
    while(q--){
        int x, t, res = __INT_MAX__;
        cin >> x >> t;
        for(int i = 0; i * x <= t; ++i)
            res = min(res, i + f[15][t - i * x]);
        cout << res << endl;
    }
    return 0;
}
