// @___justkiddin
#include <bits/stdc++.h>
#define ll long long
#define Pii pair<int, int>
#define Piii pair<int, Pii>
#define _mp make_pair
#define _pb push_back
#define st first
#define nd second
#define whole(x) x.begin(), x.end()
#define Reset(x) memset(x, 0, sizeof(x))
#define PI acos(-1)
#define TASK "FIXSTR"
const int M = 1e6+8;
const int oo = 1e9+7;
using namespace std;

// mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

string s, Last[M];
int n, x, l, r, k, N;
char Query;

struct Queryx{
    int t, l, r;
};

int _in(){
    int tmp = 0; char x = getchar();
    while(x == ' ' || x == '\n') x = getchar();
    while('0' <= x && x <= '9') tmp = tmp * 10 + (x - '0'), x = getchar();
    return tmp;
}

char _inC(){
    char x = getchar();
    while(x == ' ' || x == '\n') x = getchar();
    return x;
}

string _inS(){
    string tmp = ""; char x = getchar();
    while(x == ' ' || x == '\n') x = getchar();
    while(x == '(' || x == ')') tmp = tmp + x, x = getchar();
    return tmp;
}

int _predict(int l, int r){
    if(l > r) return 0;
    if(l == r) return 1;
    if(s[l] == '('){
        if(s[l+1] == ')') 
            return _predict(l+2, r);
        else{
            if(s[r] == ')'){
                if(s[r-1] == '(') 
                    return _predict(l, r-2);
                else 
                    return _predict(l+1, r-1);
            }
            else
                return 1 + _predict(l, r-1);
        }
    }
    else
        return 1 + _predict(l+1, r);
}

int main(int argc, char const *argv[]){
	// freopen("test.txt", "r", stdin);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ios_base::sync_with_stdio(false);   cin.tie(0);

    s = _inS(), n = _in();

    N = s.size();   s = ' ' + s; 
    // cerr << _predict(1, N) << '\n';
    
    for(int i = 1; i <= n; i++){
        Query = _inC();
        Last[i] = s;
        if(Query == 'C'){
            x = _in();
            s[x] = (s[x] == ')' ? '(' : ')');
        }
        if(Query == 'Q'){
            l = _in(), r = _in();
            // for(int i = l; i <= r; i++) cerr << s[i]; cerr << " | ";
            cout << _predict(l, r) << '\n';
        }
        if(Query == 'U'){
            k = _in();
            s = Last[k];
        }
    }
	return 0; 
}