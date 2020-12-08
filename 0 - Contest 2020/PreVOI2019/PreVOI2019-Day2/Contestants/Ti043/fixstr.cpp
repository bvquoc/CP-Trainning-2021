#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define maxn 1000005

using namespace std;
int n;
string str[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ifstream cin("fixstr.inp");
    ofstream cout("fixstr.out");
    cin >> str[0];
    cin >> n;
    FOR(i, 1, n){
        str[i] = str[i-1];
        char ty; cin >> ty;
        if(ty == 'C'){
            int x; cin >> x;
            if(str[i][x-1] == ')') str[i][x-1] = '(';
            else str[i][x-1] = ')';
        }
        if(ty == 'U'){
            int k; cin >> k;
            str[i] = str[k-1];
        }
        if(ty == 'Q'){
            int l, r, close = 0, open = 0;
            cin >> l >> r;
            l--, r--;
            FOR(temp, l, r){
                if(str[i][temp] == '('){
                    if(open < 0) open = 0;
                    open++;
                }
                else open--;
            }
            if(open < 0) open = 0;
            FORR(temp, r, l){
                if(str[i][temp] == '(') close--;
                else{
                    if(close < 0) close = 0;
                    close++;
                }
            }
            if(close < 0) close = 0;
            cout << open + close << '\n';
        }
    }
}
