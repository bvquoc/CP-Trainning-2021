#include <bits/stdc++.h>

#define _u(i,a,b) for(int i=(a);i<=(b);++i)
#define _d(i,a,b) for(int i=(a);i>=(b);--i)
#define FIO() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FI(task) freopen(task".inp","r",stdin);
#define FO(task) freopen(task".out","w",stdout);
#define fillchar(a, x) memset(a, x, sizeof(a))
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define endl "\n"

using namespace std;

const int N =2e6+7;
const ll M = 1ll*1e9+7;

void write(){}
template<typename T, typename ...Ts>
void write(const T &first, const Ts &...rest){
    cout << first << ' ';
    write(rest...);
}
template<typename ...Ts>
void writeln(const Ts &... rest){
    write(rest...);
    cout << endl;
}

int readint(){
    int num(0); char c; bool neg(0);
    for(c=getchar();c<'0'||c>'9';c=getchar()) neg|=c=='-';
    for(;c>='0'&&c<='9';c=getchar()) num=num*10+c-48;
    return neg?-num:num;
}

char readchar(){
    char c;
    for(c=getchar();!isalpha(c);c=getchar());
    return c;
}

void print(ll num){if(num>9)print(num/10);putchar(num%10+48);}

struct node{
    int id;
    node(int id) : id(id) {};
    node *Nxt = 0;
};

typedef node *pnode;

struct linklist{
    pnode head = 0, tail = 0;
    void insert(int id){
        if(head == 0){
            head = new node(id);
            tail = head;
            return;
        }
        tail->Nxt = new node(id);
        tail = tail->Nxt;
    }
}a[30];

char res[N];

void merge(int x, int y){
    a[y].tail->Nxt = a[x].head;
    a[y].tail = a[x].tail;
    a[x].head = 0;
}

#define task "paint"

int main(){
    FIO();
    FI(task);
    #ifndef HOHO
        FO(task);
    #endif // HOHO

    int m = readint(); int n = 0;
    while(m--){
        int c = readint();
        if(c == 1){
            ++n;
            int x = readchar() - 'a';
            a[x].insert(n);
        }else{
            int x = readchar() - 'a' , y = readchar() - 'a';
            merge(x, y);
        }
    }
    _u(i,0,25){
        pnode y = a[i].head;
        while(y){
            res[y->id] = (char)(i + 'a');
            y = y->Nxt;
        }
    }
    _u(i,1,n) cout << res[i];
    return 0;
}
