///Kurumi
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Pii pair < int, int >
#define Piii pair < Pii, int >
#define Vi vector < int >
#define Vii vector < Pii >
#define pb push_back
#define mp make_pair
#define reset(x) memset(x, 0, sizeof(x))
#define fi first
#define se second
#define Kurumi "paint"
#define nmax 1000005
const ll OO = 1e9+7 ;

using namespace std;
int T;
queue < int > qq;
string s = "";
Vi gg[1005];
int read(){
    int res = 0;
    char c = getchar();
    bool Neg = false;
    while(c == ' ' || c == '\n') c = getchar();
    if(c == '-'){
        Neg = true;
        c = getchar();
    }
    while('0' <= c && c <= '9'){
        res = res * 10 + c - '0';
        c = getchar();
    }
    if(Neg) return -res;
    return res;
}

void kurumi(){
    cin >> T;
    for(int i = 1; i <= T; i++)
        qq.push(i);
    while(T--){
        int type;
        char x,y;
        cin >> type;
        if(type == 1){
            cin >> x;
            s += x;
            int z = qq.front();
            gg[x - '0'].pb(z);
            qq.pop();
        }
        else{
            cin >> x >> y;
            for(auto xx : gg[x - '0']){
                s[xx - 1] = y;
                gg[y - '0'].pb(xx);
            }
            gg[x - '0'].clear();
        }
    }
    cout << s;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen(Kurumi".inp","r",stdin);
    freopen(Kurumi".out","w",stdout);
    kurumi();
    return 0;
}
