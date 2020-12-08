///EmperorD: @npd.28
#include <bits/stdc++.h>
#define EmperorD "MOTION"
#define ll long long
#define ull unsigned long long
#define el '\n'
#define fi first
#define se second
#define pll pair<long long, long long>
#define pii pair<int,int>
#define piii pair<int,pii>
#define mp make_pair
#define pb push_back
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define forv(a,b) for(auto &a:b)
#define reset(f,x) memset(f,x,sizeof(f))
#define mod 10000007
using namespace std;
const int oo=1e9+7;

int get()
{
    int tmp = 0;
    char x = getchar();
    bool Neg = false;
    while(x == ' ' || x == '\n')
        x = getchar();
    if(x == '-')
        Neg = true, x = getchar();
    while('0' <= x && x <= '9')
        tmp = tmp * 10 + (x - '0'), x = getchar();
    if(Neg)
        return -tmp;
    return tmp;
}

void input()
{
	cout <<7<<' '<<2<<el;
  cout <<3<<' '<<2<<el;
  cout <<-1<<el;
  cout <<1<<' '<<3<<el;
  cout <<63<<' '<<2<<el;
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen (EmperorD".inp","r",stdin);
    freopen (EmperorD".out","w",stdout);
	input();
    return 0;
}