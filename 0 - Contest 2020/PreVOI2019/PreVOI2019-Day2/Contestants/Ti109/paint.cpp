#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define ft(i,x,y) for(int i=y;i>=x;i--)
#define ll long long
#define add push_back
#define ad push
#define fi first
#define se second
#define fast_read ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef struct pair<ll,ll> ii;
int n,tv,dem;
char s[5],a[5],b[5];
string color[1000010];
void io(){
    freopen("paint.inp" , "r" , stdin);
    freopen("paint.out" , "w" , stdout);
}
void inp(){
    scanf("%d",&n);
}
void sub(){
    fr(i,1,n){
        scanf("%d",&tv);
        if(tv==1){
            scanf("%s",&s);
            color[++dem]=s;
        }
        else{
            scanf("%s%s",&a,&b);
            fr(i,1,dem){
                if(color[i]==a) color[i]=b;
            }
        }
    }
    fr(i,1,dem) cout<<color[i];
}
int main (){
    io();
    inp();
    sub();
    return 0;
}

