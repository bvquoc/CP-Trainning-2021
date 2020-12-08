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
#define Kurumi "construct"
#define nmax 1000005
const ll OO = 1e9+7 ;

using namespace std;
ll d = 0;
int T,n,m;
int a[nmax],b[nmax],h[nmax];
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
void ql(){
    int l = 1;
    int r = n;
    int cnt = 0;
    for(int j = 1; j <= n; j++)
        if(h[j] == b[j]) cnt++;
    if(cnt == n)
        return;
    for(int j = 1; j <= n; j++){
        if(h[j] == b[j]){
            l = j + 1;
        }
        if(h[j + 1] != b[j + 1]) break;
    }
    for(int j = l; j <= n; j++){
        if(h[j] == b[j]){
            r = j - 1;
            break;
        }
    }
    d++;
    for(int j = l; j <= r; j++)
        h[j]++;
    ql();
}
void kurumi(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        for(int i = 1; i <= m; i++){
            reset(h);
            int type,L,R,k;
            cin >> type;
            if(type == 1){
                cin >> L >> R >> k;
                for(int j = L; j <= R; j++)
                    a[j] += k;
            }
            else{
                cin >> L >> R;
                for(int j = 1; j <= n; j++)
                    b[j] = a[j];
                for(int j = 1; j < L; j++){
                    b[j] = 0;
                }
                for(int j = R + 1; j <= n; j++){
                    b[j] = 0;
                }
                d = 0;
                ql();
                cout << d << '\n';
            }
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
