#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    int m,n,x=100000, tmp, res=1, a[100001]={0}, check;
    cin>>m;
    int max_tem[m+1]={0}, min_tem[m+1]={0};
    for (int i=1; i<=m; i++){
        cin>>min_tem[i]>>max_tem[i];
        if (a[min_tem[i]]==0) a[min_tem[i]]=max_tem[i];
        else a[min_tem[i]]=max(a[min_tem[i]], max_tem[i]);
    }
    sort(min_tem+1, min_tem+m+1);
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>tmp; x=min(tmp,x);
    }
    tmp=1;
    for (int i=1; i<=m; i++){
        if (min_tem[i]<=x && a[min_tem[i]]>=x){
            if (tmp==1) check=a[min_tem[i]];
            x=max(a[min_tem[i]], a[min_tem[i-1]]);
          }
            else {
                res++; x=a[min_tem[i]];
            }
        }
    if (x==100000) cout<<res; else cout<<-1;
    return 0;
}

