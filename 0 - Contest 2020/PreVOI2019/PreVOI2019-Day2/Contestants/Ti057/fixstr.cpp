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
#define Kurumi "fixstr"
#define nmax 1000005
const ll OO = 1e9+7 ;

using namespace std;
string s;
string x[nmax];
int n;
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
void check(int a){
    if(s[a - 1] == '('){
        s[a - 1] = ')';
        return;
    }
    if(s[a - 1] == ')'){
        s[a - 1] = '(';
        return;
    }
}

int _check(int a, int b){
    a--;
    b--;
    int l = a,r = b;
    int d1 = 0;
    int x = 0;
    int y = 0;
    for(int i = a; i <= b; i++){
        l = i;
        if(s[i] == ')'){
            x++;
        }
        else break;
    }
    for(int i = b; i >= a; i--){
        r = i;
        if(s[i] == '('){
            y++;
        }
        else break;
    }
    if(l == b && s[b] == ')') l++;
    if(r == a && s[r] == '(') r--;
    for(int i = l; i <= r; i++){
        if(s[i] == '(') d1++;
        else d1--;
    }
    int xx = abs(d1 - 0) + x + y;
    return xx;
}
void kurumi(){
    cin >> s;
    x[0] = s;
    cin >> n;
    int N = n;
    for(int i = 1; i <= n; i++){
        char type;
        int a,b;
        cin >> type;
        if(type == 'C'){
            cin >> a;
            check(a);
            x[i] = s;
//            cout << s << '\n';
        }
        if(type == 'Q'){
            cin >> a >> b;
            int res = _check(a,b);
            cout << res << '\n';
            x[i] = s;
//            cout << s << '\n';
        }
        if(type == 'U'){
            cin >> a;
            s = x[a - 1];
            x[i] = s;
//            cout << s << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen(Kurumi".inp","r",stdin);
    freopen(Kurumi".out","w",stdout);
    kurumi();
    return 0;
}
