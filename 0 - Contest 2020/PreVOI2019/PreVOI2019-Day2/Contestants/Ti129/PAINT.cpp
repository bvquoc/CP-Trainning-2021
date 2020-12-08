#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define Task "PAINT"
//PAINT

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000015;
const int inf = 0x3f3f3f3f;

void InOut();
#define debug(X) cout << #X << " = " << X << '\n'
vector<int> pos[26];
int n;
void tron(vector<int> &a, vector<int> b){
    vector<int> c;
    int i = 0, j = 0;
    int n = sz(a), m = sz(b);
    while(i < n && j < m){
        if (a[i] > b[j]){
            c.push_back(b[j]);
            ++j;
        } else {
            c.push_back(a[i]);
            ++i;
        }
    }
    while(i < n){
        c.push_back(a[i]);
        ++i;
    }
    while(j < m){
        c.push_back(b[j]);
        ++j;
    }
    for(int i = 0; i < n + m; ++i){
        if (i < n) a[i] = c[i];
        else {
            a.push_back(c[i]);
        }
    }
}
char s[N];
void subtask1(){
    int cur = 0;
    for(int i = 1; i <= n; ++i){
        int type;
        char c, d;
        cin >> type >> c;
        if (type == 1){
            ++cur;
            pos[c - 'a'].push_back(cur);
        } else {
            cin >> d;
            if (c == d) continue;
            tron(pos[d - 'a'], pos[c - 'a']);
            pos[c - 'a'].clear();
        }
    }
    for(int c = 0; c < 26; ++c){
        for(int i = 0; i < sz(pos[c]); ++i) s[pos[c][i]] = char(c + 'a');
    }
    for(int i = 1; i <= cur; ++i) cout << s[i];
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    subtask1();
return 0;
}

void InOut(){
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
}

