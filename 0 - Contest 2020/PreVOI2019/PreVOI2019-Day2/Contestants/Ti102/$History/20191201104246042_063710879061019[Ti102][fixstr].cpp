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

const int N = 4e7+7;
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

void readstring(string &s){
    char c;
    for(c=getchar();c!=')' && c!='(';c=getchar());
    for(;c==')' || c == '('; c=getchar()) s.push_back(c);
}

char readchar(){
    char c;
    for(c=getchar();!isalpha(c);c=getchar());
    return c;
}

void print(ll num){if(num>9)print(num/10);putchar(num%10+48);}

struct node{
    int opt = 0, open = 0, close = 0;
};

node null_node;

node operator + (node a, node b){
    node c;
    int tmp = min(a.open, b.close);
    c.opt = a.opt + b.opt + tmp;
    c.open = a.open + b.open - tmp;
    c.close = a.close + b.close - tmp;
    return c;
}

node st[N];
int L[N], R[N];
int ver[N], cur = 1, cnode = 1, que;

void Refresh(int id){
    st[id] = st[L[id]] + st[R[id]];
}

void build(int id, int l, int r, int u, int val){
    if(u > r || u < l) return;
    if(l == r){
        if(val == 0) st[id].open = 1;
        else st[id].close = 1;
        return;
    }
    int m = (l + r) >> 1;
    if(u <= m){
        if(!L[id]) L[id] = ++cnode;
        build(L[id], l, m, u, val);
        Refresh(id);
    }else{
        if(!R[id]) R[id] = ++cnode;
        build(R[id], m+1,r,u,val);
        Refresh(id);
    }
}

void upd(int id, int l, int r, int u, int val, int old){
    if(u > r || u < l) return ;
    if(l == r){
        if(val == 0) st[id].open = 1;
        else st[id].close = 1;
        return;
    }
    int m = (l + r) >> 1;
    if(u <= m){
        L[id] = ++cnode;
        upd(L[id], l, m, u, val, L[old]);
        R[id] = R[old];
        Refresh(id);
    }else{
        L[id] = L[old];
        R[id] = ++cnode;
        upd(R[id], m+1,r,u,val, R[old]);
        Refresh(id);
    }
}

node Get(int id, int l, int r, int u, int v){
    if(u > r || v < l) return null_node;
    if(l >= u && r <= v) return st[id];
    int m = (l + r) >> 1;
    if(!L[id] && !R[id]) return null_node;
    if(!L[id]) return Get(R[id], m + 1, r, u, v);
    if(!R[id]) return Get(L[id], l, m, u, v);
    return Get(L[id], l, m, u, v) +
            Get(R[id], m + 1, r, u, v);
}

int trau_sml(string &s, int l, int r){
    int c0(0), c1(0);
    _u(i,l,r){
        if(s[i] == '(') ++c0;
        else{
            if(c0) --c0;
            else ++c1;
        }
    }
    return c0 + c1;
}

#define task "fixstr"

int main(){
    FIO();
    FI(task);
    #ifndef HOHO
        FO(task);
    #endif // HOHO

    string s(" "); readstring(s);
    int n = (int)s.size() - 1;

    ver[1] = 1; que = 1;
    _u(i,1,n){
        if(s[i] == '(') build(1, 1, n, i, 0);
        else build(1, 1, n, i, 1);
    }

    int m = readint();
    _u(i,1,m){
        char c = readchar();
        if(c == 'C'){
            int u = readint();
            int Now = Get(ver[cur], 1, n, u, u).open;

            ver[++que] = ++cnode;
            upd(ver[que], 1, n, u, Now, ver[cur]);
            cur = que;
        }
        if(c == 'U'){
            cur = readint(); --cur;
        }
        if(c == 'Q'){
            int u = readint(), v = readint();
            node ans = Get(ver[cur], 1, n, u, v);
            print(ans.close + ans.open); putchar('\n');
            ///cout << trau_sml(s, u, v) << endl;
        }
    }
    return 0;
}
