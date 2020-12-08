#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;

int n;
int id[maxn],kq[maxn],a[maxn];

int getroot(int x){
    return !id[x]?x:id[x]=getroot(id[x]);
}
void hop(int x,int y){
    if((x=getroot(x))==(y=getroot(y))) return;
    id[y]=x;
}

main(){
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int type;
        cin>>type;
        if(type==1){
            char ch; cin>>ch;
            kq[++n]=ch-'a';
            if(a[ch-'a']){
                hop(n,a[ch-'a']);
            } else{
                a[ch-'a']=n;
            }
        } else{
            char x,y;
            cin>>x>>y;
            if(!a[x-'a']) continue;
            if(!a[y-'a']){
                a[y-'a']=a[x-'a'];
                kq[getroot(a[x-'a'])]=y-'a';
                if(x!=y) a[x-'a']=0;
            } else{
                hop(a[y-'a'],a[x-'a']);
                if(x!=y) a[x-'a']=0;
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<(char)(kq[getroot(i)]+'a');
}
