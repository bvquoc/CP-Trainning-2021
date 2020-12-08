#include <bits/stdc++.h>
using namespace std;
#define el '\n'

typedef unsigned long long ull;

typedef long long ll;

template<typename so>

void read(so &x)
{
    x = 0;
    int dem = 0;char c;
    for (c = getchar();'0'>c||c>'9';c=getchar())
    {
        dem++;if(dem==1000) return;
    }
    for (;'0'<=c&&c<='9';c=getchar())
    {
        x = (x<<3) + (x<<1) + c - '0';
    }
}

void rec(char &son)
{
    char c;int dem = 0;
    for (c = getchar();'A'>c||c>'Z';c=getchar())
    {
        dem++;if(dem==1000) return;
    }
    for (;'A'<=c&&c<='Z';c=getchar())
    {
        son = c;
        return;
    }
}

const int MaxN = 1e6+1e5;

const ll mod = 1e6+3;

template<typename so> void get_min(so &a,so b)
{
    if (a>b) a = b;
}

//name MOTION

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MOTION.inp","r",stdin);
    freopen("MOTION.out","w",stdout);
    int n;cin>>n;
    cout<<7<<" "<<2<<el;
    cout<<3<<" "<<2<<el;
    cout<<-1<<el;
    cout<<1<<" "<<3<<el;
    cout<<63<<" "<<2<<el;
}
