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

char s[maxN];
int cnt = 0;
int n;
int bit;
char x,y;
stack<int> S[30];


int dd[maxN];
vector<int> Index[30];
int res[maxN];
int Value[maxN];
int CHAR[maxN];


void sub1(){
    while(n--){
        cin >> bit;
        if(bit == 1){
            cin >> x;
            s[++cnt] = x;
        }
        else {
            cin >> x >> y;
            if(x == y) continue;
            foru(i,1,cnt)
                if(s[i] == x)
                    s[i] = y;
        }
    }
    foru(i,1,cnt)
        cout << s[i];
}

void sub2(){
    while(n--){
        cin >> bit;
        if(bit == 1){
            cin >> x;
            s[++cnt] = x;
            S[x-96].push(cnt);
        }
        else{
            cin >> x >> y;
            if(x == y) continue;
            while(!S[x-96].empty()){
                int k = S[x-96].top();
                s[k] = y;
                S[y-96].push(k);
                S[x-96].pop();
            }
        }
    }
    foru(i,1,cnt)
        cout << s[i];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    #define name "paint."
    freopen(name"inp","r",stdin);
    freopen(name"out","w",stdout);
    #endif

    cin >> n;

    sub2();

    return 0;
}
















