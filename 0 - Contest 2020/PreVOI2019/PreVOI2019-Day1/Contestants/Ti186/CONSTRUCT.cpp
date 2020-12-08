#include <bits/stdc++.h>

using namespace std;
int res,t,n,m,a[1005],b[1005],l,r,k,id;
void run(int L,int R,int k){
    res+=k;
    for(int i=L;i<=R;i++){
        b[i]-=k;
    }
    int l=L;
    for(int i=L;i<=R+1;i++){
        if(b[i]==0){

            if(b[i-1]!=0) run(l,i-1,*min_element(b+l,b+i));
            l=i+1;
        }
    }
}

void xuli(int l,int r){
    memset(b,0,sizeof(b));
    for(int i=l;i<=r;i++){
        b[i]=a[i];
    }
    res=0;
    run(l,r,*min_element(b+l,b+r+1));
    printf("%d\n",res);
}

int main()
{
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int _=1;_<=m;_++){
            scanf("%d",&id);
            if(id-1){
                scanf("%d%d",&l,&r);
                xuli(l,r);
            } else {
                scanf("%d%d%d",&l,&r,&k);
                for(int i=l;i<=r;i++){
                    a[i]+=k;
                }
            }
        }
    }
}
