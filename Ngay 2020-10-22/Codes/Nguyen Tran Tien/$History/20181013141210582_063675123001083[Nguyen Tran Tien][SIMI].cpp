#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll BASE = 31;

string s;

int ans = 0;

char tmp[1000001];

/*
void calBase(){
    base[0] = 1;
    FOR(i, 1, 1000001){
        base[i] = (base[i - 1] * BASE) % MOD;
    }
}

void calHash(){
    hashS[0] = 0;
    FOR(i, 2 , s.size() - 1){
        hashS[i] = (hashS[i - 1] * BASE + s[i] - 'a') % MOD;
    }
}
*/
int match(int l){
    int i1 = 1, i2 = s.size() - l;
    while (s[i1] == s[i2] && i1 < s.size() && i2 <= s.size()){
        i1++;
        i2++;
    }
    return i1 - 1;
}
int main(){
    freopen("SIMI.INP", "r", stdin);
    freopen("SIMI.OUT", "w", stdout);

    scanf("%1000000s", tmp);
    s = tmp;
    s = " " + s;

    //calBase();
    //calHash();
    FOR(l, 1, s.size()){
        ans += match(l);
    }
    printf("%d", ans);

    return 0;
}
