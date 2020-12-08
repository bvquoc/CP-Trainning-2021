#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fio(s) freopen(s".inp","r",stdin)
#define foo(s) freopen(s".out","w",stdout)
#define pb push_back
#define task "paint"
using namespace std;
const int N=1000009;
int n,m,b[N];
char a[N];
struct data{
    int t,u,v;
};
void Sub1()
{
    char c,cc;
    int typ;
    vector<int> v[26];
    For(i,1,n){
        scanf("%d",&typ);
        if(typ==1){
                for(c=getchar();c<'a'||c>'z';c=getchar());
                ++m; v[c-'a'].pb(m);
        }else{
            for(c=getchar();c<'a'||c>'z';c=getchar());
            for(cc=getchar();cc<'a'||cc>'z';cc=getchar());
            for(auto x:v[c-'a']) v[cc-'a'].pb(x);
            v[c-'a'].clear();
        }
    }
    For(i,0,25)
        for(auto x:v[i]) a[x]=(char) (i) + 'a';
    For(i,1,m) putchar(a[i]);
}
void Sub2()
{
    vector<data> v;
    vector<int> rs;
    int typ;
    char c,cc;
    For(i,1,n){
        scanf("%d",&typ);
        if(typ==1){
                for(c=getchar();c<'a'||c>'z';c=getchar());
                v.pb((data){1,c-'a',0});
        }else{
            for(c=getchar();c<'a'||c>'z';c=getchar());
            for(cc=getchar();cc<'a'||cc>'z';cc=getchar());
                v.pb((data){2,c-'a',cc-'a'});
        }
    }
    For(i,0,25) b[i]=i;
    if(!v.empty())
    Ford(i,v.size()-1,0){
        if(v[i].t==1)
            rs.pb(b[v[i].u]);
        else{
            b[v[i].u]=b[v[i].v];
        }
    }
    if(!rs.empty())
    Ford(i,rs.size()-1,0)
        putchar(rs[i]+'a');
}
int main()
{
    fio(task); foo(task);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d",&n);
    if(n<=10000)
        Sub1();
    else
        Sub2();
    return 0;
}
