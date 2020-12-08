#include <bits/stdc++.h>
using namespace std;
#define llint long long
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define X first
#define Y second
#define NAME "paint"
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
inline int nextChar(){
    char c=getchar();
    while (c==' '||c=='\n') c=getchar();
    return (int) c;
}
void write(llint x){
    if (x>9) write(x/10);
    putchar(x%10+48);
}
const int oo = 1e9 , maxn = 1e6+5;
typedef pair<int,int> ii;

int cha[maxn], a[maxn], mang[maxn], loai[maxn];
int n, dem;



int father(int x){
    if (cha[x]<0) return x;
    cha[x] = father(cha[x]);
    return cha[x];
}
void noi(int x, int y){
    int t1 = father(x);
    int t2 = father(y);//cout << "cha" << t1 <<" "<<t2<<endl;
    if (t1 == t2) return ;
    if ( cha[t1] > cha[t2] ){
        cha[t2] += cha[t1];
        cha[t1] = t2;
        mang[loai[t2]] = 0;
        mang[loai[t1]] = t2;
        loai[t2] = loai[t1];
        return ;
    }
    cha[t1] += cha[t2];
    cha[t2] = t1;
    mang[loai[t2]] = 0 ;
    loai[t2] = loai[t1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
     n= nextInt();
     for (int i = 1;i <= n; i++){
        int kind = nextInt();
        if ( kind == 1){
            int x = nextChar();//cout <<(char) x <<" "<<endl;
            dem++;
            if (mang[x]==0){
                mang[x] = dem;
                loai[dem] = x;
                cha[dem] = -1;

            } else {
                loai[dem] = x;
                int t = mang[x];
                cha[t]--;
                cha[dem] = t;
            }
        } else {


            int x = nextChar();
            int y = nextChar();// cout <<(char) x<<" "<<(char) y <<endl;
            if (mang[x]==0) continue;
            if (mang[y]==0){

                int t=mang[x];
                mang[x]=0;
                loai[t] = y;
                mang[y]=t;
               // if (i==9) cout <<y;
                continue;
            }
            x = mang[x];//cout << x ;
            y = mang[y];//cout <<" "<<y<<endl;
            noi(y, x);
        }
//        cout <<"/";
//        for (int j =1;j<=dem;j++) cout << father(j)<<" ";
//        cout << endl;

     }
     for (int i =1; i <= dem;i++){
        int t=father(i);
        int kind = loai[t];
        char c = (char) kind;
        putchar(c);
     }

}

