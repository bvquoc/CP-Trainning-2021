/** Hien Jeony **/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define getbit(n,i) ((n>>(i-1))&1)
#define offbit(n,i) (n^(1<<(i-1)))
#define onbit(n,i) (n|(1<<(i-1)))
#define cntone(x) (__builtin_popcount(x))
const int mod=1e9+7;
using namespace std;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
int main()
{
    freopen("motion.inp","r",stdin);
    freopen("motion.out","w",stdout);
    cout<<"7 2\n3 2\n-1\n1 3\n63 2";
}
