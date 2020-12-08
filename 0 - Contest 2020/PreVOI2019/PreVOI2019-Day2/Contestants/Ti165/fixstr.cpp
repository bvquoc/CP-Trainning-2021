#include<bits/stdc++.h>

#define foru(i,d,c) for(int i=d;i<=c;++i)
#define ford(i,c,d) for(int i=c;i>=d;--i)
#define fi first
#define se second
#define ii pair<int,int>
#define pb push_back
void Read(int &res) {
    res=0; bool am=false;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-') c = getchar();
    if (c=='-') {am = true;c = getchar();}
    while(c>='0' && c<='9'){res = res * 10 + c - 48;c = getchar();}
    if(am) res = -res;
}
typedef long long ll;
const int oo = 1e9 + 5;
const ll mod = 1e9 + 7;
const int maxN = 1000005;
using namespace std;

int n,m;
string s;
string S[maxN];

int calc(int i, int j){
    int res = 0;
    int dong = 0, mo = 0;
    int dongthua = 0;
    foru(k,i,j){
        if(s[k] == '(') ++mo;
        else ++dong;
        if(dong > mo) {
            ++res;
            ++mo;
        }
    }
    res += mo - dong;

    return res;
}


void sub1(){
    char bit;
    int i,j,k;

    foru(z,1,m){
        S[z] = s;
        cin >> bit;
        if(bit == 'C'){
            cin >> i;
            bool kt;
            if(s[i] == '(') kt = true;
            else kt = false;
            if(kt) s[i] = ')';
            else s[i] = '(';
        }
        if(bit == 'Q'){
            cin >> i >> j;
            cout << calc(i,j) <<"\n";
        }
        if(bit == 'U'){
            cin >> k;
            s = S[k];
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    #define name "fixstr."
    freopen(name"inp","r",stdin);
    freopen(name"out","w",stdout);
    #endif

    cin >> s;
    int n = s.length();
    s = ' ' + s;
    cin >> m;


    if(n <= 1000 && m <= 1000)
        sub1();

    return 0;
}
















