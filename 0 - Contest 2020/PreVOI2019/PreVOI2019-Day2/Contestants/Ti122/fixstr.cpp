#include <bits/stdc++.h>
using namespace std;
#define llint long long
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define X first
#define Y second
#define NAME "fixstr"
inline llint nextInt(){
    register char c=getchar();
    bool neg=0;
    llint ret=0;
    while (c<'0'||'9'<c){
        if (c=='-') neg=1;
        c=getchar();
    }
    while ('0'<=c&&c<='9'){
        ret=ret*10+c-'0';
        c=getchar();
    }
    if (neg) ret=-ret;
    return ret;
}
inline char nextChar(){
    char c=getchar();
    while (c==' '||c=='\n') c=getchar();
    return c;
}
void write(llint x){
    if (x>9) write(x/10);
    putchar(x%10+48);
}
const int oo = 1e9 , maxn = 6006;
typedef pair<int,int> ii;
struct stc{
    char c;
    int be, en;
};
stc st[maxn];
bool a[maxn];
int save[maxn], dem, n;
vector <bool > v[maxn];
string s;


void enter(){
    cin >> s;
       for (int i=0;i<s.length();i++)
        if (s[i]=='(') v[i].push_back(0); else v[i].push_back(1);
    for (int i = 0; i < s.length(); i++) a[i] = v[i][0];
    cin >> n;
    for (int i = 1;i<=n;i++){
        cin >> st[i].c;
        if (st[i].c == 'C') {
            cin >> st[i].be;
            st[i].be--;
        }
        else if (st[i].c == 'Q') {
            cin >> st[i].be;
            cin >> st[i].en;
            st[i].be--;
            st[i].en--;
        } else {
            int k;
            cin >> k;
            st[i].be= k;
            dem++;
            save[k] = dem;
        }
    }
}

void truyvan(int dau, int cuoi){
    int res = 0;
    int chay = 0 ;
    for (int i= dau;i<=cuoi;i++)
    {if (a[i]==0) chay++;
        else {
            if (chay) {chay--;continue;}
            res ++;
        }
    }
    res += chay;
    write(res);
    putchar('\n');
    return ;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    enter();
    dem = 0;
    for (int i = 1; i<= n; i++){
        if (save[i]!=0) {
                dem++;
            for (int j=0;j<s.length();j++) v[j].push_back(a[j]);
        }
        if (st[i].c=='C'){
            int x=  st[i].be;
            a[x]=1-a[x];
        } else
        if (st[i].c == 'Q'){//write(i);putchar(' ');
            truyvan(st[i].be, st[i].en);

        } else
        if (st[i].c == 'U'){
            int x = st[i].be;
            x = save[x];
            for (int j = 0 ; j< s.length(); j++) a[j]=v[j][x];
        }
    }

}

