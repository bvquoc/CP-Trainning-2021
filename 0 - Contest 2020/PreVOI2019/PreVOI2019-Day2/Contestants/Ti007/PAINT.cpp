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
#define TASK "PAINT"
const int M = 1e5+8;
const int oo = 1e9+7;
using namespace std;

// mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Type, n, id = 1;
char a[M], x, y, Val[M];
string Res = "";
vector < Pii > G;

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

int main(int argc, char const *argv[]){
	// freopen("test.txt", "r", stdin);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ios_base::sync_with_stdio(false);   cin.tie(0);
    n = _in();

    for(char i = 'a'; i <= 'z'; i++) Val[i] = i;

    for(int i = 1; i <= n; i++){
        Type = _in();
        if(Type == 1){
            x = _inC();
            G._pb(_mp(-1, x));
        }
        else{
            x = _inC(), y = _inC();
            G._pb(_mp(x, y));
        }
    }

    for(int i = n-1; i >= 0; i--){
        if(G[i].st == -1)
            Res = (char)Val[G[i].nd] + Res;
        else 
            Val[G[i].st] = Val[G[i].nd];
    }

    cout << Res;
	return 0; 
}
