#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define nmax 100005
#define MOD 1000000007
#define pii pair<long long, long long>
#define ll long long
#define Task "PAINT"
#define sqr(x) (x) * (x)
#define For(i,x,y) for(int i=x; i <= y ; i++)
#define oo
using namespace std;
int n , t ,k=1;
char a , b;
bool avail[nmax] ={0};
char pained[nmax] , kq[nmax];
map<char , queue<int> > mp;
map<char , int> m;
void paint(char s)
{
    For(i , 1 , k + 1){
        if(avail[i] == 0){
            kq[i] = s;
            avail[i]=1;
            k++;
            return ;
    }
   }
}
void change(char c , char d)
{
    For(i , 1 , k)
        if(kq[i] == c )
            kq[i] = d;
}
void enter()
{
    cin >> n;
    For(i , 1 , n){
        cin >> t;
        if(t == 1){
            cin >> a;
            paint(a);
        }
        if(t == 2){
            cin >> a >> b ;
            if(a!=b)
            change(a , b);
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    enter();
    For( i , 1 , k)
        cout << kq[i] ;
    //cout <<endl<< "cddcdcad";
    }
